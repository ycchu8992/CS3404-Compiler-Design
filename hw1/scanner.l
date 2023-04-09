%{

#include <stdio.h>
#include <stdlib.h>

int lines = 0;
int source = 1;
int token = 1;
char* context;

%}


%x LINE_PARSE

%% 

(.)*\n                                                  { context = yytext; yyless(0); BEGIN LINE_PARSE; }

<LINE_PARSE>"#pragma source on"                         { source = 1; }
<LINE_PARSE>"#pragma source off"                        { source = 0; }
<LINE_PARSE>"#pragma token on"                          { token  = 1; }
<LINE_PARSE>"#pragma token off"                         { token  = 0; }

<LINE_PARSE>\n                                          { ++lines; if(source) printf("%d:%s\n",lines,context); BEGIN 0; }

<LINE_PARSE>((("break"|"return")|"long")|"switch")      { if(token) printf("#key:%s\n", yytext); }                       
<LINE_PARSE>c("har"|"ase"|("on"("st"|"tinue")))         { if(token) printf("#key:%s\n", yytext); }                   
<LINE_PARSE>d((o(uble)?)|(efault))                      { if(token) printf("#key:%s\n", yytext); }                   
<LINE_PARSE>("whil"|"els")e                             { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>f("or"|"loat")                              { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>i("nt"|f)                                   { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>((voi)|((un)?signe))d                       { if(token) printf("#key:%s\n", yytext); }
<LINE_PARSE>s("hor"|"truc")t                            { if(token) printf("#key:%s\n", yytext); }

<LINE_PARSE>((("CHAR"|"INT"_)?M(AX)|(IN))|"NULL")|(__"COUNTER"|"LINE"__)  { if(token) printf("#macro:%s\n", yytext); }

<LINE_PARSE>(_[a-zA-Z]+)|([a-zA-Z]*)                    { if(token) printf("#id:%s\n",  yytext); }

<LINE_PARSE>" "                                         { ; }

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

<LINE_PARSE>[:;,.\[\]\(\)\{\}]                          { if(token) printf("#punc:%s\n",yytext); }

%%

int main(int argc, char* argv[]) { yylex();  return 0; }


int yywrap() { return 1; /* eof */ }