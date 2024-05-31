%{
	
#include "y.tab.h"

int num_lines  = 0;
int num_chars = 0;

char* line_content;

int* sw;
int tkn=0;
int src=0;
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

Macro_Token		    ("NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MIN"|"CHAR_MAX"|"MIN"|"MAX")
Identifier_Token    (_|[a-zA-Z])[_a-zA-Z0-9]*
Operator_Token	    (\+|\-|\*|\/|%|"\+\+"|"\-\-"|"<"|">"|"<="|">="|"=="|"!="|"&"|"&&"|"\|\|"|"!"|"&"|"\|")
Punc_Token		    (\.)
Empty_Token		    (" "|"\t")
Char_Token		    (\'(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?")\')
Escape_Token	    (\'\\[01234567]+\')|(\'\\x[0-9a-fA-F]+\')|(\'\\u[0-9a-fA-F]{1,4}\')|(\'\\U[0-9a-fA-F]{1,8}\')
String_Token 	    (\"(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?")*\")
Integer_Token	    (\+|\-)?[0-9]+
Float_Token		    (\+|\-)?((\.[0-9]+)|([0-9]+\.)|([0-9]+\.[0-9]+))
EOL_Token		    "\n"
Comment_Token 	    \/\/(.)*
	
%x	LINE
%x	CTRL
%x	CMT

%%

{Line_Pattern}			    {
							    line_content = (char*) malloc(yyleng+1);
							    num_chars = yyleng;
						    	strcpy(line_content, yytext);
					    		yyless(0);
			    				if(cmt) BEGIN CMT;
				    			else BEGIN LINE;
						    }

<LINE>{Source_Control}	    { sw = &src;  BEGIN CTRL;	}

<LINE>{Token_Control}	    { sw = &tkn;  BEGIN CTRL; 	}

<LINE>{Keyword_Token}       {  
                                KeyWordHash(yytext);
                                yylval.token = key; 
                                if(tkn) printf("\n#KEYWORD: %s\n", yytext); 
                                return keyword_hash_table[key];  
                            }

<LINE>{Macro_Token}		    { if(tkn) printf("#macro:%s\n",yytext); }

<LINE>{Type_Token}          {  
                                TypeHash(yytext);
                                yylval.token = key; 
                                if(tkn) printf("\n#TYPE: %s\n", yytext); 
                                return type_hash_table[key];  
                            }

<LINE>{Float_Token}		    { if(tkn) printf("#float:%s\n", yytext); }

<LINE>{Identifier_Token}    {   
                                yylval.charv=check_id_exist(yytext);
                                if(tkn) printf("\n#IDENTIFIER: %s\n",yytext);  
                                return ID;
                            }
<LINE>"="                   { 
                                yylval.charv="="; 
                                if(tkn) printf("\n#OPERATOR: %s\n",yytext); 
                                return '='; 
                            }
<LINE>{Operator_Token}	    { 
                                yylval.charv=yytext; 
                                if(tkn) printf("\n#OPERATOR: %s\n",yytext); 
                                return '*'; 
                            }
<LINE>","		            {  
                                yylval.charv=","; 
                                if(tkn) printf("\n#COMMA: %s\n", yytext); 
                                return COMMA;
                            }
<LINE>";"		            {  
                                yylval.charv=";"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext);  
                                return SEMICOLON;
                            }
<LINE>"("		            {  
                                yylval.charv="("; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return '(';
                            }
<LINE>")"		            {  
                                yylval.charv=")"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return ')';
                            }                            
<LINE>"["		            {  
                                yylval.charv="["; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return '[';
                            }
<LINE>"]"		            {  
                                yylval.charv="]"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return ']';
                            }
<LINE>"{"		            {  
                                yylval.charv="{"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return '{';
                            }
<LINE>"}"		            {  
                                yylval.charv="}"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return '}';
                            }
<LINE>":"		            {  
                                yylval.charv=":"; 
                                if(tkn) printf("\n#SEMICOLON: %s\n", yytext); 
                                return ':';
                            }
<LINE>{Punc_Token}		    {  yylval.charv=yytext; if(tkn) printf("#punc:%s\n", yytext); return yytext[0];}

<LINE>{Escape_Token}		{ if(tkn) printf("#char:%s\n", yytext); }

<LINE>{Integer_Token}	    {   
                                yylval.charv=yytext;
                                if(tkn) printf("\n#INTEGER: %s\n", yytext); 
                                return NUM; 
                            }

<LINE>{Char_Token}		{ if(tkn) printf("#char:%s\n", yytext); }

<LINE>{String_Token}	{ if(tkn) printf("#string:%s\n", yytext);}

<LINE>{Empty_Token}		{}

<LINE>{Comment_Token} 	{}

<LINE>\/\*				{ cmt = 1; BEGIN CMT; }

<LINE>{EOL_Token}		{	
							++num_lines;
							if(src){
								printf("%d:%s", num_lines, line_content);
								free(line_content);
							}
							BEGIN 0;
						}

<CTRL>on|off			{ *sw= (int)(*(yytext+1)=='n');  BEGIN LINE; }

<CMT>\*\/				{ cmt = 0; BEGIN LINE;}
<CMT>.					{}
<CMT>{EOL_Token}		{ yyless(0); BEGIN LINE; }

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