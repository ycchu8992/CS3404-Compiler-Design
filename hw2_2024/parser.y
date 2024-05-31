%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* const type_table[11] = {"const", "signed", "unsigned", "longlong", "long", "short", "int", "float", "double", "void", "char"};
char* const keyword_table[12] = { "for", "do", "while", "break", "continue", "if", "else", "return", "struct", "switch", "case", "default" };
extern int tkn;

char* check_id_exist(char* tok);
char* install_id(char* tok);


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
%type<charv>  ident var_init scalar_decl func_decl program array_decl func_def var_decl expr_stmt compound_stmt_content stmt
%type<charv> expr arr_ident arr_tag arr_content box arr_cnt_fmt arr_id type_ident parameter_info parameters compound_stmt init
%token<charv> SEMICOLON ENTER
%left<charv> COMMA
%%

init: program

program:  var_decl program  {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);
                                char* buffer = (char*)malloc(n1+n2+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                $$ = buffer; 
                                free($1);
                                free($2);
                            }
        | func_decl program {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);
                                char* buffer = (char*)malloc(n1+n2+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                $$ = buffer;
                                printf("%s", buffer);  
                                free($1);
                                free($2);
                            }
        | func_def program  {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);
                                char* buffer = (char*)malloc(n1+n2+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                $$ = buffer;
                                printf("%s", buffer);  
                                free($1);
                                free($2);
                            }
        ;

var_decl: scalar_decl           {
                                    
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    printf("%s",buffer);
                                    free($1);   
                                }
        | array_decl            {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    printf("%s",buffer);
                                    free($1);   
                                }
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
                                                    printf("%s",buffer);
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
                                                        printf("%s",buffer);
                                                        free($1);
                                                        free($2);
                                                        free($3);
                                                    }
        ;

expr_stmt: expr SEMICOLON                           { 
                                                        size_t n1 = strlen($1);
                                                        size_t n2 = strlen($2);                   
                                                        char* buffer = (char*)malloc(n1+n2+1);
                                                        strcpy(buffer,$1);
                                                        strcat(buffer,$2);
                                                        $$ = buffer;
                                                        free($1);
                                                    } ;

compound_stmt: '{' compound_stmt_content '}'    { 
                                                    size_t n1 = strlen($1);
                                                    size_t n2 = strlen($2);
                                                    size_t n3 = strlen($3);                      
                                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                                    strcpy(buffer,$1);
                                                    strcat(buffer,$2);
                                                    strcat(buffer,$3);
                                                    $$ = buffer;
                                                    free($2);
                                                }
            | '{' '}'                           { 
                                                    size_t n1 = strlen($1);
                                                    size_t n2 = strlen($2);                   
                                                    char* buffer = (char*)malloc(n1+n2+1);
                                                    strcpy(buffer,$1);
                                                    strcat(buffer,$2);
                                                    $$ = buffer;
                                                }                      
            ;

compound_stmt_content: expr_stmt compound_stmt_content   { 
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
                | expr_stmt     {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);   
                                }
                | var_decl      {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);   
                                }
                ;






parameter_info: '(' parameters ')' {
                                        size_t n1 = strlen($1);
                                        size_t n2 = strlen($2);
                                        size_t n3 = strlen($3);
                                        char* buffer = (char*)malloc(n1+n2+n3+1);
                                        strcpy(buffer,$1);
                                        strcat(buffer,$2);
                                        strcat(buffer,$3);
                                        $$ = buffer;
                                        free($2);
                                    }
        | '(' ')'                   {
                                        size_t n1 = strlen($1);
                                        size_t n2 = strlen($2);
                                        char* buffer = (char*)malloc(n1+n2+1);
                                        strcpy(buffer,$1);
                                        strcat(buffer,$2);
                                        $$ = buffer;                                        
                                    }
        ;

parameters: type_ident COMMA parameters {
                                            size_t n1 = strlen($1);
                                            size_t n2 = strlen($2);
                                            size_t n3 = strlen($3);
                                            char* buffer = (char*)malloc(n1+n2+n3+1);
                                            strcpy(buffer,$1);
                                            strcat(buffer,$2);
                                            strcat(buffer,$3);
                                            $$ = buffer;
                                            free($1);
                                            free($3);
                                        }
        | type_ident            {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);   
                                }
        ;

type_ident: type_decl ID  {
                            size_t n1 = strlen($1);
                            size_t n2 = strlen($2);
                            char* buffer = (char*)malloc(n1+n2+1);
                            strcpy(buffer,$1);
                            strcat(buffer,$2);
                            $$ = buffer;
                            free($1);                        
                       };

arr_ident:  arr_id COMMA arr_ident    {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    size_t n3 = strlen($3);
                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    strcat(buffer,$3);
                                    $$ = buffer;
                                    free($1);
                                    free($3);
                                }
            | arr_id            {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);   
                                }
        ;

arr_id: ID arr_tag        {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                    free($2);
                                }

arr_tag:  box arr_tag           {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                    free($1);
                                    free($2);
                                }
        | box '=' arr_cnt_fmt   {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    size_t n3 = strlen($3);
                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    strcat(buffer,$3);
                                    $$ = buffer;
                                    free($1);
                                    free($3);
                                }
        | box                   {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);   
                                }
        ;

arr_cnt_fmt: '{'arr_content'}'          {
                                            size_t n1 = strlen($1);
                                            size_t n2 = strlen($2);
                                            size_t n3 = strlen($3);
                                            char* buffer = (char*)malloc(n1+n2+n3+1);
                                            strcpy(buffer,$1);
                                            strcat(buffer,$2);
                                            strcat(buffer,$3);
                                            $$ = buffer;
                                            free($2);
                                        }
            ;

arr_content: arr_cnt_fmt                {
                                            size_t n1 = strlen($1);
                                            char* buffer = (char*)malloc(n1+1);//free_at_next_reduction
                                            strcpy(buffer,$1);
                                            $$ = buffer;
                                            free($1);   
                                        }
            | arr_cnt_fmt COMMA  arr_content   {
                                            size_t n1 = strlen($1);
                                            size_t n2 = strlen($2);
                                            size_t n3 = strlen($3);
                                            char* buffer = (char*)malloc(n1+n2+n3+1);//free_at_next_reduction
                                            strcpy(buffer,$1);
                                            strcat(buffer,$2);
                                            strcat(buffer,$3);
                                            $$ = buffer;
                                            free($1);
                                            free($3);
                                        }
            | expr COMMA arr_content    {
                                            size_t n1 = strlen($1);
                                            size_t n2 = strlen($2);
                                            size_t n3 = strlen($3);
                                            char* buffer = (char*)malloc(n1+n2+n3+1);
                                            strcpy(buffer,$1);
                                            strcat(buffer,$2);
                                            strcat(buffer,$3);
                                            $$ = buffer;
                                            free($1);
                                            free($3);
                                        } 
            | expr              {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);
                                } 
            ;
            
box: '[' expr ']'               {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    size_t n3 = strlen($3);
                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    strcat(buffer,$3);
                                    $$ = buffer;
                                    free($2);
                                }   
    ;

type_decl: CONST type_layer     {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,type_table[$1]);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                }
         | type_layer           {
                                    size_t n1 = strlen($1);
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,$1);
                                    $$ = buffer;
                                    free($1);
                                }
         | CONST                {
                                    size_t n1 = strlen(type_table[$1]);
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,type_table[$1]);
                                    $$ = buffer;
                                }
         | CONST type_layer '*' {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    size_t n3 = strlen($3);
                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                    strcpy(buffer,type_table[$1]);
                                    strcat(buffer,$2);
                                    strcat(buffer,$3);
                                    $$ = buffer;
                                    free($2);
                                }
         | type_layer '*'       {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                    free($1);
                                }   
         | CONST '*'            {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,type_table[$1]);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                }
         ;         

type_layer: sign_usgn int_char  {   
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* buffer = (char*)malloc(n1+n2+1);
                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    $$ = buffer;
                                    free($1);
                                    free($2);                     
                                }
          | sign_usgn           { 
                                    size_t n1 = strlen($1);             
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer, $1);
                                    $$ = buffer;
                                    free($1);
                                }           
          | int_char            { 
                                    size_t n1 = strlen($1);             
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer, $1);
                                    $$ = buffer;
                                    free($1);
                                }
          | FLOAT               { 
                                    size_t n1 = strlen(type_table[$1]);             
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,type_table[$1]);
                                    $$ = buffer;
                                }
          | DOUBLE              { 
                                    size_t n1 = strlen(type_table[$1]);             
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,type_table[$1]);
                                    $$ = buffer;
                                }
          | VOID                { 
                                    size_t n1 = strlen(type_table[$1]);             
                                    char* buffer = (char*)malloc(n1+1);
                                    strcpy(buffer,type_table[$1]);
                                    $$ = buffer;
                                }
          ;

sign_usgn: SIGN             { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
         | USIGN            { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
         ;

int_char: long_shrt INT     {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen(type_table[$2]);
                                char* buffer = (char*)malloc(n1+n2+1);
                                strcpy(buffer,$1);
                                strcat(buffer,type_table[$2]);
                                $$ = buffer;
                                free($1);  
                            }
        | long_shrt         { 
                                size_t n1 = strlen($1);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer, $1);
                                $$ = buffer;
                                free($1);
                            }
        | CHAR              { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
        | INT               { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
        ;

long_shrt: LLONG            { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
         | LONG             { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
         | SHRT             { 
                                size_t n1 = strlen(type_table[$1]);             
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,type_table[$1]);
                                $$ = buffer;
                            }
         ;

ident: var_init COMMA ident {
                                strcpy($$,$1);
                                strcat($$,$2);
                                strcat($$,$3);   
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);
                                size_t n3 = strlen($3);               
                                char* buffer = (char*)malloc(n1+n2+n3+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                strcat(buffer,$3);
                                $$ = buffer;
                                free($1);
                                free($3);
                            }
    | var_init SEMICOLON    {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);            
                                char* buffer = (char*)malloc(n1+n2+1);                        
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                $$ = buffer;
                                free($1);
                            }
    | ID SEMICOLON          {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);            
                                char* buffer = (char*)malloc(n1+n2+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                $$ = buffer;
                            }
    | ID COMMA ident        {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen($2);     
                                size_t n3 = strlen($3);       
                                char* buffer = (char*)malloc(n1+n2+n3+1);
                                strcpy(buffer,$1);
                                strcat(buffer,$2);
                                strcat(buffer,$3);
                                $$ = buffer;
                                free($3);
                            }
    ;

var_init: ID '=' expr   {
                            size_t n1 = strlen($1);
                            size_t n2 = strlen($2);     
                            size_t n3 = strlen($3);       
                            char* buffer = (char*)malloc(n1+n2+n3+1);
                            strcpy(buffer,$1);
                            strcat(buffer,$2);
                            strcat(buffer,$3);
                            $$ = buffer;
                            free($3);
                        }   
        ;

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
    //printf("oops!\n");
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

/*
if_else_stmt: if_stmt else_stmt
            | if_stmt
            ;
if_stmt: IF condition compound_stmt
else_stmt: ELSE compound_stmt
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
condition: '(' expr ')'
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
            | return_stmt
            | break_stmt
            | continue_stmt
            */