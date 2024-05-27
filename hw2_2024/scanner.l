%{

#include "y.tab.h"

int num_lines  = 0;
int num_chars = 0;

char* line_content;
int cmt = 0;

%}


Keyword_Token	("for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default")

Type_Token_a 	(("const ")?(("un")?"signed ")?("long "("long ")?|"short ")?"int")|"const"
Type_Token_b	("const ")?((("un")?"signed ")?("long"(" long")?|"short"|"char")|("signed"|"unsigned"|"float"|"double"|"void"))

Macro_Token		("NULL"|"__COUNTER__"|"__LINE__"|"INT_MAX"|"INT_MIN"|"CHAR_MIN"|"CHAR_MAX"|"MIN"|"MAX")

Identi_Token	(_|[a-zA-Z])[_a-zA-Z0-9]*
Operator_Token	(\+|\-|\*|\/|%|"\+\+"|"\-\-"|"<"|">"|"<="|">="|"=="|"!="|"="|"&"|"&&"|"\|\|"|"!"|"&"|"\|")

Punc_Token		([:;,.]\[|\]|\(|\)|\{|\})
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



{Type_Token_a}	{ yylval.data_type = yytext; return TYPE; }
{Type_Token_b}	{ yylval.data_type = yytext; return TYPE; }
{Identi_Token}  { yylval.identifier = yytext; return ID; }


{Keyword_Token}	{ printf("#key:%s\n", yytext); }
{Macro_Token}	{ printf("#macro:%s\n",yytext); }


{Float_Token}	{ yylval.token_float = atof(yytext); return NUM;  }



"+"		{  yylval.op = yytext; return '+'; }
"-"		{  yylval.op = yytext; return '-'; }
"*"		{  yylval.op = yytext; return '*'; }
"/"		{  yylval.op = yytext; return '/'; }
"%"		{  yylval.op = yytext; return '%'; }
"<"		{  yylval.op = yytext; return '<'; }
">"		{  yylval.op = yytext; return '>'; }
"="		{  yylval.op = yytext; return '='; }
"&"		{  yylval.op = yytext; return '&'; }
"!"		{  yylval.op = yytext; return '!'; }
"|"		{  yylval.op = yytext; return '|'; }


{Punc_Token}			{ yylval.punc_symbol=yytext[0]; return yytext[0]; }

{Escape_Token}			{ printf("#char:%s\n", yytext); }
{Escape_Token2}			{ printf("#char:%s\n", yytext); }
{Escape_Token3}			{ printf("#char:%s\n", yytext); }
{Escape_Token4}			{ printf("#char:%s\n", yytext); }



{Integer_Token}			{ yylval.token = atoi(yytext); return NUM; }




{Char_Token}			{ printf("#char:%s\n", yytext); }
{String_Token}			{ printf("#string:%s\n", yytext);}
{Empty_Token}			{}
{Comment_Token} 		{}
\/\*					{ cmt = 1; BEGIN CMT; }

<CMT>\*\/				{ cmt = 0; BEGIN 0;}
<CMT>.					{}
<CMT>{EOL_Token}		{ yyless(0); BEGIN 0; }
			

%%