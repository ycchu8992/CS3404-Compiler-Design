%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//char* CST[2] = {"", "const"};
//char* USG[3] = {"", "signed", "unsigned"};
//char* LLS[4] = {"", "longlong", "long", "short"};
//char* NUV[6] = {"", "int", "float", "double", "void", "char"};
char* type_table[11] = {"const", "signed", "unsigned", "long long", "long", "short", "int", "float", "double", "void", "char"};
char  buffer[295] = {'\0'};
char  temp[295] = {'\0'};
int a,b,c,d;
extern int tkn;
int buffer_ready=1;

void buffer_reset(){
    strcpy(buffer,"\0") ;
    buffer_ready=1;
}

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
%type<charv>  data_type type_layer sign_usgn int_char long_shrt
//%type<token>  data_type type_layer sign_usgn int_char long_shrt
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

array_decl: data_type arr_ident SEMICOLON   {
                                                /*
                                                d= ($1)%10;
                                                c= (($1)%100-d)/10;
                                                b= (($1)%1000-c*10-d)/100;
                                                a= ($1-b*100-c*10-d)==1000;
                                                strcpy(buffer,CST[a]);
                                                strcat(buffer,USG[b]);
                                                strcat(buffer,LLS[c]);
                                                strcat(buffer,NUV[d]);
                                                */
                                                strcat(buffer,$1);
                                                strcat(buffer,$2);
                                                strcat(buffer,$3);
                                                printf("<array_decl>%s</array_decl>",buffer);
                                                buffer_reset();
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


box: '[' expr ']'           {
                                char* sc = (char*)malloc(sizeof("[<expr>")+sizeof($2)+sizeof("</expr>]")+1);
                                strcpy(sc,"[");
                                strcat(sc,$2);
                                strcat(sc,"]");
                                $$ = sc;
                                free($2);
                            }   
    ;

scalar_decl: data_type ident    {

                                    strcpy(buffer,$1);
                                    strcat(buffer,$2);
                                    printf("<scalar_decl>%s</scalar_decl>", buffer); 
                                    buffer_reset();
                                };

data_type: CONST type_layer     {
                                    char* dct = (char*)malloc(sizeof($1)+sizeof($2)+1);
                                    strcpy(dct,type_table[$1]);
                                    strcat(dct,$2);
                                    $$ = dct;
                                    
                                }
         | type_layer            
         | CONST                { $$=type_table[$1]; }
         ;        

type_layer: sign_usgn int_char  {                            
                                    strcpy($$,$1);
                                    strcat($$,$2);
                                }
          | sign_usgn           
          | int_char            
          | FLOAT               { $$=type_table[$1]; }
          | DOUBLE              { $$=type_table[$1]; }
          | VOID                { $$=type_table[$1]; }
          ;

sign_usgn: SIGN             { $$=type_table[$1]; }
         | USIGN            { $$=type_table[$1]; }
         ;

int_char: long_shrt INT     {
                                strcpy($$,$1);
                                strcpy($$,type_table[$2]); 
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
                        char* num = (char*)malloc(sizeof("<expr>")+sizeof($1)+sizeof("</expr>")+1);
                        strcpy(num,"<expr>");
                        strcat(num,$1);
                        strcat(num,"</expr>");
                        $$ = num;
                    };
    
%%

int yylex(void);

int main(int argc, char* argv[]) {
    if(argc ==2 && !strcmp(argv[1],"-d")) {
        yydebug = 1;
        tkn = 1;
    }
    strcpy(symbol_table[0].name,"tst");
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

                                    //d= ($1)%10;
                                    //c= (($1)%100-d)/10;
                                    //b= (($1)%1000-c*10-d)/100;
                                    //a= ($1-b*100-c*10-d)==1000;
                                    //strcpy(buffer,CST[a]);
                                    //strcat(buffer,USG[b]);
                                    //strcat(buffer,LLS[c]);
                                    //strcat(buffer,NUV[d]);


                                    //strcpy($$,type_table[$1]);
                                    //strcat($$,$2);