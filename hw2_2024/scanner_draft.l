%{

#include "y.tab.h"

int num_lines  = 0;
int num_chars = 0;

char* line_content;
int cmt = 0;

int Hashfunc(char* yytext);
%}

Keyword_Token	("for"|"do"|"while"|"break"|"continue"|"if"|"else"|"return"|"struct"|"switch"|"case"|"default")

Type_Token      "const"|"signed"|"unsigned"|"long long"|"long"|"short"|"int"|"float"|"double"|"void"

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

{Keyword_Token}	{ printf("#key:%s\n", yytext); }
{Macro_Token}	{ printf("#macro:%s\n",yytext); }


"const"         { yylval.token=Hashfunc(yytext); return CONST; }
"signed"        { yylval.token=Hashfunc(yytext); return SIGN; }
"unsigned"      { yylval.token=Hashfunc(yytext); return USIGN; }
"long long"     { yylval.token=Hashfunc(yytext); return LLONG; }
"long"          { yylval.token=Hashfunc(yytext); return LONG; }
"short"         { yylval.token=Hashfunc(yytext); return SHRT; }
"int"           { yylval.token=Hashfunc(yytext); return INT; }
"float"         { yylval.token=Hashfunc(yytext); return FLOAT; }
"double"        { yylval.token=Hashfunc(yytext); return DOUBLE; }
"void"          { yylval.token=Hashfunc(yytext); return VOID; }

{Identi_Token}  { yylval.charv=yytext; printf("ok"); return ID; }

{Float_Token}	{ yylval.token = atoi(yytext); return NUM;  }


"="		{  yylval.charv = yytext; return '='; }


{Punc_Token}			{ yylval.opera=yytext; return yytext[0]; }

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

int Hashfunc(char* yytext){
    /*
    "const" "signed" "unsigned" "long long" "long" "short" "int" "float" "double" "void" "char"
    0       1        2          3           4      5        6     7         8       9       10
    1000    100     200         10          20      30      1     2       3         4       5
    */

        if(!strcmp(yytext,"const")){
            return 1000;
        }else if(!strcmp(yytext,"signed")){
            return 100;
        }else if(!strcmp(yytext,"unsigned")){
            return 200;
        }else if(!strcmp(yytext,"long long")){
            return 10;
        }else if(!strcmp(yytext,"long")){
            return 20;
        }else if(!strcmp(yytext,"short")){
            return 30;
        }else if(!strcmp(yytext,"int")){
            return 1;
        }else if(!strcmp(yytext,"float")){
            return 2;
        }else if(!strcmp(yytext,"double")){
            return 3;
        }else if(!strcmp(yytext,"void")){
            return 4;
        }else if(!strcmp(yytext,"char")){
            return 5;
        }else return -1;
}