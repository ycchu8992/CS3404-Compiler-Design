%{
	
#include "y.tab.h"

int num_lines  = 0;
int num_chars = 0;

char* line_content;

int* sw;
int tkn=0;
int cmt = 0;
int key = -1;
int type_hash_table[11] = { CONST, SIGN, USIGN, LLONG, LONG, SHRT, INT, FLOAT, DOUBLE, VOID, CHAR };
int keyword_hash_table[12] = { FOR, DO, WHILE, BREAK, CONTINUE, IF, ELSE, RETURN, STRUCT, SWITCH, CASE, DEFALUT };

void TypeHash(char* yytext);
void KeyWordHash(char* yytext);
extern char* check_id_exist(char* tok);

%}

Line_Pattern	    ((.){0,298}\n)|((.){1,299})
Source_Control 	    (#pragma)(" "|"\t")+source(" "|"\t")+
Token_Control 	    (#pragma)(" "|"\t")+token(" "|"\t")+

Keyword_Token	    "for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default"
Type_Token          "const"|"signed"|"unsigned"|"long long"|"long"|"short"|"int"|"float"|"double"|"void"|"char"

Identifier_Token    (_|[a-zA-Z])[_a-zA-Z0-9]*
Operator_Token	    ("&&"|"\|\|")
Empty_Token		    (" "|"\t")
Char_Token		    (\'(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?")\')
Escape_Token	    (\'\\[01234567]+\')|(\'\\x[0-9a-fA-F]+\')|(\'\\u[0-9a-fA-F]{1,4}\')|(\'\\U[0-9a-fA-F]{1,8}\')

String_Token 	    (\"(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\"\"|"\\\?")*\")
Integer_Token	    [0-9]+
Float_Token		    ((\.[0-9]+)|([0-9]+\.)|([0-9]+\.[0-9]+))
EOL_Token		    "\n"
Comment_Token 	    \/\/(.)*
	
%x	LINE
%x	CTRL
%x	CMT

%%

{Line_Pattern}			    {
					    		yyless(0);
			    				if(cmt) BEGIN CMT;
				    			else BEGIN LINE;
                                num_lines++;
						    }

<LINE>{Keyword_Token}       {   
                                KeyWordHash(yytext);
                                yylval.token = key; 
                                if(tkn) printf("\n#KEYWORD: %s\n", yytext); 
                                return keyword_hash_table[key];  
                            }

<LINE>"NULL"		        {   
                                size_t buffer_size = strlen("0");
                                char* buffer = (char*)malloc(buffer_size);
                                strcpy(buffer,"0");
                                yylval.charv = buffer;
                                return NULL_SIGNAL;
                            }

<LINE>{Type_Token}          {  
                                TypeHash(yytext);
                                yylval.token = key; 
                                if(tkn) printf("\n#TYPE: %s\n", yytext); 
                                return type_hash_table[key];  
                            }

<LINE>{Float_Token}		    {   
                                size_t buffer_size = strlen(yytext) + 7;
                                char* buffer = (char*)malloc(buffer_size);
                                memset(buffer, '\0', buffer_size);
                                sprintf(buffer, "%0.6f", atof(yytext));
                                yylval.charv = buffer;
                                return FLOAT_NUM;
                            }

<LINE>{Identifier_Token}    {   yylval.charv=check_id_exist(yytext); return ID; }


<LINE>"="                   {   yylval.charv="=";return '=';  }
<LINE>"+"	                {   yylval.charv="+"; return '+'; }
<LINE>"-"	                {   yylval.charv="-"; return '-'; }
<LINE>"*"	                {   yylval.charv="*"; return '*'; }
<LINE>"/"	                {   yylval.charv="/"; return '/'; }
<LINE>"%"	                {   yylval.charv="%"; return '%'; }
<LINE>"<<"	                {   yylval.charv="<<"; return SHIFT_LEFT; }
<LINE>">>"	                {   yylval.charv=">>"; return SHIFT_RIGHT; }
<LINE>"<="	                {   yylval.charv="<="; return LESS_OR_EQUAL; }
<LINE>">="	                {   yylval.charv=">="; return GREATER_OR_EQUAL; }
<LINE>"=="	                {   yylval.charv="=="; return IS_EQUAL; }
<LINE>"!="	                {   yylval.charv="!="; return IS_NOT_EQUAL; }
<LINE>"<"	                {   yylval.charv="<"; return '<'; }
<LINE>">"	                {   yylval.charv=">"; return '>'; }
<LINE>"!"	                {   yylval.charv="!"; return '!'; }
<LINE>"~"	                {   yylval.charv="~"; return '~'; }
<LINE>"^"	                {   yylval.charv="^"; return '^'; }
<LINE>"&"	                {   yylval.charv="&"; return '&'; }
<LINE>"|"	                {   yylval.charv="|"; return '|'; }
<LINE>"++"	                {   yylval.charv="++"; return INCREMENT; }
<LINE>"--"	                {   yylval.charv="--"; return DECREMENT; }
<LINE>"&&"	                {   yylval.charv="&&"; return AND;  }
<LINE>"||"	                {   yylval.charv="||"; return OR;   }


<LINE>","		            {   yylval.charv=","; return ',';   }
<LINE>";"		            {   yylval.charv=";"; return ';';   }
<LINE>"("		            {   yylval.charv="("; return '(';   }
<LINE>")"		            {   yylval.charv=")"; return ')';   }                            
<LINE>"["		            {   yylval.charv="["; return '[';   }
<LINE>"]"		            {   yylval.charv="]"; return ']';   }
<LINE>"{"		            {   yylval.charv="{"; return '{';   }
<LINE>"}"		            {   yylval.charv="}"; return '}';   }
<LINE>":"		            {   yylval.charv=":"; return ':';   }

<LINE>{Escape_Token}		{   if(tkn) printf("#char:%s\n", yytext);   }




<LINE>{Integer_Token}	    {   yylval.charv=yytext; return INT_NUM;    }

<LINE>{Char_Token}		    {   
                                size_t buffer_size = strlen(yytext);
                                char* buffer = (char*)malloc(buffer_size);
                                strcpy(buffer,yytext);
                                yylval.charv = buffer;
                                return CHARACTER;
                            }

<LINE>{String_Token}	    {   
                                size_t buffer_size = strlen(yytext);
                                char* buffer = (char*)malloc(buffer_size);
                                strcpy(buffer,yytext);
                                yylval.charv = buffer;
                                return STRING;
                            }

<LINE>{Empty_Token}		    {}

<LINE>{Comment_Token} 	    {}

<LINE>\/\*				    { cmt = 1; BEGIN CMT; }

<LINE>{EOL_Token}		    {	BEGIN 0;    }


<CMT>\*\/				    { cmt = 0; BEGIN LINE;}
<CMT>.					    {}
<CMT>{EOL_Token}		    { yyless(0); BEGIN LINE; }

%%

void TypeHash(char* yytext){
    if(!strcmp(yytext,"const")){
		  key = 0;
    }else if(!strcmp(yytext,"signed")){
		  key = 1;
    }else if(!strcmp(yytext,"unsigned")){
		  key = 2;
    }else if(!strcmp(yytext,"long long")){
		  key = 3;
    }else if(!strcmp(yytext,"long")){
		  key = 4;
    }else if(!strcmp(yytext,"short")){
		  key = 5;
    }else if(!strcmp(yytext,"int")){
		  key = 6;
    }else if(!strcmp(yytext,"float")){
		  key = 7;
    }else if(!strcmp(yytext,"double")){
		  key = 8;
    }else if(!strcmp(yytext,"void")){
		  key = 9;
    }else if(!strcmp(yytext,"char")){
		  key = 10;
    }else key = -1;
}

void KeyWordHash(char* yytext){
    if(!strcmp(yytext,"for")){
		  key = 0;
    }else if(!strcmp(yytext,"do")){
		  key = 1;
    }else if(!strcmp(yytext,"while")){
		  key = 2;
    }else if(!strcmp(yytext,"break")){
		  key = 3;
    }else if(!strcmp(yytext,"continue")){
		  key = 4;
    }else if(!strcmp(yytext,"if")){
		  key = 5;
    }else if(!strcmp(yytext,"else")){
		  key = 6;
    }else if(!strcmp(yytext,"return")){
		  key = 7;
    }else if(!strcmp(yytext,"struct")){
		  key = 8;
    }else if(!strcmp(yytext,"switch")){
		  key = 9;
    }else if(!strcmp(yytext,"case")){
		  key = 10;
    }else if(!strcmp(yytext,"default")){
		  key = 11;
    }else key = -1;
}

/*

 

 
<LINE>{Operator_Token}	    { 
                                yylval.charv=yytext; 
                                if(tkn) printf("\n#OPERATOR: %s\n",yytext); 
                                return yytext; 
                            }
    (int)a;
    while(1){
        &(123);
        printf("as\n");
    }
    int a = +1;
*/