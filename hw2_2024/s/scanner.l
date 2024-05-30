%{
#include <stdio.h>
#include <stdlib.h>

int num_lines  = 0;
int num_chars = 0;

char* line_content;

int* sw;
int tkn=1;
int src=1;
int cmt = 0;

%}

Line_Pattern		((.){0,298}\n)|((.){1,299})
Source_Control 	(#pragma)(" "|"\t")+source(" "|"\t")+
Token_Control 	(#pragma)(" "|"\t")+token(" "|"\t")+
Keyword_Token	("double"|"for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default"|"void"|"int"|"char"|"float"|"const"|"signed"|"unsigned"|"short"|"long")
Macro_Token		("NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MIN"|"CHAR_MAX"|"MIN"|"MAX")
Identifier_Token	(_|[a-zA-Z])[_a-zA-Z0-9]*
Operator_Token	(\+|\-|\*|\/|%|"\+\+"|"\-\-"|"<"|">"|"<="|">="|"=="|"!="|"="|"&"|"&&"|"\|\|"|"!"|"&"|"\|")
Punc_Token		(\:|;|,|\.|\[|\]|\(|\)|\{|\})
Empty_Token		(" "|"\t")
Char_Token		(\'(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?")\')
Escape_Token	(\'\\[01234567]+\')
Escape_Token2	(\'\\x[0-9a-fA-F]+\')
Escape_Token3	(\'\\u[0-9a-fA-F]{1,4}\')
Escape_Token4	(\'\\U[0-9a-fA-F]{1,8}\')
String_Token 	(\"(.|"\\a"|"\\b"|"\\e"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"|"\\\\"|"\\\'"|"\\\""|"\\\?")*\")
Integer_Token	(\+|\-)?[0-9]+
Float_Token		(\+|\-)?((\.[0-9]+)|([0-9]+\.)|([0-9]+\.[0-9]+))
EOL_Token		"\n"
Comment_Token 	\/\/(.)*
	
%x	LINE
%x	CTRL
%x	CMT

%%

{Line_Pattern}			{
							line_content = (char*) malloc(yyleng+1);
							num_chars = yyleng;
							strcpy(line_content, yytext);
							yyless(0);
							if(cmt) BEGIN CMT;
							else BEGIN LINE;
						}

<LINE>{Source_Control}	{ sw = &src;  BEGIN CTRL;	}

<LINE>{Token_Control}		{ sw = &tkn;  BEGIN CTRL; 	}

<LINE>{Keyword_Token}	{ if(tkn) printf("#key:%s\n", yytext); }

<LINE>{Macro_Token}		{ if(tkn) printf("#macro:%s\n",yytext); }




<LINE>{Float_Token}		{ if(tkn) printf("#float:%s\n", yytext); }

<LINE>{Identifier_Token}	{ if(tkn) printf("#id:%s\n",yytext); }

<LINE>{Operator_Token}	{ if(tkn) printf("#op:%s\n",yytext); }

<LINE>{Punc_Token}		{ if(tkn) printf("#punc:%s\n", yytext); }

<LINE>{Escape_Token}		{ if(tkn) printf("#char:%s\n", yytext); }
<LINE>{Escape_Token2}		{ if(tkn) printf("#char:%s\n", yytext); }
<LINE>{Escape_Token3}		{ if(tkn) printf("#char:%s\n", yytext); }
<LINE>{Escape_Token4}		{ if(tkn) printf("#char:%s\n", yytext); }

<LINE>{Integer_Token}	{ if(tkn) printf("#integer:%s\n", yytext); }

<LINE>{Char_Token}		{ if(tkn) printf("#char:%s\n", yytext); }

<LINE>{String_Token}		{ if(tkn) printf("#string:%s\n", yytext);}

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

<CTRL>on|off				{ *sw= (int)(*(yytext+1)=='n');  BEGIN LINE; }

<CMT>\*\/				{ cmt = 0; BEGIN LINE;}
<CMT>.					{}
<CMT>{EOL_Token}		{ yyless(0); BEGIN LINE; }
			

%%

int main(int argc, char* argv[]) {
	yylex();
	return 0;
}
