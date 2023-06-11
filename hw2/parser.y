%{
#include <stdio.h>
%}
%union { 
    int intVal; 
    st}
%token NUM '=' '+' '-'
%start program
%%
program: 

scalar_decl: type 

%%
int main(void) {

}
int yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
 return 0;
}

