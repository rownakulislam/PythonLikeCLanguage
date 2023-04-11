#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_digit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0;
}

int check_int(char *c){
    int i;
    for(i=0;i<strlen(c);i++){
        if(check_digit(c[i])==0){
            return 0;
        }
    }
    return 1;
}

int check_real(char *c){
    int f=0;
    int i;
    for(i=0;i<strlen(c);i++){
        if(c[i]=='.'){
            f=1;
            continue;
        }
        if(check_digit(c[i])==0){
            return 0;
        }
    }
    if(f==1){
        return 1;
    }
    else{
        return 0;
    }
}


struct identifier_data
{
    int type;
    char *varname;
    int valtype;
    char *strval;
    int intval;
    double realval;
};

void print(struct identifier_data data, int i) {
    if ((data).valtype == 2) {
        printf("name :: %s value :: %d\n", (data).varname,(data).intval);
    } else if ((data).valtype == 3) {
        printf("name :: %s value :: %lf\n", (data).varname, (data).realval);
    } else if ((data).valtype == 4) {
        printf("name :: %s value :: %s\n", (data).varname, (data).strval);
    } else if (data.valtype == 1) {
        printf("Function name :: %s return type :: %s\n", data.varname,data.strval);
    }
    else if(data.valtype == 5){
        printf("Array name :: %s Dimension :: %d\n", data.varname, data.intval);
    }
    else if(data.valtype == 6){
        printf("Class name :: %s \n",data.varname);
    }
}

struct identifier_data constructor(int type,char *varname,char *val){
    struct identifier_data data;
    data.type=type;
    data.varname=(char *)malloc((strlen(varname)+1)*sizeof(char));
    strcpy(data.varname,varname);
    //func
    if(type==1){
        data.valtype=1;
        data.strval=val;
        data.intval=atoi("sajndjkansj");
        printf("%d\n",data.intval);
    }
        //array
    else if(type==5){
        data.valtype=5;
        data.intval=atoi(val+1);
    }
        //class
    else if(type==6){
        data.valtype=6;
        data.intval=atoi(val);
    }
    else{
        if(check_int(val)){
            data.valtype=2;
            data.intval=atoi(val);
        }
        else if(check_real(val)){
            data.valtype=3;
            data.realval=atof(val);
        }
        else{
            data.valtype=4;
            data.strval=(char *)malloc((strlen(val)+1)*sizeof(char));
            strcpy(data.strval,val);
        }
    }
    return data;
};



// void fprint(struct identifier_data data,FILE* fp) {
//     if ((data).valtype == 2) {
//         fprintf(fp,"name :: %s value :: %d\n", (data).varname,(data).intval);
//     } else if ((data).valtype == 3) {
//         fprintf(fp,"name :: %s value :: %f\n", (data).varname, (data).intval);
//     } else if ((data).valtype == 4) {
//         fprintf(fp,"name :: %s value :: %s\n", (data).varname, (data).intval);
//     } else if (data.valtype == 1) {
//         fprintf(fp,"Function name :: %s return type :: %s\n", data.varname,data.strval);
//     }
//     else if(data.valtype == 5){
//         fprintf(fp,"Array name :: %s Dimension :: %d\n", data.varname, data.intval);
//     }
//     else if(data.valtype == 6){
//         fprintf(fp,"Class name :: %s \n",data.varname);
//     }
// }

struct identifier
{
    struct identifier_data data;
    struct identifier *next;

};

struct identifier *findClassName(struct identifier **root, int id) {
    struct identifier *now = *root, *ans = NULL;
    while (now != NULL) {
        if (now->data.type == 6 && now->data.intval == id) {
            ans = now;
            break;
        }
        now = now->next;
    }
    return ans;
}

char *gettypename(int id, struct identifier **root) {
    if (id == 0) return "VOID";
    if (id == 1) return "INT";
    if (id == 2) return "DOUBLE";
    if (id == 3)
        return "STRING";
    else {
        struct identifier *res = findClassName(root, id);
        if (res == NULL) {
            printf("Error :: Class not found\n");
            exit(-1);
        }
        return res->data.varname;
    }
}

void push_back(struct identifier **root, struct identifier **last, struct identifier_data newdata) {
    if(newdata.type == 1){
        newdata.strval = strdup(gettypename(newdata.intval,root));
    }
    struct identifier *new_node = (struct identifier *)malloc(sizeof(struct identifier));
    new_node->data = newdata;
    new_node->next = NULL;
    if (*root == NULL) {
        *root = new_node;
    } else {
        (*last)->next = new_node;
    }
    *(last) = new_node;
    return;
}

struct identifier *isDeclared(struct identifier **root, char *varname) {
    struct identifier *now = *root, *ans = NULL;
    while (now != NULL) {
        if (strcmp(now->data.varname, varname) == 0) {
            ans = now;
            break;
        }
        now = now->next;
    }
    return ans;
}

int addNewVal(struct identifier **root, struct identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 1;
    if (check_int(val))
        type = 2;
    else if (check_real(val))
        type = 3;
    else if(val[0]=='`')
        type = 5;
    else if (strlen(val) > 0)
        type = 4;
    struct identifier_data tmp = constructor(type, str, val);
    push_back(root, last, tmp);
    return 1;
}

struct identifier *getVal(struct identifier **root, char *str) {
    return isDeclared(root, str);
}

void setVal(struct identifier **root, struct identifier **last, char *str, char *val) {
    struct identifier *idx = isDeclared(root, str);
    if (idx == NULL) {
        addNewVal(root, last, str, val);
    }
    else if(idx->data.type == 1 || idx->data.type == 6){
        printf("Error :: You can't set a value to class/function");
        exit(-1);
    }
    else {
        int type = 1;
        if (check_int(val))
            type = 2;
        else if (check_real(val))
            type = 3;
        else if (val[0] == '`')
            type = 5;
        else if (strlen(val) > 0)
            type = 4;
        idx->data = constructor(type, str, val);
    }
}

int addNewFunc(struct identifier **root, struct identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 1;
    struct identifier_data tmp = constructor(type, str, val);
    push_back(root, last, tmp);
    return 1;
}
int addNewClass(struct identifier **root, struct identifier **last, char *str, char *val) {
    if (isDeclared(root, str) != NULL)
        return 0;
    int type = 6;
    struct identifier_data tmp = constructor(type, str, val);
    push_back(root, last, tmp);
    return 1;
}

void print_all(struct identifier *now) {
    if (now == NULL)
        return;
    print(now->data, 0);
    print_all(now->next);
}


//void fprint_all(struct identifier *now,FILE* fp) {
//    if (now == NULL)
//        return;
//    fprint(now->data,fp);
//    fprint_all(now->next,fp);
//}
#define HIGH 1e5
#ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif

int max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

void print_datatype(struct datatype tmp){
    printf("type :%d\n",tmp.type);
    if(tmp.type==2){
        printf("%d\n", tmp.intval);
    }
    else if (tmp.type==3){
        printf("%lf\n",tmp.realval);
    }
    else if(tmp.type==4){
        printf("%s\n",tmp.strval);
    }
}

//void fprint_datatype(struct datatype tmp,FILE *x){
//    if(tmp.type==2){
//        fprintf(x,"%d\n", tmp.intval);
//    }
//    else if (tmp.type==3){
//        fprintf(x,"%lf\n",tmp.realval);
//    }
//    else if(tmp.type==4){
//        fprintf(x,"%s\n",tmp.strval);
//    }
//}

struct datatype make_datatype_int(int val){
    struct datatype tmp;
    tmp.type=2;
    tmp.intval=val;
    return tmp;
}

struct datatype make_datatype_double(double val){
    struct datatype tmp;
    tmp.type=3;
    tmp.realval=val;
    return tmp;
}

struct datatype make_datatype_char(char *val){
    struct datatype tmp;
    tmp.type=4;
    tmp.strval= calloc(strlen(val)+1,sizeof(char));
    strcpy(tmp.strval,val);
    return tmp;
}

void convert_to_str(struct datatype *a){
    if(a->type==2){
        a->type=4;
        int n= (int)log10(a->intval)+1;
        a->strval= calloc(n+1,sizeof(char));
        snprintf(a->strval,n+1,"%ld",a->intval);
    }
    else if(a->type==3){
        a->type=4;
        int n= 50;
        a->strval= calloc(n+1,sizeof(char));
        snprintf(a->strval,n,"%lf",a->intval);
    }
}

void convert_to_double(struct datatype *a){
    if(a->type==2){
        a->type=3;
        a->realval=a->intval*1.0;
    }
}

void makesame(struct datatype *a,struct datatype *b){
    if(a->type==b->type){
        return;
    }
    else if (a->type==4 || b->type==4){
        convert_to_str(a);
        convert_to_str(b);
    }
    else if(a->type==3 || b->type==3){
        convert_to_double(a);
        convert_to_double(b);
    }

}

struct datatype prepare_for_evaluate(struct datatype *a,struct datatype *b){
    makesame(a,b);
    struct datatype temp;
    if(temp.type==2){
        temp= make_datatype_int(a->intval);
    }
    if(a->type==3){
        temp= make_datatype_double(a->realval);
    }
    if(a->type==4){
        temp= make_datatype_char(a->strval);
    }
    return temp;
}

struct datatype evaluate(struct datatype a,struct datatype b,char *sign) {
    struct datatype tmp;
    int type = max(a.type, b.type);
    print_datatype(a);
    print_datatype(b);
    if (strcmp(sign, "+") == 0) {
        tmp = prepare_for_evaluate(&a, &b);
        // print_datatype(a);
        // print_datatype(b);
        if (type == 2) {
            tmp.intval = a.intval + b.intval;
        } else if (type == 3) {
            tmp.realval = a.realval + b.realval;
        } else if (type == 4) {
            realloc(tmp.strval, (strlen(a.strval) + strlen(b.strval) + 1) * sizeof(char));
            strcat(tmp.strval, b.strval);
        }
        print_datatype(tmp);
    }
    else if (strcmp(sign, "*") == 0) {
        int str_len;
        if((a.type==2 && b.type==4) || (a.type==4 && b.type==2)){
            str_len=max(a.intval,b.intval);
        }
        tmp = prepare_for_evaluate(&a, &b);
        if (type == 2) {
            tmp.intval = a.intval * b.intval;
        } else if (type == 3) {
            tmp.realval = a.realval * b.realval;
        } else if (type == 4 && (a.type==4 && b.type==4)) {
            realloc(tmp.strval, (strlen(a.strval)+1)*strlen(b.strval)* sizeof(char));
            int i;
            for (i = 0; i < b.intval-1; i++) {
                strcat(tmp.strval, a.strval);
            }
//            strcat(tmp.strval, b.strval);
        }
    }
    else if(strcmp(sign,"/")==0){
        tmp = prepare_for_evaluate(&a, &b);
        if(a.type==2){
            if(b.intval==0){
                printf("Division by zero error\n");
                exit(-1);
            }
            tmp.intval=a.intval/b.intval;
        }
        else if(a.type==3){
            if(b.realval==0.0){
                printf("Division by zero error\n");
                exit(-1);
            }
            tmp.realval=a.realval/b.realval;
        }
    }
    else if (strcmp(sign,"-")==0){
        tmp = prepare_for_evaluate(&a, &b);
        if(a.type==2){
            tmp.intval=a.intval-b.intval;
        } else if(a.type==3){
            tmp.realval=a.realval-b.realval;
        }
        else{
            printf("compilation error in minus\n");
            exit(-1);
        }
    }
    else if(strcmp(sign,"<")==0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?a.intval<b.intval:a.realval<b.realval);
        }else{
            tmp.intval=strcmp(a.strval,b.strval)<0;
        }
    }
    else if(strcmp(sign,"<=")==0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?(a.intval<=b.intval):(a.realval<=b.realval));
        }else{
            tmp.intval=strcmp(a.strval,b.strval)<=0;
        }
    }
    else if(strcmp(sign,">")==0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?(a.intval>b.intval):(a.realval>b.realval));
        }else{
            tmp.intval=strcmp(a.strval,b.strval)>0;
        }
    }
    else if(strcmp(sign,">=")==0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?a.intval>=b.intval:a.realval>=b.realval);
        }else{
            tmp.intval=strcmp(a.strval,b.strval)>=0;
        }
    }
    else if(strcmp(sign,"==")==0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?a.intval==b.intval:a.realval==b.realval);
        }else{
            tmp.intval=strcmp(a.strval,b.strval)==0;
        }
    }
    else if(strcmp(sign,"<")!=0){
        prepare_for_evaluate(&a, &b);
        tmp.type=2;
        if(a.type==2 || a.type==3){
            tmp.intval=(a.type==2?a.intval!=b.intval:a.realval!=b.realval);
        }else{
            tmp.intval=strcmp(a.strval,b.strval)!=0;
        }
    }
    else if(strcmp(sign,"%")==0){
        if(type==2){
            tmp= prepare_for_evaluate(&a,&b);
            tmp.intval=a.intval%b.intval;
        }
        else{
            printf("compilation error in mod\n");
        }
    }

    else if(strcmp(sign,"^")==0){
        if(type==2){
            tmp= prepare_for_evaluate(&a,&b);
            tmp.intval=a.intval^b.intval;
        }
        else{
            printf("compilation error in XOR\n");
        }
    }
    else if(strcmp(sign,"&")==0){
        if(type==2){
            tmp= prepare_for_evaluate(&a,&b);
            tmp.intval=a.intval&b.intval;
        }
        else{
            printf("compilation error in AND\n");
        }
    }
    else if(strcmp(sign,"|")==0){
        if(type==2){
            tmp= prepare_for_evaluate(&a,&b);
            tmp.intval=a.intval%b.intval;
        }
        else{
            printf("compilation error in mod\n");
        }
    }
    return tmp;
}

int boolvalue(struct datatype x){
    if(x.type==2){
        return x.intval!=0;
    }
    else if(x.type==3){
        return x.realval!=0;
    }
    else if(x.type==4){
        return strlen(x.strval)>0;
    }
    return 0;
}

int _intvalue(struct datatype z){
    if(z.type==2){
        return z.intval;
    }
    else if(z.type==3){
        return (int)z.realval;
    }
    return 0;
}

// int main(){
//     struct identifier *root, *last;
//     root = NULL, last = NULL;
//     addNewVal(&root, &last, "abc", "12");
//     addNewVal(&root,&last,"x","lala");
//     addNewVal(&root, &last, "abcx", "12.1");
//     addNewFunc(&root, &last, "des", "int");
//     print_all(root);
//     struct datatype z= make_datatype_int(5);
//     print_datatype(z);
//     struct datatype z1= make_datatype_int(2);
//     print_datatype(z1);
//     struct datatype ans;
//     ans=evaluate(z,z1,"%");
//     print_datatype(ans);
// }