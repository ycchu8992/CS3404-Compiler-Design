%{
#include<stdio.h>
#include<string.h>

char dest[295], src[295]; 
%}

%union{
    int token;
    double token_float;
    char* charv;
    char punc_symbol;
    char* op;
    char* data_type;
    char* identifier;
    char* expression;
    struct symbol *sym;
}

%token<token> NUM 
%token<identifier> ID
%token<data_type> TYPE 
%token<op> '+' '-' '*' '/' '=' '%' '<' '>' '=' '&' '!' '|' ',' ';'
%token<token> '++' '--' '<=' '>=' '==' '!=' '&&' '||'  
%type<token>  array_decl func_decl func_def stmt
%type<expression> expr 
%type<expression> ident
%type<expression> var_decl
%%

scalar_decl: TYPE ident         { printf("<scalar_decl>%s%s</scalar_decl>\n", $1,$2); };


ident:    var_decl ',' ident    { 
                                  memset(dest, '\0', sizeof(dest));
                                  strcpy(dest,$1);
                                  strcat(dest,$2); 
                                  strcat(dest,$3);
                                  $$ = dest; 
                                }
        | var_decl ';'          { 
                                  memset(dest, '\0', sizeof(dest));
                                  strcpy(dest,$1);
                                  strcat(dest,$2); 
                                  $$ = dest; 
                                }
        ;
        
var_decl: ID '=' expr {
                        memset(dest, '\0', sizeof(dest));
                        strcpy(dest,$1);
                        strcat(dest,$2); 
                        strcat(dest, $3); 
                        $$ = dest; 
                      }
        | ID          
        ;
        
expr: expr '+' NUM  { $$ = $1 + $3;}
    | expr '-' NUM  { $$ = $1 - $3;}
    | NUM           { 
                      memset(dest, '\0', sizeof(dest));
                      strcpy(dest,"<expr>"); 
                      char* number; 
                      sprintf(number,"%d",$1); 
                      strcat(dest,number); 
                      strcat(dest,"</expr>"); 
                      $$ = dest; 
                    }
    ;
    
%%

int yylex(void);

int yywrap(void){
    return 1;
}

int main(void) {
    yyparse();
    return 0;
}

int yyerror(char *s){
    fprintf(stderr, "%s\n", s);
    return 0;
}

/*



    
    
    


scalar_decl: TYPE ident         {
                                  printf("<scalar_decl>%s%s</scalar_decl>\n", $1,$2);
                                };






stmt: ID '=' expr   { $$ = $1; printf("36");}
    | expr          { printf("%d</expr>",$1); }
    ;
 '*'ID '=' expr
        | '*'ID

<LINE>"\+\+"	{   return '++'; }
<LINE>"\-\-"	{   return '--'; }
<LINE>"<="		{   return '<='; }
<LINE>">="		{   return '>='; }
<LINE>"=="		{   return '=='; }
<LINE>"!="		{   return '!='; }
<LINE>"&&"		{   return '&&'; }
<LINE>"||"		{   return '||'; }
*/