%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* const type_table[11] = {"const", "signed", "unsigned", "longlong", "long", "short", "int", "float", "double", "void", "char"};

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
%token<token> CONST SIGN USIGN LONG LLONG SHRT FLOAT DOUBLE VOID CHAR INT
%token<charv> '=' '\n' '[' ']' 
%left<charv>'*'
%type<charv>  type_decl type_layer sign_usgn int_char long_shrt

%type<charv>  ident var_decl scalar_decl func_decl program global_var_decl array_decl arr_ident arr_tag arr_content box 
%type<charv> expr
%token<charv> SEMICOLON ENTER
%left<charv> COMMA
%%


program: global_var_decl '\n'
    ;

global_var_decl: scalar_decl global_var_decl 
                | array_decl global_var_decl
                ;

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

arr_ident: ID arr_tag           {
                                    strcpy($$,$1);
                                    strcat($$,$2);
                                }
        ;

arr_tag:  box arr_tag           {            
                                    strcpy($$,$1);
                                    strcat($$,$2);
                                }
        | box '=' arr_content   {
                                    strcpy($$,$1);
                                    strcat($$,$2);
                                    strcat($$,$3);
                                    free($1);
                                }
        | box                   
        ;

box: '[' expr ']'               {
                                    char* sc = (char*)malloc(strlen("[<expr>")+strlen($2)+strlen("</expr>]"));
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

ident: var_decl COMMA ident {
                                strcpy($$,$1);
                                strcat($$,$2);
                                strcat($$,$3);   
                            }
    | var_decl SEMICOLON    {
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

var_decl: ID '=' expr   {
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