%{
#include <stdio.h>
/*
#define KEYWORD 0
#define MACRO   1
#define ID      2
#define OP      3
#define PUNC    4
#define FLOAT   5
#define INTEGER 6
#define CHAR    7
#define STRING  8
*/
int lines=0, length, size, src=1, tkn=1;
int* pragma;
char* line_text;
char* tkn_text;

int idx;
char type[9][8]={"key","macro","id","op","punc","float","integer","char","string"};


%}

hex         [0123456789abcdef]
octal       [01234567]

keyword_1   ("break"|"return"|"long"|"switch"|"char"|"case"|"continue"|"const"|"default"|(do(uble)?))
keyword_2   (((voi)|((un)?signe))d)|(s("hor"|"truc")t)|(("whil"|"els")e)|(f("or"|"loat"))|(i("nt"|f))

keyword     ({keyword_1}|{keyword_2})   
macro       ((("CHAR"|"INT"_)?M(AX)|(IN))|"NULL")|(__"COUNTER"|"LINE"__)
identifier  (_|[a-zA-Z])[_a-zA-Z0-9]*
op          ((\+\+?)|(--?)|(\*)|(\/)|(%)|(\<=?)|(\>=?)|(==?)|(!=?)|(&&?)|(\|\|?))
punc        [:;,\.\[\]\(\)\{\}]
integer     (\+|-)?(0|[1-9][0-9]*)
float       ((\+|-)?(0|[1-9][0-9]*)?\.[0-9]*)
string      (\"(.|"\t")*\")
char        ('.')|('\\[abefnrtv\'\"\?\\]')|('\\({octal}|(x{hex}+)|(u{hex}{4,4})|(U{hex}{8,8}))')

empty       (" "|("\t"))

pragma_src  ("#pragma"(" "|"\t")+"source"(" "|"\t")+)
pragma_tkn  ("#pragma"(" "|"\t")+"token"(" "|"\t")+)
switch      ("on"|"off")

single_comment      (\/\/(.)*)                
mul_comment_start   (\/\*)
mul_comment_end     ((.)*"*/")

token      ((.|"\n")?)

%x LINE
%x TOKEN
%x PRAGMA
%x COMMENT
%x COMMENT_LINE

%%


(.){0,298}\n                                    { line_text=yytext; yyless(0); BEGIN LINE; }
<COMMENT_LINE>(.){0,298}\n                   { line_text=yytext; yyless(0); BEGIN COMMENT; }

<LINE>{pragma_src}                                            { pragma=&src; BEGIN PRAGMA; }
<LINE>{pragma_tkn}                                            { pragma=&tkn; BEGIN PRAGMA; }

<PRAGMA>{switch}                                 { *pragma=(*(yytext+1)=='n'); BEGIN LINE; }

<LINE>\n                             { if(src) printf("%d:%s",++lines,line_text); BEGIN 0; }
<COMMENT>\n               { if(src) printf("%d:%s",++lines,line_text); BEGIN COMMENT_LINE; }

<TOKEN>{token}          {yyless(0);if(tkn)printf("#%s:%s\n",type[idx],tkn_text);BEGIN LINE;}

<LINE>{keyword}                                     { idx=0; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{macro}                                       { idx=1; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{identifier}                                  { idx=2; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{op}                                          { idx=3; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{punc}                                        { idx=4; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{float}                                       { idx=5; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{integer}                                     { idx=6; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{char}                                        { idx=7; tkn_text=yytext; BEGIN TOKEN; }
<LINE>{string}                                      { idx=8; tkn_text=yytext; BEGIN TOKEN; }

<LINE>{empty}|{single_comment}                      { ; }

<LINE>{mul_comment_start}                           { BEGIN COMMENT; }

<COMMENT>{mul_comment_end}                          { BEGIN LINE; }
<COMMENT>.                                          { ; }

%%

int main(int argc, char* argv[]) { yylex(); return 0; }

int yywrap() { return 1; /* eof */ }