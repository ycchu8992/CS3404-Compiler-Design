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

%start program
%token<charv> NUM 
%token<charv> ID
%token<token> CONST SIGN USIGN LONG LLONG SHRT FLOAT DOUBLE VOID CHAR INT FOR DO WHILE BREAK CONTINUE IF ELSE RETURN STRUCT SWITCH CASE DEFALUT 
%token<charv> '=' '\n' '[' ']' '{' '}'  '(' ')'
%left<charv> '*'
%type<charv>  type_decl type_layer sign_usgn int_char long_shrt
%type<charv>  ident var_init scalar_decl func_decl program array_decl func_def var_decl
%type<charv> expr arr_ident arr_tag arr_content box arr_cnt_fmt arr_id type_ident parameter_info parameters compound_stmt
%token<charv> SEMICOLON ENTER
%left<charv> COMMA
%%


program:  var_decl program
        | func_decl program 
        | func_def program
        ;

var_decl: scalar_decl | array_decl ;

func_def: type_ident parameter_info compound_stmt   {
                                                        size_t n1 = strlen($1);
                                                        size_t n2 = strlen($2);
                                                        size_t n3 = strlen($3);
                                                        char* buffer = (char*)malloc(n1+n2+n3+1);
                                                        strcpy(buffer,$1);
                                                        strcat(buffer,$2);
                                                        strcat(buffer,$3);
                                                        printf("<func_def>%s</func_def>", buffer);
                                                        free(buffer);
                                                        free($1);
                                                        free($2);
                                                        free($3);
                                                    };
        ;

stmt: single_stmt stmt
    | single_stmt
    ;

single_stmt: expr_stmt
            | if_else_stmt
            | switch_stmt
            | while_stmt
            | for_stmt
            | return_stmt
            | break_stmt
            | continue_stmt
            | '{' compound_stmt '}'
            | '{' '}'
            ;

expr_stmt:　expr SEMICOLON

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

return_stmt: RETURN expr SEMICOLON
            | RETURN SEMICOLON
            ;

compound_stmt: stmt compound_stmt
            | var_decl compound_stmt
            ;

func_decl: type_ident parameter_info SEMICOLON {
                                                    size_t n1 = strlen($1);
                                                    size_t n2 = strlen($2);
                                                    size_t n3 = strlen($3);
                                                    char* buffer = (char*)malloc(n1+n2+n3+1);
                                                    strcpy(buffer,$1);
                                                    strcat(buffer,$2);
                                                    strcat(buffer,$3);
                                                    printf("<func_decl>%s</func_decl>", buffer);
                                                    free(buffer);
                                                    free($1);
                                                    free($2);
                                                };

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
        | type_ident
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

array_decl: type_decl arr_ident SEMICOLON   {
                                                size_t n1 = strlen($1);
                                                size_t n2 = strlen($2);
                                                size_t n3 = strlen($3);
                                                char* afr = (char*)malloc(n1+n2+n3+1);
                                                strcpy(afr,$1);
                                                strcat(afr,$2);
                                                strcat(afr,$3);
                                                printf("<array_decl>%s</array_decl>",afr);
                                                free(afr);
                                            }    
        ;

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
            | arr_id
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
                                    char* art = (char*)malloc(n1+n2+n3+1);
                                    strcpy(art,$1);
                                    strcat(art,$2);
                                    strcat(art,$3);
                                    $$ = art;
                                    free($1);
                                    free($3);
                                }
        | box                   
        ;

arr_cnt_fmt: '{'arr_content'}'          {
                                            size_t n1 = strlen($1);
                                            size_t n2 = strlen($2);
                                            size_t n3 = strlen($3);
                                            char* aac = (char*)malloc(n1+n2+n3+1);
                                            strcpy(aac,$1);
                                            strcat(aac,$2);
                                            strcat(aac,$3);
                                            $$ = aac;
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
                                            char* arc = (char*)malloc(n1+n2+n3+1);
                                            strcpy(arc,$1);
                                            strcat(arc,$2);
                                            strcat(arc,$3);
                                            $$ = arc;
                                            free($1);
                                            free($3);
                                        } 
            | expr              {
                                    size_t n1 = strlen($1);
                                    char* exr = (char*)malloc(n1+1);
                                    strcpy(exr,$1);
                                    $$ = exr;
                                    free($1);
                                    
                                } 
            ;
            
box: '[' expr ']'               {
                                    char* sc = (char*)malloc(strlen("[<expr>")+strlen($2)+strlen("</expr>]")+1);
                                    strcpy(sc,"[");
                                    strcat(sc,$2);
                                    strcat(sc,"]");
                                    $$ = sc;
                                    free($2);
                                }   
    ;

scalar_decl: type_decl ident    {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* bfr = (char*)malloc(n1+n2+1);
                                    strcpy(bfr,$1);
                                    strcat(bfr,$2);
                                    printf("<scalar_decl>%s</scalar_decl>", bfr); 
                                    free(bfr);
                                };

type_decl: CONST type_layer     {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    char* dct = (char*)malloc(n1+n2+1);
                                    strcpy(dct,type_table[$1]);
                                    strcat(dct,$2);
                                    $$ = dct;
                                }
         | type_layer           {
                                    size_t n1 = strlen($1);
                                    char* dct = (char*)malloc(n1+1);
                                    strcpy(dct,$1);
                                    $$ = dct;
                                }
         | CONST                {
                                    size_t n1 = strlen(type_table[$1]);
                                    char* dct = (char*)malloc(n1+1);
                                    strcpy(dct,type_table[$1]);
                                    $$ = dct;
                                }
         | CONST type_layer '*' {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    size_t n3 = strlen($3);
                                    char* dct = (char*)malloc(n1+n2+n3+1);
                                    strcpy(dct,type_table[$1]);
                                    strcat(dct,$2);
                                    strcat(dct,$3);
                                    $$ = dct;
                                }
         | type_layer '*'       {
                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* dct = (char*)malloc(n1+n2+1);
                                    strcpy(dct,$1);
                                    strcat(dct,$2);
                                    $$ = dct;
                                }   
         | CONST '*'            {
                                    size_t n1 = strlen(type_table[$1]);
                                    size_t n2 = strlen($2);
                                    char* dct = (char*)malloc(n1+n2+1);
                                    strcpy(dct,type_table[$1]);
                                    strcat(dct,$2);
                                    $$ = dct;
                                }
         ;         

type_layer: sign_usgn int_char  {   

                                    size_t n1 = strlen($1);
                                    size_t n2 = strlen($2);
                                    char* tsi = (char*)malloc(n1+n2+1);
                                    strcpy(tsi,$1);
                                    strcat(tsi,$2);
                                    $$ = tsi;                       
                                }
          | sign_usgn           
          | int_char            
          | FLOAT               { $$=type_table[$1]; }
          | DOUBLE              { $$=type_table[$1]; }
          | VOID                { $$=type_table[$1]; }
          ;

sign_usgn: SIGN                 { $$=type_table[$1]; }
         | USIGN                { $$=type_table[$1]; }
         ;

int_char: long_shrt INT     {
                                size_t n1 = strlen($1);
                                size_t n2 = strlen(type_table[$2]);
                                char* ilI = (char*)malloc(n1+n2+1);
                                strcpy(ilI,$1);
                                strcat(ilI,type_table[$2]);
                                $$ = ilI;  
                            }
        | long_shrt         
        | CHAR              { $$=type_table[$1]; }
        | INT               { $$=type_table[$1]; }
        ;

long_shrt: LLONG            { $$=type_table[$1]; }
         | LONG             { $$=type_table[$1]; }
         | SHRT             { $$=type_table[$1]; }
         ;

ident: var_init COMMA ident {
                                strcpy($$,$1);
                                strcat($$,$2);
                                strcat($$,$3);   
                            }
    | var_init SEMICOLON    {
                                strcpy($$,$1);
                                strcat($$,$2);
                            }
    | ID SEMICOLON          {
                                strcpy($$,$1);
                                strcat($$,$2);
                            }
    | ID COMMA ident        {
                                strcpy($$,$1);
                                strcat($$,$2);
                                strcat($$,$3);
                            }
    ;

var_init: ID '=' expr   {
                            strcpy($$,$1);
                            strcat($$,$2);
                            strcat($$,$3);
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
    //if(argc ==2 && !strcmp(argv[1],"-d")) yydebug = tkn = 1;
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