%{

#include <stdio.h>

int lines = 0;
int chars = 0;
int source = 1;
int token = 1;
char* line_content;
int line_size;
%}

hex     [0123456789abcdef]
octal   [01234567]

%x LINE_PARSE
%x KEYWORD

%% 


(.)*\n                                                  { line_content = yytext; yyless(0); BEGIN LINE_PARSE; }
(.){1,299}                                              { line_content = yytext; yyless(0); BEGIN LINE_PARSE; }

<LINE_PARSE>"#pragma"(" "|"\t")+"source"(" "|"\t")+"on"                         { source = 1; }
<LINE_PARSE>"#pragma"(" "|"\t")+"source"(" "|"\t")+"off"                        { source = 0; }
<LINE_PARSE>"#pragma"(" "|"\t")+"token"(" "|"\t")+"on"                          { token  = 1; }
<LINE_PARSE>"#pragma"(" "|"\t")+"token"(" "|"\t")+"off"                         { token  = 0; }

<LINE_PARSE>\n                                          { ++lines; if(source) printf("%d:%s",lines,line_content); BEGIN 0; }


<LINE_PARSE>((("break"|"return")|"long")|"switch")      { if(token) printf("#key:%s\n", yytext); }                       
<LINE_PARSE>c(("har"|"ase")|("on"("st"|"tinue")))       { if(token) printf("#key:%s\n", yytext); }                   
<LINE_PARSE>d((o(uble)?)|"efault")                      { if(token) printf("#key:%s\n", yytext); }                   
<LINE_PARSE>("whil"|"els")e                             { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>f("or"|"loat")                              { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>i("nt"|f)                                   { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>((voi)|((un)?signe))d                       { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>s("hor"|"truc")t                            { if(token) printf("#key:%s\n", yytext); }

<LINE_PARSE>((("CHAR"|"INT"_)?M(AX)|(IN))|"NULL")       { if(token) printf("#macro:%s\n",yytext);}
<LINE_PARSE>(__"COUNTER"|"LINE"__)                      { if(token) printf("#macro:%s\n",yytext);}

<LINE_PARSE>(_|[a-zA-Z])[_a-zA-Z0-9]*                   { if(token) printf("#id:%s\n",  yytext); }

<LINE_PARSE>" "                                         { ; }

<LINE_PARSE>(((\/\/)|\/\*)|\*\/).*/"\n"                 { ; }
<LINE_PARSE>(((\/\/)|\/\*)|\*\/).*                      { ; }

<LINE_PARSE>\+\+?                                       { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>--?                                         { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>\*                                          { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>\/                                          { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>%                                           { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>\<=?                                        { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>\>=?                                        { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>==?                                         { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>!=?                                         { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>&&?                                         { if(token) printf("#op:%s\n",  yytext); }
<LINE_PARSE>\|\|?                                       { if(token) printf("#op:%s\n",  yytext); }

<LINE_PARSE>[:;,\.\[\]\(\)\{\}]                         { if(token) printf("#punc:%s\n",yytext); }

<LINE_PARSE>(\+|-)?(0|[1-9][0-9]*)\.[0-9]*              { if(token) printf("#float:%s\n",yytext); }
<LINE_PARSE>(\+|-)?\.[0-9]+                             { if(token) printf("#float:%s\n",yytext); }

<LINE_PARSE>(\+|-)?(0|[1-9][0-9]*)                      { if(token) printf("#integer:%s\n",yytext); }

<LINE_PARSE>('.')|('\\[abefnrtv\'\"\?\\]')              { if(token) printf("#char:%s\n", yytext); }
<LINE_PARSE>'\\{octal}|(x{hex}+)'                       { if(token) printf("#char:%s\n", yytext); }
<LINE_PARSE>'\\(u{hex}{4,4})|(U{hex}{8,8})'             { if(token) printf("#char:%s\n", yytext); }

<LINE_PARSE>\"(.|"\t")*("\n")?\"                        { if(token) printf("#string:%s\n", yytext); }


%%

int main(int argc, char* argv[]) { yylex();  return 0; }


int yywrap() { return 1; /* eof */ }