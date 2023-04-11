%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>
    #include<conio.h>
    #include "identifier_data.c"
    void yyerror(char *);
    int yylex(void);
    int typenow=-1;
    struct datatype casedata;
    int caseflag;
    int ifdone[1000];
    int ifptr;
    struct identifier *root=NULL,*last=NULL;
    int sym[26];
%}
%code requires {
    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif
}
%union {
    char text[1009];
    struct datatype val;
}

%start program
%token<text>VARIABLE
%token<text>VARACCESS
%token<val>NUM
%token<val>STR
%token LE_OP GE_OP EQ_OP NE_OP ALLOCATE
%token SIN ASIN COS ACOS TAN ATAN POW LOG LOG10 RETURN INC DEC ADD SUB 
%token IF ELSE_IF ELSE FOR WHILE
%token INT REAL DESCRIBE CLASS FUNC STRING VOID OPTIONS OPTION DEFAULT PRINT IMPORT
%type<val>expression
%left ALLOCATE
%left ADD '-'
%left '*' '/'
%left INC DEC

%%
program         : {
                    printf("compilation successful\n");
                }
                | function program
                | class program
                | declaration program
                | import program
                | statement
                ;

class           :   CLASS VARIABLE '{' statement '}' {  int temp=addNewClass(&root,&last,$2,"");
                                                        if(!temp)
                                                        {
                                                            printf("Error: %s is already declared.\n",$2);
                                                            exit(-1);
                                                        }   
                                                        else{
                                                            printf("class declared\n");
                                                        }                     

                                                      }
                    ;
function        :   type FUNC VARIABLE '(' func_para ')' {
                        char *val;
                        int n=log10(typenow)+1;
                        val=calloc(n+1,sizeof(char));
                        snprintf(val,n,"%ld",typenow);
                        int res=addNewFunc(&root,&last,$3,val);
                        if(!res){
                            printf("Compilation error: %s already declared\n",$3);
                        }
                        else{
                            printf("function declared: %s\n",$3);
                        }
                    } '{' statement '}'
                    ;
type           :   INT {typenow=1;}
                |   REAL {typenow=2;}
                |   STRING {typenow=3;}
                |   VOID {typenow=4;}
                |   VARIABLE {
                    struct identifier* temp=getVal(&root,$1);
                    if(temp==NULL || temp->data.type!=6){
                        printf("error: class can't be defined\n");
                        exit(-1);
                    }
                    typenow=temp->data.intval;
                }
                ;
func_para       :   
                    |   type VARIABLE func_paras
func_paras      :   | ',' type VARIABLE func_paras 
                    | ',' type VARIABLE
                    ;
statement       :   
                    | if statement
                    | declaration statement
                    | for statement
                    | assign statement
                    | while statement
                    | mathexpr statement
                    | return statement
                    | print statement
                    | switch statement
                    ;
switch          :   OPTIONS '(' expression ')' {
                        casedata = $3;
                        printf("\n\nSwitch case \n");
                        print_datatype(casedata);
                    } '{' casegrammer '}'
                    ;
casegrammer     : OPTION  expression ':'  statement  {
                    if(caseflag == 0 && evaluate($2,casedata,"==").intval == 1){
                        caseflag = 1;
                        printf("Case executed :: ");
                        print_datatype($2);
                    }
                } casegrammer
                | DEFAULT ':' statement  {
                    if(caseflag == 0){
                        printf("Defualt executed\n");
                    }
                }
                | 
mathexpr        : expression {
                    printf("value of the expression: ");
                    print_datatype($1);
                }
                ;
if              : IF '(' expression ')' '{' statement '}' {
                        ifptr++;
                        if(boolvalue($3)){
                            printf("\n\nif executed\n");
                            ifdone[ifptr]=1;
                        }
                    } elsifgrmr {
                        ifptr--;
                    }
                    ;
elsifgrmr   :
            | ELSE_IF '(' expression ')' '{' statement '}' {
                if(ifdone[ifptr]==0 && boolvalue($3)){
                    ifdone[ifptr]=1;
                    printf("ELSE IF executed\n");
                }
            } elsifgrmr
            | ELSE '{' statement '}' {
                if(ifdone[ifptr]==0){
                    printf("ELSE executed\n\n");
                }
            }
            ;
expression      : NUM {$$=$1;print_datatype($1);}
                | STR {
                    
                    print_datatype($1);
                    $$ = $1; 
                }
                | VARACCESS {
                    struct identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if(res->data.type==2)
                        $$ = make_datatype_int(res->data.intval);
                    else if(res->data.type==3)
                        $$ = make_datatype_double(res->data.realval);
                    else if(res->data.type==4){
                        $$ = make_datatype_char(res->data.strval);
                    }
                    print_datatype($$);
                }
                }
                | SIN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",sin(val));
            }
            | ASIN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",asin(val));
            }
            | ACOS '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",acos(val));
            }
            | COS '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",cos(val));
            }
            | LOG '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",log(val));
            }
            | LOG10 '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",log10(val));
            }
            | POW '(' expression ',' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    if($5.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    double p = $5.type==2?$5.intval:$5.realval;
                    printf("Value of the expression :: %f\n",pow(val,p));
            }
            | TAN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",tan(val));
            }
            | ATAN '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.realval;
                    printf("Value of the expression :: %f\n",atan(val));
            }
            | expression ADD expression { 
                $$ = evaluate($1,$3,"+");
            }
            | expression '-' expression { 
                $$ = evaluate($1,$3,"-");
            }
            | expression '/' expression { 
                $$ = evaluate($1,$3,"/");
            }
            | expression '*' expression { 
                $$ = evaluate($1,$3,"*");
            }
             | expression LE_OP expression { 
                $$ = evaluate($1,$3,"<=");
            }
            | expression GE_OP expression { 
                $$ = evaluate($1,$3,">=");
            }
            | expression '<<' expression { 
                $$ = evaluate($1,$3,"<");
            }
            | expression '>>' expression { 
                $$ = evaluate($1,$3,">");
            }
            | expression EQ_OP expression { 
                $$ = evaluate($1,$3,"==");
            }
            | expression NE_OP expression { 
                $$ = evaluate($1,$3,"!=");
            }
            | '(' expression ')' { 
                $$ = $2;
            }
            ;
return      : RETURN mathexpr {
                printf("return occured\n");
            }
            | RETURN {
                printf("void return\n");
            }
            ;
declaration : type vars 
            ;

vars        : varr ',' vars 
            | varr
            ;

varr        : VARIABLE ALLOCATE expression {
                char *val;
                if ($3.type == 2) {
                    $3.type = 4;
                    int n = log10($3.intval) + 1;
                    val = calloc(n + 1, sizeof(char));
                    snprintf(val, n + 1, "%ld", $3.intval);
                }
                else if ($3.type == 3) {
                    $3.type = 4;
                    printf("%lf",$3.realval);
                    val = calloc(51, sizeof(char));
                    snprintf(val, 50, "%lf", $3.realval);
                }
                else{
                    val = $3.strval;
                }
                int res = addNewVal(&root,&last,$1,val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
                else{
                    printf("varriable declared : %s\n",$1);
                }
            }
            | VARIABLE {
                int temp = addNewVal(&root,&last,$1,"");
                if(!temp)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
            }
            ;

assign          : varassign ',' assign
                | varassign 
                ;

for             : FOR '(' declaration ':' expression ':' varassign ')' '{' statement '}' {
                    printf("\n\nfor loop\n\n");

                }
                ;

varassign       : VARACCESS ALLOCATE expression {
                struct identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if($3.type == 2){
                        int n = log10($3.intval) + 1;
                        char *num = calloc(n, sizeof(char));
                        sprintf(num,"%ld",$3.intval);
                        setVal(&root,&last,$1,num);
                        printf("Value assigned :: %s = %d\n",$1,$3.intval);
                    }
                    else if($3.type == 3){
                        char *num = calloc(51,sizeof(char));
                        snprintf(num,50,"%lf",$3.realval);
                        setVal(&root,&last,$1,num);
                        printf("Value assigned :: %s = %f\n",$1,$3.realval);
                    }
                    else{
                        setVal(&root,&last,$1,$3.strval);
                        printf("Value assigned :: %s = %s\n",$1,$3.strval);
                    }
                }
            }
            | VARACCESS INC {
                struct identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.realval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        printf("Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.realval);
                        setVal(&root,&last,$1,numberArray);
                        printf("Value assigned :: %s = %f\n",$1,tmp2.realval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        printf("Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS DEC {
                struct identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.realval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.realval);
                        setVal(&root,&last,$1,numberArray);
                        printf("Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.realval);
                        setVal(&root,&last,$1,numberArray);
                        printf("Value assigned :: %s = %f\n",$1,tmp2.realval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        printf("Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            ;

while           : WHILE '(' expression ')' '{' statement '}' {
                    printf("\n\nwhile loop\n");
                    print_datatype($3);
                }
                ;

print           : PRINT '(' {
                    printf("PRINT : ")
                } mul_exp ')'
                ;

mul_exp         : expression {
                    print_datatype($1);
                } ',' mul_exp
                | expression {
                    print_datatype($1);
                }

import          : IMPORT VARIABLE{
                    printf("importing files %s\n",$2);
                } 
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    yyparse();
}
