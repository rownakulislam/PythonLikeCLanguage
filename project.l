%{
    #include <stdio.h>
    #include <conio.h>
    #include <string.h>
    #include "project.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
%}

variable [a-zA-Z][a-zA-Z0-9]*
digit [0-9]
operator "="|"+"|"-"|"/"|"*"|"&"|"|"|"%"|":"


%%
"import" {
    printf("importing files\n");
    return IMPORT;
}
"show" {
    printf("print\n");
    return PRINT;
}
"since" {
    printf("for looop\n");
    return FOR;
}
"as long as" {
    return WHILE;
}
"retrive" {
    printf("return\n");
    return RETURN;
}
"asin" {
    return ASIN;
}
"sin" {
    return SIN;
}
"cos" {
    return COS;
}
"acos" {
    return ACOS;
}
"tan" {
    return TAN;
}
"atan" {
    return ATAN;
}
"log10" {
    return LOG10;
}
"log" {
    return LOG;
}
"pow" {
    return POW;
}
"whenever" {

    return IF;
}
"otherwise whenever" {

    return ELSE_IF;
}
"otherwise" {

    return ELSE;
}
"class" {
    printf("class\n");
    return CLASS;
}
"func" {
    return FUNC;
}
"options" {
    printf("switch\n");
    return OPTIONS;
}
"option" {
    printf("option\n");
    return OPTION;
}
"default" {
    printf("default\n");
    return DEFAULT;
}
"describe" {
    printf("Describe: \n");
    return DESCRIBE;
}
"num4" {
    printf("Int: \n");
    return INT;
}
"dec4" {
    printf("Real: \n");
    return REAL;
}
"str" {
    printf("String\n");
    return STRING;
}
"empty" {
    printf("Void type\n");
    return VOID;
}
"add" {
    printf("add\n");
    return ADD; 
}
"add1" {
    printf("increment\n");
    return INC;
}
"reduce1" {
    printf("decrement\n");
    return DEC;
}
"reduce" {
    printf("minus\n");
    return('-'); 
}
"into" {
    printf("into\n");
    return('*'); 
}
"div" {
    printf("div\n");
    return('/'); 
}

"<<"		{
    return('<'); }
">>"		{
    return('>'); }
"<<="			{ 
    return(LE_OP); }
">>="			{ 
    return(GE_OP); }
"==="			{ 
    return(EQ_OP); }
"~"			{ 
    return(NE_OP); }
"{"		{ 
    return('{'); }
"}"		{
    return('}'); }
","			{ 
    return(','); }
":"			{ 
    return(':'); }
"=="			{ 
    return ALLOCATE; }
"("			{ 
     return('('); }
")"			{ 
     return(')'); }
{digit}+[.]{digit}+ {
    printf("float value\n");
    yylval.val.realval=atof(yytext);
    yylval.val.type=3;
    return NUM;
}
{digit}+ {
    printf("Int value\n");
    yylval.val.intval=atoi(yytext);
    yylval.val.type=2;
    return NUM;
}
"$"{variable} {
    printf("variable access\n");
    strcpy(yylval.text,yytext+1);
    return VARACCESS;
}
{variable} {
    printf("Variable\n");
    strcpy(yylval.text,yytext);
    return VARIABLE;
}
"\""(.)*"\"" {
    yylval.val.type = 4;
    yylval.val.strval = calloc(strlen(yytext),sizeof(char));
    strcpy(yylval.val.strval,yytext+1);
    yylval.val.strval[strlen(yylval.val.strval)-1]=0;
    return STR;
}
[ ]*	    			{}
[\n]*					{}
[\t]*					{}
. {

}

%%

int yywrap(void) {
    return 1;
}
