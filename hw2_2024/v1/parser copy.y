%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* CST[2] = {"", "const"};
char* USG[3] = {"", "signed", "unsigned"};
char* LLS[4] = {"", "longlong", "long", "short"};
char* NUV[6] = {"", "int", "float", "double", "void", "char"};
char  buffer[295] = {'\0'};
char  temp[295] = {'\0'};
int a,b,c,d;
extern int tkn;
int buffer_ready=1;

void buffer_reset(){
    strcpy(buffer,"") ;
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

%start scalar_decl
%token<charv> NUM 
%token<charv> ID
%token<token> CONST SIGN USIGN LONG LLONG SHRT FLOAT DOUBLE VOID CHAR INT
 
%token<charv> '='
%type<token>  data_type type_layer sign_usgn int_char long_shrt
%type<charv>  ident var_decl  scalar_decl
%type<charv> expr
%token<charv> SEMICOLON ENTER
%left<charv> COMMA
%%



scalar_decl: data_type ident    {
                                    d= ($1)%10;
                                    c= (($1)%100-d)/10;
                                    b= (($1)%1000-c*10-d)/100;
                                    a= ($1-b*100-c*10-d)==1000;
                                    strcpy(buffer,CST[a]);
                                    strcat(buffer,USG[b]);
                                    strcat(buffer,LLS[c]);
                                    strcat(buffer,NUV[d]);
                                    strcat(buffer,$2);
                                    printf("<scalar_decl>%s</scalar_decl>\n", buffer); 
                                    buffer_reset();
                                };

data_type: CONST type_layer   { $$ = $1 + $2; }
         | type_layer            
         | CONST              
         ;        

type_layer: sign_usgn int_char  { $$ = $1 + $2; }
          | sign_usgn
          | int_char
          | FLOAT
          | DOUBLE
          | VOID
          ;

sign_usgn: SIGN             
         | USIGN
         ;

int_char: long_shrt INT         { $$ = $1 + $2; }
        | long_shrt
        | CHAR
        | INT                  
        ;

long_shrt: LLONG
         | LONG
         | SHRT
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
                            char* id = (char*)malloc(sizeof($1)+sizeof($2)+sizeof($3)+1);
                            strcpy(id,$1);
                            strcat(id,$2);
                            strcat(id,$3);
                            $$ = id;
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
        //yydebug = 1;
        //tkn = 1;
    }
    strcpy(symbol_table[0].name,"tst");
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