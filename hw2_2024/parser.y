%{
#include<stdio.h>
#include<string.h>
%}

%union{
    int token;
    double token_float;
    char* charv;
    char* op;
    char* identifier;
    struct symbol *sym;
}

%token<token> ID NUM DATA_TYPE 
%token<token> '+' '-' '*' '/' '=' '%' '<' '>' '=' '&' '!' '|' ',' ';'
%token<token> '++' '--' '<=' '>=' '==' '!=' '&&' '||'  
%type<token> scalar_decl array_decl func_decl func_def expr stmt ident variable

%%

stmt: ID '=' expr
    | expr          { printf("====%d", $1); }
    ;

expr: expr '+' NUM  { $$ = $1 + $3; }
    | expr '-' NUM  { $$ = $1 - $3; }
    | NUM           { $$ = $1; }
    ;

%%

int yylex(void);

int main(void) {
    yyparse();
    return 0;
}

int yyerror(char *s){
    fprintf(stderr, "%s\n", s);
    return 0;
}

/*
scalar_decl:= DATA_TYPE ident    { strcat($$,$1); strcat($$,$2); printf("%s", $$); }
        ;

ident:= variable ',' ident     { printf("%s%s %s", $1, $2, $3); }
        | variable ';'         { printf("%s %s", $1, $2); }
        ;

variable:= '*'ID '=' expr
        | '*'ID 
        | ID '=' expr
        | ID
        ;


<LINE>"\+\+"	{   return '++'; }
<LINE>"\-\-"	{   return '--'; }
<LINE>"<="		{   return '<='; }
<LINE>">="		{   return '>='; }
<LINE>"=="		{   return '=='; }
<LINE>"!="		{   return '!='; }
<LINE>"&&"		{   return '&&'; }
<LINE>"||"		{   return '||'; }
*/