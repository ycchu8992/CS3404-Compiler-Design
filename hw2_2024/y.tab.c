/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* const type_table[11] = {"const", "signed", "unsigned", "longlong", "long", "short", "int", "float", "double", "void", "char"};
char* const keyword_table[12] = { "for", "do", "while", "break", "continue", "if", "else", "return", "struct", "switch", "case", "default" };
extern int tkn;

char* check_id_exist(char* tok);
char* install_id(char* tok);
char* reduce_nonterminal(char* r1);
char* reduce_terminal(char* r1);
char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal(char* r1, char* r2);
char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_terminal(char* r1, char* r2);
char* reduce_nonterminal_terminal(char* r1, char* r2);
char* reduce_terminal_nonterminal(char* r1, char* r2);
char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3);
char* reduce_nonterminal_nonterminal_terminal(char* r1, char* r2, char* r3);
char* reduce_for_stmt(char* r1);

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

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 41 "parser.y"
typedef union YYSTYPE{
    int token;
    char* charv;
    struct symbol *sym;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 75 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define NUM 257
#define ID 258
#define CONST 259
#define SIGN 260
#define USIGN 261
#define LONG 262
#define LLONG 263
#define SHRT 264
#define FLOAT 265
#define DOUBLE 266
#define VOID 267
#define CHAR 268
#define INT 269
#define FOR 270
#define DO 271
#define WHILE 272
#define BREAK 273
#define CONTINUE 274
#define IF 275
#define ELSE 276
#define RETURN 277
#define STRUCT 278
#define SWITCH 279
#define CASE 280
#define DEFALUT 281
#define SEMICOLON 282
#define ENTER 283
#define COMMA 284
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   19,   19,   40,   40,   40,   22,   22,   17,   20,
   18,   21,   25,   25,   25,   25,   25,   25,   25,   25,
   25,    6,    7,    8,    9,   10,   11,   12,   12,   12,
   12,   13,   13,   14,   14,   41,   41,   27,   28,   23,
   26,   39,   39,   24,   24,   24,   24,   42,   43,   44,
   44,   37,   37,   38,   38,   36,   30,   30,   35,   31,
   31,   31,   34,   32,   32,   32,   32,   33,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    3,    3,    4,    4,    4,    4,    5,    5,    5,   15,
   15,   15,   15,   16,   29,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    1,    2,    3,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    3,    2,    2,    3,    3,    3,    3,    2,
    2,    3,    2,    2,    1,    2,    1,    3,    2,    2,
    3,    3,    2,    2,    2,    1,    1,    2,    2,    2,
    2,    3,    2,    3,    1,    2,    3,    1,    2,    2,
    3,    1,    3,    1,    3,    3,    1,    3,    2,    1,
    1,    3,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    2,    1,    1,    1,    1,    1,    1,    3,
    2,    2,    3,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   81,   82,   88,   87,   89,   78,   79,   80,   85,
   86,    0,    0,    0,    0,   77,    0,    7,    5,    1,
    8,    6,    4,    0,    0,   74,    0,    0,    9,    0,
    0,    0,   73,   75,   83,    0,    0,    2,   72,    0,
    0,   92,    0,   59,    0,   91,    0,   10,    0,   53,
    0,    0,    0,    0,   11,   12,   95,   94,    0,    0,
   93,    0,   60,   90,    0,   57,   56,    0,   52,    0,
    0,    0,    0,    0,    0,    0,   43,    0,   19,   20,
    0,    0,   21,    0,   15,    0,    0,    0,    0,   14,
   13,   17,   18,   16,   68,    0,   61,   54,   25,    0,
   24,   48,   49,    0,   51,   50,    0,    0,   22,    0,
   45,   42,   44,    0,   36,   40,    0,    0,    0,    0,
   38,    0,   26,   23,   39,    0,   63,    0,   41,    0,
    0,    0,   66,   65,    0,    0,    0,    0,   27,   28,
    0,   34,   29,   32,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  286,  287,  288,  289,  290,  291,  303,  304,  305,
  306,  307,  308,  322,  326,   42,  288,  258,  301,  302,
  316,  321,   42,  290,  269,   40,  323,  305,   42,   61,
   91,  282,  284,  317,  319,  282,  284,  282,  284,   41,
  287,  322,  324,  123,  282,  325,  257,  315,  315,  258,
  301,   61,  317,  301,  258,  316,  258,  284,   41,  271,
  272,  273,  274,  275,  277,  279,  125,  287,  292,  293,
  294,  295,  296,  308,  309,  310,  311,  313,  315,  325,
  327,  328,  329,  330,   93,  123,  320,  324,  311,   40,
  312,  282,  282,  312,  282,  309,  312,  258,  311,  294,
  310,  125,  310,  276,  314,  282,  315,  318,  320,  315,
  325,  123,  297,  282,  325,  284,  125,  284,   41,  280,
  281,  298,  318,  318,  299,  315,   58,  300,  125,  298,
   58,  311,  298,  311,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         12,
   78,   14,   15,   16,   17,   79,   80,   81,   82,   83,
  123,  132,  135,  138,   29,   30,   18,   19,   20,   21,
   22,   84,   85,   86,   87,  101,   88,  115,   89,   31,
   44,  118,   45,  119,   32,   24,   37,   53,   90,   25,
   91,   92,   93,   94,
};
static const YYINT yysindex[] = {                      -165,
  -31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -237,   -9, -219,    0, -232,    0,    0,    0,
    0,    0,    0,    7, -165,    0,   -2,  -43,    0, -253,
 -230, -227,    0,    0,    0,  -41, -122,    0,    0, -196,
 -196,    0, -194,    0,  -49,    0, -194,    0, -193,    0,
 -192, -222,   26,  -93,    0,    0,    0,    0,  -25,  -42,
    0,  -54,    0,    0,  -20,    0,    0, -165,    0,  -12,
   30, -210, -208,   30, -244,   30,    0, -182,    0,    0,
  -12, -191,    0,  -72,    0,  -46,  -72, -190, -202,    0,
    0,    0,    0,    0,    0, -121,    0,    0,    0, -196,
    0,    0,    0,  -40,    0,    0,  -39,  -43,    0, -200,
    0,    0,    0,  -40,    0,    0, -197,  -35, -179,   47,
    0, -265,    0,    0,    0, -121,    0, -121,    0, -196,
   34,  -19,    0,    0, -265,   49,  -12, -265,    0,    0,
  -12,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -150,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -149,  -15,    0,  -14,    0,    0,    0,
    0,    0,    0,    0,  110,    0, -146,   73,    0,    0,
    0, -168,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -248,    0,    0,    0,    0,    0,
    0,   74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -8,    0,    0,   -7, -118,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -6,    0,   -5,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -4,    0,  -71,   -3,    0,    0,
  -69,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   10,  115,    0,  108,    0,    0,    0,   42,    0,    0,
    0, -113,    0,    0,  -23,    0,    0,    0,  100,    0,
    0,   14,   51,  -61,  -64,  -21,    0,    0,  -37,   78,
   83,  -68,    0,   67,    0,  -27,    0,   62,  -29,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 267
static const YYINT yytable[] = {                         50,
   54,   96,   58,   59,   37,   99,   37,   56,   52,   13,
   26,   62,   57,   23,  130,  131,  109,   40,   40,   61,
   28,  140,  111,   64,  143,  113,   76,   84,   46,   54,
   47,   77,   33,   62,   13,   62,   35,  105,   23,   39,
   52,   41,    4,    5,    6,   51,   36,   41,   10,   11,
   54,   48,  104,   35,  107,   33,   49,  133,  117,  134,
   57,   68,  120,   60,   65,   67,   69,   95,   96,  100,
   41,  102,  142,  103,  121,  108,  144,   51,  112,  116,
   71,  124,   54,  122,  125,  114,  126,  129,  117,  127,
  117,  137,  136,    1,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,  128,  139,  141,   71,   70,    3,
   54,   69,   56,   58,   55,   27,   47,   46,   67,   64,
   30,   31,   34,  110,   38,  106,   66,   63,   97,   98,
    0,    0,    0,    0,    0,   57,    0,    0,   37,    0,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,    0,   37,   37,   37,   37,   37,    0,   37,   55,
   37,   37,   37,   57,    0,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,    0,   70,   71,   72,
   73,   74,    0,   75,   57,   76,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,    0,   70,   71,
   72,   73,   74,    0,   75,    0,   76,    0,   35,   35,
   33,   33,    0,    0,    0,    0,    0,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   42,   42,
   43,   43,   76,   84,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   70,   71,
   72,   73,   74,    0,   75,    0,   76,
};
static const YYINT yycheck[] = {                         41,
  123,  123,   40,   41,  123,   70,  125,   37,   36,    0,
   42,   61,  257,    0,  280,  281,   81,   61,   61,   43,
  258,  135,   84,   47,  138,   87,   42,   42,  282,  123,
  284,  125,   42,  282,   25,  284,  269,  282,   25,   42,
   68,   91,  262,  263,  264,   36,   40,   91,  268,  269,
  123,  282,   74,  125,   76,  125,  284,  126,   96,  128,
  257,  284,  100,  258,  258,  258,   41,   93,  123,   40,
   91,  282,  137,  282,  104,  258,  141,   68,  125,  282,
  272,  282,  123,  123,  114,  276,  284,   41,  126,  125,
  128,   58,  130,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,  269,  284,  125,   58,  258,  258,    0,
  123,  258,   40,  282,   41,    1,  125,  125,  125,  125,
  125,  125,   15,   82,   25,   75,   49,   45,   62,   68,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,  257,   -1,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,   -1,  271,  272,  273,  274,  275,   -1,  277,  282,
  279,  280,  281,  257,   -1,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,   -1,  271,  272,  273,
  274,  275,   -1,  277,  257,  279,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,   -1,  271,  272,
  273,  274,  275,   -1,  277,   -1,  279,   -1,  280,  281,
  280,  281,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  282,  282,
  284,  284,  258,  258,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  271,  272,
  273,  274,  275,   -1,  277,   -1,  279,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 331
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,"'='",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"error","NUM","ID","CONST","SIGN","USIGN","LONG","LLONG","SHRT","FLOAT",
"DOUBLE","VOID","CHAR","INT","FOR","DO","WHILE","BREAK","CONTINUE","IF","ELSE",
"RETURN","STRUCT","SWITCH","CASE","DEFALUT","SEMICOLON","ENTER","COMMA",
"$accept","init","type_decl","type_layer","sign_usgn","int_char","long_shrt",
"while_stmt","do_while_stmt","while_tag","do_tag","switch_stmt","switch_clause",
"switch_content","case_expr","default_expr","ident","var_init","scalar_decl",
"func_decl","program","array_decl","func_def","var_decl","expr_stmt",
"compound_stmt_content","stmt","condition","if_stmt","else_stmt","expr",
"arr_ident","arr_tag","arr_content","box","arr_cnt_fmt","arr_id","type_ident",
"parameter_info","parameters","compound_stmt","section","if_else_stmt",
"break_stmt","continue_stmt","return_stmt","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : init",
"init : program",
"program : section program",
"program : section",
"section : var_decl",
"section : func_decl",
"section : func_def",
"var_decl : scalar_decl",
"var_decl : array_decl",
"scalar_decl : type_decl ident",
"array_decl : type_decl arr_ident SEMICOLON",
"func_decl : type_ident parameter_info SEMICOLON",
"func_def : type_ident parameter_info compound_stmt",
"stmt : if_else_stmt",
"stmt : compound_stmt",
"stmt : expr_stmt",
"stmt : return_stmt",
"stmt : break_stmt",
"stmt : continue_stmt",
"stmt : while_stmt",
"stmt : do_while_stmt",
"stmt : switch_stmt",
"while_stmt : while_tag stmt",
"do_while_stmt : do_tag while_tag SEMICOLON",
"while_tag : WHILE condition",
"do_tag : DO stmt",
"switch_stmt : SWITCH condition switch_clause",
"switch_clause : '{' switch_content '}'",
"switch_content : CASE case_expr switch_content",
"switch_content : DEFALUT default_expr switch_content",
"switch_content : CASE case_expr",
"switch_content : DEFALUT default_expr",
"case_expr : expr ':' stmt",
"case_expr : expr ':'",
"default_expr : ':' stmt",
"default_expr : ':'",
"if_else_stmt : if_stmt else_stmt",
"if_else_stmt : if_stmt",
"if_stmt : IF condition compound_stmt",
"else_stmt : ELSE compound_stmt",
"expr_stmt : expr SEMICOLON",
"condition : '(' expr ')'",
"compound_stmt : '{' compound_stmt_content '}'",
"compound_stmt : '{' '}'",
"compound_stmt_content : stmt compound_stmt_content",
"compound_stmt_content : var_decl compound_stmt_content",
"compound_stmt_content : stmt",
"compound_stmt_content : var_decl",
"break_stmt : BREAK SEMICOLON",
"continue_stmt : CONTINUE SEMICOLON",
"return_stmt : RETURN expr_stmt",
"return_stmt : RETURN SEMICOLON",
"parameter_info : '(' parameters ')'",
"parameter_info : '(' ')'",
"parameters : type_ident COMMA parameters",
"parameters : type_ident",
"type_ident : type_decl ID",
"arr_ident : arr_id COMMA arr_ident",
"arr_ident : arr_id",
"arr_id : ID arr_tag",
"arr_tag : box arr_tag",
"arr_tag : box '=' arr_cnt_fmt",
"arr_tag : box",
"arr_cnt_fmt : '{' arr_content '}'",
"arr_content : arr_cnt_fmt",
"arr_content : arr_cnt_fmt COMMA arr_content",
"arr_content : expr COMMA arr_content",
"arr_content : expr",
"box : '[' expr ']'",
"type_decl : CONST type_layer",
"type_decl : type_layer",
"type_decl : CONST",
"type_decl : CONST type_layer '*'",
"type_decl : type_layer '*'",
"type_decl : CONST '*'",
"type_layer : sign_usgn int_char",
"type_layer : sign_usgn",
"type_layer : int_char",
"type_layer : FLOAT",
"type_layer : DOUBLE",
"type_layer : VOID",
"sign_usgn : SIGN",
"sign_usgn : USIGN",
"int_char : long_shrt INT",
"int_char : long_shrt",
"int_char : CHAR",
"int_char : INT",
"long_shrt : LLONG",
"long_shrt : LONG",
"long_shrt : SHRT",
"ident : var_init COMMA ident",
"ident : var_init SEMICOLON",
"ident : ID SEMICOLON",
"ident : ID COMMA ident",
"var_init : ID '=' expr",
"expr : NUM",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 298 "parser.y"

int yylex(void);

int main(int argc, char* argv[]) {
    if(argc ==2 && !strcmp(argv[1],"-d")) yydebug = tkn = 1;
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

char* reduce_nonterminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    free(r1);
    if(tkn) printf("%s", buffer);
    return buffer;                           
}

char* reduce_terminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    if(tkn) printf("%s", buffer);
    return buffer;                           
}

char* reduce_terminal_nonterminal_terminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    free(r2);
    return buffer;
}

char* reduce_nonterminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r3);
    return buffer;
}

char* reduce_terminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    return buffer;
}

char* reduce_nonterminal_terminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r1);
    return buffer;
}

char* reduce_terminal_nonterminal(char* r1, char* r2){
    size_t buffer_size = strlen(r1) + strlen(r2) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    free(r2);
    return buffer;
}

char* reduce_terminal_terminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r3);
    return buffer;
}

char* reduce_terminal_nonterminal_nonterminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r2);
    free(r3);
    return buffer;    
}

char* reduce_nonterminal_nonterminal_terminal(char* r1, char* r2, char* r3){
    size_t buffer_size = strlen(r1) + strlen(r2) + strlen(r3) + 1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer, r1);
    strcat(buffer, r2);
    strcat(buffer, r3);
    free(r1);
    free(r2);
    return buffer;    
}

char* reduce_for_stmt(char* r1){
    size_t l = strlen("<stmt>");
    size_t n1 = strlen(r1);
    size_t r = strlen("</stmt>");
    char* buffer = (char*)malloc(l+r+n1+1);
    strcpy(buffer,"<stmt>");
    strcat(buffer,r1);
    strcat(buffer,"</stmt>");
    free(r1);   
    return buffer;
} 
/*





for_stmt: FOR for_condition stmt

            | for_stmt

            */
#line 776 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 60 "parser.y"
	{
                                size_t n1 = strlen(yystack.l_mark[0].charv);
                                char* buffer = (char*)malloc(n1+1);
                                strcpy(buffer,yystack.l_mark[0].charv);
                                printf("%s", buffer);   
                                free(yystack.l_mark[0].charv);
                                free(buffer);
                            }
#line 1456 "y.tab.c"
break;
case 2:
#line 69 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1461 "y.tab.c"
break;
case 3:
#line 70 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1466 "y.tab.c"
break;
case 4:
#line 73 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1471 "y.tab.c"
break;
case 5:
#line 74 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1476 "y.tab.c"
break;
case 6:
#line 75 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1481 "y.tab.c"
break;
case 7:
#line 78 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1486 "y.tab.c"
break;
case 8:
#line 79 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1491 "y.tab.c"
break;
case 9:
#line 82 "parser.y"
	{
                                    size_t l = strlen("<scalar_decl>");
                                    size_t n1 = strlen(yystack.l_mark[-1].charv);
                                    size_t n2 = strlen(yystack.l_mark[0].charv);
                                    size_t r = strlen("</scalar_decl>");
                                    char* buffer = (char*)malloc(l+r+n1+n2+1);
                                    strcpy(buffer,"<scalar_decl>");
                                    strcat(buffer,yystack.l_mark[-1].charv);
                                    strcat(buffer,yystack.l_mark[0].charv); 
                                    strcat(buffer,"</scalar_decl>");                                    
                                    yyval.charv = buffer;
                                    free(yystack.l_mark[-1].charv);
                                    free(yystack.l_mark[0].charv);
                                }
#line 1509 "y.tab.c"
break;
case 10:
#line 97 "parser.y"
	{
                                                size_t l = strlen("<array_decl>");
                                                size_t n1 = strlen(yystack.l_mark[-2].charv);
                                                size_t n2 = strlen(yystack.l_mark[-1].charv);
                                                size_t n3 = strlen(yystack.l_mark[0].charv);
                                                size_t r = strlen("</array_decl>");
                                                char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                strcpy(buffer,"<array_decl>");
                                                strcat(buffer,yystack.l_mark[-2].charv);
                                                strcat(buffer,yystack.l_mark[-1].charv);
                                                strcat(buffer,yystack.l_mark[0].charv);
                                                strcat(buffer,"</array_decl>");
                                                yyval.charv = buffer;
                                                free(yystack.l_mark[-2].charv);
                                                free(yystack.l_mark[-1].charv);
                                            }
#line 1529 "y.tab.c"
break;
case 11:
#line 115 "parser.y"
	{
                                                    size_t l = strlen("<func_decl>");
                                                    size_t n1 = strlen(yystack.l_mark[-2].charv);
                                                    size_t n2 = strlen(yystack.l_mark[-1].charv);
                                                    size_t n3 = strlen(yystack.l_mark[0].charv);
                                                    size_t r = strlen("</func_decl>");
                                                    char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                    strcpy(buffer,"<func_decl>");
                                                    strcat(buffer,yystack.l_mark[-2].charv);
                                                    strcat(buffer,yystack.l_mark[-1].charv);
                                                    strcat(buffer,yystack.l_mark[0].charv);
                                                    strcat(buffer,"</func_decl>");
                                                    yyval.charv = buffer;
                                                    if(tkn) printf("%s",buffer);
                                                    free(yystack.l_mark[-2].charv);
                                                    free(yystack.l_mark[-1].charv);
                                                }
#line 1550 "y.tab.c"
break;
case 12:
#line 133 "parser.y"
	{
                                                        size_t l = strlen("<func_def>");
                                                        size_t n1 = strlen(yystack.l_mark[-2].charv);
                                                        size_t n2 = strlen(yystack.l_mark[-1].charv);
                                                        size_t n3 = strlen(yystack.l_mark[0].charv);
                                                        size_t r = strlen("</func_def>");
                                                        char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
                                                        strcpy(buffer,"<func_def>");
                                                        strcat(buffer,yystack.l_mark[-2].charv);
                                                        strcat(buffer,yystack.l_mark[-1].charv);
                                                        strcat(buffer,yystack.l_mark[0].charv);
                                                        strcat(buffer,"</func_def>");
                                                        yyval.charv = buffer;
                                                        if(tkn) printf("%s",buffer);
                                                        free(yystack.l_mark[-2].charv);
                                                        free(yystack.l_mark[-1].charv);
                                                        free(yystack.l_mark[0].charv);
                                                    }
#line 1572 "y.tab.c"
break;
case 13:
#line 153 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1577 "y.tab.c"
break;
case 14:
#line 154 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1582 "y.tab.c"
break;
case 15:
#line 155 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1587 "y.tab.c"
break;
case 16:
#line 156 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1592 "y.tab.c"
break;
case 17:
#line 157 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1597 "y.tab.c"
break;
case 18:
#line 158 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1602 "y.tab.c"
break;
case 19:
#line 159 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1607 "y.tab.c"
break;
case 20:
#line 160 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1612 "y.tab.c"
break;
case 21:
#line 161 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1617 "y.tab.c"
break;
case 22:
#line 164 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1622 "y.tab.c"
break;
case 23:
#line 166 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal_terminal(yystack.l_mark[-2].charv,yystack.l_mark[-1].charv,yystack.l_mark[0].charv);  }
#line 1627 "y.tab.c"
break;
case 24:
#line 168 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1632 "y.tab.c"
break;
case 25:
#line 170 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1637 "y.tab.c"
break;
case 26:
#line 172 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1642 "y.tab.c"
break;
case 27:
#line 174 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1647 "y.tab.c"
break;
case 28:
#line 176 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1652 "y.tab.c"
break;
case 29:
#line 177 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1657 "y.tab.c"
break;
case 30:
#line 178 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1662 "y.tab.c"
break;
case 31:
#line 179 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1667 "y.tab.c"
break;
case 32:
#line 182 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1672 "y.tab.c"
break;
case 33:
#line 183 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1677 "y.tab.c"
break;
case 34:
#line 186 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1682 "y.tab.c"
break;
case 35:
#line 187 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);    }
#line 1687 "y.tab.c"
break;
case 36:
#line 189 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1692 "y.tab.c"
break;
case 37:
#line 190 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1697 "y.tab.c"
break;
case 38:
#line 193 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1702 "y.tab.c"
break;
case 39:
#line 195 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1707 "y.tab.c"
break;
case 40:
#line 197 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1712 "y.tab.c"
break;
case 41:
#line 199 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1717 "y.tab.c"
break;
case 42:
#line 201 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1722 "y.tab.c"
break;
case 43:
#line 202 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1727 "y.tab.c"
break;
case 44:
#line 205 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1732 "y.tab.c"
break;
case 45:
#line 206 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1737 "y.tab.c"
break;
case 46:
#line 207 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1742 "y.tab.c"
break;
case 47:
#line 208 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1747 "y.tab.c"
break;
case 48:
#line 211 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1752 "y.tab.c"
break;
case 49:
#line 212 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1757 "y.tab.c"
break;
case 50:
#line 213 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1762 "y.tab.c"
break;
case 51:
#line 214 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1767 "y.tab.c"
break;
case 52:
#line 216 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1772 "y.tab.c"
break;
case 53:
#line 217 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1777 "y.tab.c"
break;
case 54:
#line 220 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1782 "y.tab.c"
break;
case 55:
#line 221 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1787 "y.tab.c"
break;
case 56:
#line 224 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1792 "y.tab.c"
break;
case 57:
#line 226 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1797 "y.tab.c"
break;
case 58:
#line 227 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1802 "y.tab.c"
break;
case 59:
#line 230 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1807 "y.tab.c"
break;
case 60:
#line 232 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1812 "y.tab.c"
break;
case 61:
#line 233 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1817 "y.tab.c"
break;
case 62:
#line 234 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1822 "y.tab.c"
break;
case 63:
#line 237 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1827 "y.tab.c"
break;
case 64:
#line 239 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1832 "y.tab.c"
break;
case 65:
#line 240 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1837 "y.tab.c"
break;
case 66:
#line 241 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1842 "y.tab.c"
break;
case 67:
#line 242 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1847 "y.tab.c"
break;
case 68:
#line 245 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1852 "y.tab.c"
break;
case 69:
#line 247 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1857 "y.tab.c"
break;
case 70:
#line 248 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1862 "y.tab.c"
break;
case 71:
#line 249 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1867 "y.tab.c"
break;
case 72:
#line 250 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(type_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1872 "y.tab.c"
break;
case 73:
#line 251 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1877 "y.tab.c"
break;
case 74:
#line 252 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1882 "y.tab.c"
break;
case 75:
#line 255 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1887 "y.tab.c"
break;
case 76:
#line 256 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1892 "y.tab.c"
break;
case 77:
#line 257 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1897 "y.tab.c"
break;
case 78:
#line 258 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1902 "y.tab.c"
break;
case 79:
#line 259 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1907 "y.tab.c"
break;
case 80:
#line 260 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1912 "y.tab.c"
break;
case 81:
#line 263 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1917 "y.tab.c"
break;
case 82:
#line 264 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1922 "y.tab.c"
break;
case 83:
#line 267 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, type_table[yystack.l_mark[0].token]);   }
#line 1927 "y.tab.c"
break;
case 84:
#line 268 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1932 "y.tab.c"
break;
case 85:
#line 269 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1937 "y.tab.c"
break;
case 86:
#line 270 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1942 "y.tab.c"
break;
case 87:
#line 273 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1947 "y.tab.c"
break;
case 88:
#line 274 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1952 "y.tab.c"
break;
case 89:
#line 275 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1957 "y.tab.c"
break;
case 90:
#line 278 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1962 "y.tab.c"
break;
case 91:
#line 279 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1967 "y.tab.c"
break;
case 92:
#line 280 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1972 "y.tab.c"
break;
case 93:
#line 281 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1977 "y.tab.c"
break;
case 94:
#line 284 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1982 "y.tab.c"
break;
case 95:
#line 286 "parser.y"
	{ 
                        size_t n1 = strlen("<expr>");
                        size_t n2 = strlen(yystack.l_mark[0].charv);
                        size_t n3 = strlen("</expr>");                      
                        char* num = (char*)malloc(n1+n2+n3+1);
                        strcpy(num,"<expr>");
                        strcat(num,yystack.l_mark[0].charv);
                        strcat(num,"</expr>");
                        yyval.charv = num;
                    }
#line 1996 "y.tab.c"
break;
#line 1998 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
