%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* const type_table[11] = {"const", "signed", "unsigned", "longlong", "long", "short", "int", "float", "double", "void", "char"};
char* const keyword_table[12] = { "for", "do", "while", "break", "continue", "if", "else", "return", "struct", "switch", "case", "default" };
extern int tkn;

char* check_id_exist(char* tok);
char* install_id(char* tok);
char* reduce_nonterminal(char* r1);
char* reduce_terminal(char* r1);
char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal(char* r1, char* r2);
char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_terminal(char* r1, char* r2);
char* reduce_nonterminal_terminal(char* r1, char* r2);
char* reduce_terminal_nonterminal(char* r1, char* r2);
char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3);

struct symbol{
    int seq_num;
    char name[40];
    int scope;
    int type;
    int parameter;
    struct symbol* next;
};

struct symbol symbol_table[295];

int top=0;
int cur_scope=0;

%}

%union{
    int token;
    char* charv;
    struct symbol *sym;
}

%start init
%token<charv> NUM 
%token<charv> ID
%token<token> CONST SIGN USIGN LONG LLONG SHRT FLOAT DOUBLE VOID CHAR INT FOR DO WHILE BREAK CONTINUE IF ELSE RETURN STRUCT SWITCH CASE DEFALUT 
%token<charv> '=' '\n' '[' ']' '{' '}'  '(' ')'
%left<charv> '*'
%type<charv>  type_decl type_layer sign_usgn int_char long_shrt
%type<charv>  ident var_init scalar_decl func_decl program array_decl func_def var_decl expr_stmt compound_stmt_content stmt condition if_stmt else_stmt
%type<charv> expr arr_ident arr_tag arr_content box arr_cnt_fmt arr_id type_ident parameter_info parameters compound_stmt section init if_else_stmt
%token<charv> SEMICOLON ENTER
%left<charv> COMMA
%%

init: program               {
                                size_t n1 = strlen($1);
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,$1);
                                printf("%s", buffer);   
                                free($1);
                                free(buffer);
                            }

program: section program                            {   $$ = reduce_nonterminal_nonterminal($1, $2);    }
    | section                                       {   $$ = reduce_nonterminal($1);    }
    ;

section:  var_decl                                  {   $$ = reduce_nonterminal($1);    }
        | func_decl                                 {   $$ = reduce_nonterminal($1);    }
        | func_def                                  {   $$ = reduce_nonterminal($1);    }
        ;

var_decl: scalar_decl                               {   $$ = reduce_nonterminal($1);    }
        | array_decl                                {   $$ = reduce_nonterminal($1);    }
        ;

scalar_decl: type_decl ident    {
                                    size_t l = strlen("<scalar_decl>");
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    size_t r = strlen("</scalar_decl>");
                                    char* buffer = (char*)malloc(l+r+n1+n2+1);
                                    strcpy(buffer,"<scalar_decl>");
                                    strcat(buffer,$1);
                                    strcat(buffer,$2); 
                                    strcat(buffer,"</scalar_decl>");                                    
                                    $$ = buffer;
                                    free($1);
                                    free($2);
                                };

array_decl: type_decl arr_ident SEMICOLON   {
                                                size_t l = strlen("<array_decl>");
                                                size_t n1 = strlen($1);
                                                size_t n2 = strlen($2);
                                                size_t n3 = strlen($3);
                                                size_t r = strlen("</array_decl>");
                                                char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                strcpy(buffer,"<array_decl>");
                                                strcat(buffer,$1);
                                                strcat(buffer,$2);
                                                strcat(buffer,$3);
                                                strcat(buffer,"</array_decl>");
                                                $$ = buffer;
                                                free($1);
                                                free($2);
                                            }    
        ;

func_decl: type_ident parameter_info SEMICOLON {
                                                    size_t l = strlen("<func_decl>");
                                                    size_t n1 = strlen($1);
                                                    size_t n2 = strlen($2);
                                                    size_t n3 = strlen($3);
                                                    size_t r = strlen("</func_decl>");
                                                    char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                    strcpy(buffer,"<func_decl>");
                                                    strcat(buffer,$1);
                                                    strcat(buffer,$2);
                                                    strcat(buffer,$3);
                                                    strcat(buffer,"</func_decl>");
                                                    $$ = buffer;
                                                    if(tkn) printf("%s",buffer);
                                                    free($1);
                                                    free($2);
                                                };

func_def: type_ident parameter_info compound_stmt   {
                                                        size_t l = strlen("<func_def>");
                                                        size_t n1 = strlen($1);
                                                        size_t n2 = strlen($2);
                                                        size_t n3 = strlen($3);
                                                        size_t r = strlen("</func_def>");
                                                        char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                        strcpy(buffer,"<func_def>");
                                                        strcat(buffer,$1);
                                                        strcat(buffer,$2);
                                                        strcat(buffer,$3);
                                                        strcat(buffer,"</func_def>");
                                                        $$ = buffer;
                                                        if(tkn) printf("%s",buffer);
                                                        free($1);
                                                        free($2);
                                                        free($3);
                                                    }
        ;


stmt: if_else_stmt                                  {
                                                        size_t l = strlen("<stmt>");
                                                        size_t n1 = strlen($1);
                                                        size_t r = strlen("</stmt>");
                                                        char* buffer = (char*)malloc(l+r+n1+1);
                                                        strcpy(buffer,"<stmt>");
                                                        strcat(buffer,$1);
                                                        strcat(buffer,"</stmt>");                                    
                                                        $$ = buffer;
                                                        free($1);
                                                    };
    | compound_stmt                                 {
                                                        size_t l = strlen("<stmt>");
                                                        size_t n1 = strlen($1);
                                                        size_t r = strlen("</stmt>");
                                                        char* buffer = (char*)malloc(l+r+n1+1);
                                                        strcpy(buffer,"<stmt>");
                                                        strcat(buffer,$1);
                                                        strcat(buffer,"</stmt>");                                    
                                                        $$ = buffer;
                                                        free($1);
                                                    }
    | expr_stmt                                     {
                                                        size_t l = strlen("<stmt>");
                                                        size_t n1 = strlen($1);
                                                        size_t r = strlen("</stmt>");
                                                        char* buffer = (char*)malloc(l+r+n1+1);
                                                        strcpy(buffer,"<stmt>");
                                                        strcat(buffer,$1);
                                                        strcat(buffer,"</stmt>");                                    
                                                        $$ = buffer;
                                                        free($1);
                                                    }
    ;

if_else_stmt: if_stmt else_stmt                     {   $$ = reduce_nonterminal_nonterminal($1, $2);   }
            | if_stmt                               {   $$ = reduce_nonterminal($1);    }
            ;

if_stmt: IF condition compound_stmt                 {   $$ = reduce_terminal_nonterminal_nonterminal(keyword_table[$1], $2, $3);   }

else_stmt: ELSE compound_stmt                       {   $$ = reduce_terminal_nonterminal(keyword_table[$1], $2);   }

expr_stmt: expr SEMICOLON                           {   $$ = reduce_nonterminal_terminal($1, $2);   } 

condition: '(' expr ')'                             {   $$ = reduce_terminal_nonterminal_terminal($1, $2, $3);    }

compound_stmt: '{' compound_stmt_content '}'        {   $$ = reduce_terminal_nonterminal_terminal($1, $2, $3);    }
            |  '{' '}'                              {   $$ = reduce_terminal_terminal($1, $2);  }                     
            ;

compound_stmt_content: stmt compound_stmt_content   { 
                                                        size_t n1 = strlen($1);
                                                        size_t n2 = strlen($2);                   
                                                        char* buffer = (char*)malloc(n1+n2+1);
                                                        strcpy(buffer,$1);
                                                        strcat(buffer,$2);
                                                        $$ = buffer;
                                                        free($1);
                                                        free($2);
                                                    } 
                | var_decl compound_stmt_content    { 
                                                        size_t n1 = strlen($1);
                                                        size_t n2 = strlen($2);                   
                                                        char* buffer = (char*)malloc(n1+n2+1);
                                                        strcpy(buffer,$1);
                                                        strcat(buffer,$2);
                                                        $$ = buffer;
                                                        free($1);
                                                        free($2);
                                                    } 
                | stmt                              {   $$ = reduce_nonterminal($1);    }
                | var_decl                          {   $$ = reduce_nonterminal($1);    }
                ;






parameter_info: '(' parameters ')'                  {   $$ = reduce_terminal_nonterminal_terminal($1, $2, $3);    }
            |   '(' ')'                             {   $$ = reduce_terminal_terminal($1, $2);  }
            ;

parameters: type_ident COMMA parameters             {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
            | type_ident                            {   $$ = reduce_nonterminal($1);    }
            ;

type_ident: type_decl ID                            {   $$ = reduce_nonterminal_terminal($1, $2);   }  

arr_ident:  arr_id COMMA arr_ident                  {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
            | arr_id                                {   $$ = reduce_nonterminal($1);    }                       
            ;

arr_id: ID arr_tag                                  {   $$ = reduce_terminal_nonterminal($1, $2);   }

arr_tag:  box arr_tag                               {   $$ = reduce_nonterminal_nonterminal($1, $2);    }
        | box '=' arr_cnt_fmt                       {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
        | box                                       {   $$ = reduce_nonterminal($1);    }
        ;

arr_cnt_fmt: '{'arr_content'}'                      {   $$ = reduce_terminal_nonterminal_terminal($1, $2, $3);    }

arr_content: arr_cnt_fmt                            {   $$ = reduce_nonterminal($1);    }
            | arr_cnt_fmt COMMA  arr_content        {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
            | expr COMMA arr_content                {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
            | expr                                  {   $$ = reduce_nonterminal($1);    } 
            ;
            
box: '[' expr ']'                                   {   $$ = reduce_terminal_nonterminal_terminal($1, $2, $3);    }   

type_decl: CONST type_layer                         {   $$ = reduce_terminal_nonterminal(type_table[$1], $2);   }
         | type_layer                               {   $$ = reduce_nonterminal($1);    }
         | CONST                                    {   $$ = reduce_terminal(type_table[$1]);   }
         | CONST type_layer '*'                     {   $$ = reduce_terminal_nonterminal_terminal(type_table[$1], $2, $3);    }
         | type_layer '*'                           {   $$ = reduce_nonterminal_terminal($1, $2);   }   
         | CONST '*'                                {   $$ = reduce_terminal_terminal(type_table[$1], $2);  }
         ;         

type_layer: sign_usgn int_char                      {   $$ = reduce_nonterminal_nonterminal($1, $2);    }
          | sign_usgn                               {   $$ = reduce_nonterminal($1);    }           
          | int_char                                {   $$ = reduce_nonterminal($1);    }
          | FLOAT                                   {   $$ = reduce_terminal(type_table[$1]);   }
          | DOUBLE                                  {   $$ = reduce_terminal(type_table[$1]);   }
          | VOID                                    {   $$ = reduce_terminal(type_table[$1]);   }
          ;

sign_usgn: SIGN                                     {   $$ = reduce_terminal(type_table[$1]);   }
         | USIGN                                    {   $$ = reduce_terminal(type_table[$1]);   }
         ;

int_char: long_shrt INT                             {   $$ = reduce_nonterminal_terminal($1, type_table[$2]);   }
        | long_shrt                                 {   $$ = reduce_nonterminal($1);    }
        | CHAR                                      {   $$ = reduce_terminal(type_table[$1]);   }
        | INT                                       {   $$ = reduce_terminal(type_table[$1]);   }
        ;

long_shrt: LLONG                                    {   $$ = reduce_terminal(type_table[$1]);   }
         | LONG                                     {   $$ = reduce_terminal(type_table[$1]);   }
         | SHRT                                     {   $$ = reduce_terminal(type_table[$1]);   }
         ;

ident: var_init COMMA ident                         {   $$ = reduce_nonterminal_terminal_nonterminal($1, $2, $3);   }
    | var_init SEMICOLON                            {   $$ = reduce_nonterminal_terminal($1, $2);   }
    | ID SEMICOLON                                  {   $$ = reduce_terminal_terminal($1, $2);  }
    | ID COMMA ident                                {   $$ = reduce_terminal_terminal_nonterminal($1, $2, $3);  }
    ;

var_init: ID '=' expr                               {   $$ = reduce_terminal_terminal_nonterminal($1, $2, $3);  }  






expr:   NUM         { 
                        size_t n1 = strlen("<expr>");
                        size_t n2 = strlen($1);
                        size_t n3 = strlen("</expr>");                      
                        char* num = (char*)malloc(n1+n2+n3+1);
                        strcpy(num,"<expr>");
                        strcat(num,$1);
                        strcat(num,"</expr>");
                        $$ = num;
                    };
    
%%

int yylex(void);

int main(int argc, char* argv[]) {
    if(argc ==2 && !strcmp(argv[1],"-d")) yydebug = tkn = 1;
    yylval.sym = symbol_table;
    yyparse();
    return 0;
}

int yyerror(char *s){
    printf("oops!\n");
    fprintf(stderr, "%s\n", s);
    return 0;
}

char* check_id_exist(char* tok){
    if(top==0) return install_id(tok);
    for(int i=0;i<top;i++) if(strcmp(symbol_table[i].name,tok)==0&& symbol_table[i].scope==cur_scope) return symbol_table[i].name;
    return install_id(tok);
}

char* install_id(char* tok){
    strcpy(symbol_table[top].name,tok);
    symbol_table[top].scope = cur_scope;
    if(tkn) printf("symbol_table[%d].name: %s\n", top, symbol_table[top].name);
    if(tkn) printf("symbol_table[%d].name: %p\n", top, symbol_table[top].name);
    top++;
    return symbol_table[top-1].name;
}

char* reduce_nonterminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    free(r1);
    if(tkn) printf("%s", buffer);
    return buffer;                           
}

char* reduce_terminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    if(tkn) printf("%s", buffer);
    return buffer;                           
}

char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r3);
    return buffer;
}

char* reduce_terminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    return buffer;
}

char* reduce_nonterminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    return buffer;
}

char* reduce_terminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r2);
    return buffer;
}

char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r3);
    return buffer;
}

char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    free(r3);
    return buffer;    
}
/*

switch_stmt: SWITCH condition switch_clause
switch_clause: '{' switch_content '}'
switch_content: CASE case_expr
                | DEFALUT default_expr
                ;
case_expr: expr ':' stmt
default_expr: ':' stmt
while_stmt: while_tag stmt
do_while_stmt:  do_tag while_tag SEMICOLON
while_tag: WHILE condition 
do_tag: DO stmt
            | return_stmt
            | break_stmt
            | continue_stmt
break_stmt: BREAK SEMICOLON 
continue_stmt: CONTINUE SEMICOLON
return_stmt: RETURN expr_stmt
            | RETURN SEMICOLON
            ;
*/
/*
            | if_else_stmt
            | switch_stmt
            | while_stmt
            | for_stmt

            */