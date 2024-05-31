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

#define INT_NUM 257
#define FLOAT_NUM 258
#define STRING 259
#define CHARACTER 260
#define NULL_SIGNAL 261
#define ID 262
#define CONST 263
#define SIGN 264
#define USIGN 265
#define LONG 266
#define LLONG 267
#define SHRT 268
#define FLOAT 269
#define DOUBLE 270
#define VOID 271
#define CHAR 272
#define INT 273
#define FOR 274
#define DO 275
#define WHILE 276
#define BREAK 277
#define CONTINUE 278
#define IF 279
#define ELSE 280
#define RETURN 281
#define STRUCT 282
#define SWITCH 283
#define CASE 284
#define DEFALUT 285
#define ENTER 286
#define LEFT_SHIFT 293
#define RIGHT_SHIFT 294
#define DEREF 297
#define UMINUS 298
#define UPLUS 299
#define ADDRESS 300
#define INCREMENT 301
#define DECREMENT 302
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   22,   22,   47,   47,   47,   25,   25,   20,   23,
   21,   24,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,    6,   32,   33,   34,   34,   35,   35,   35,
   35,    7,    8,    9,   10,   11,   12,   12,   12,   12,
   13,   13,   14,   14,   16,   16,   30,   31,   26,   29,
   46,   46,   27,   27,   27,   27,   17,   48,   49,   49,
   44,   44,   45,   45,   43,   37,   37,   42,   38,   38,
   38,   41,   39,   39,   39,   39,   40,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    2,    2,    2,    3,
    3,    4,    4,    4,    4,    5,    5,    5,   18,   18,
   18,   18,   19,   36,   15,   15,   15,   15,   15,   15,
   15,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    1,    1,    1,    2,    3,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    3,    3,    3,    2,    2,    1,    3,
    2,    3,    2,    2,    3,    3,    3,    3,    2,    2,
    3,    2,    2,    1,    2,    1,    3,    2,    2,    3,
    3,    2,    2,    2,    1,    1,    2,    2,    2,    2,
    3,    2,    3,    1,    2,    3,    1,    2,    2,    3,
    1,    3,    1,    3,    3,    1,    3,    2,    1,    1,
    3,    2,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    2,    1,    1,    1,    1,    1,    1,    3,    2,
    2,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,   90,   91,   97,   96,   98,   87,   88,   89,   94,
   95,    0,    0,    0,    0,   86,    0,    7,    5,    1,
    8,    6,    4,    0,    0,   83,    0,    0,    9,    0,
    0,    0,   82,   84,   92,    0,    0,    2,   81,    0,
    0,  101,    0,   68,    0,  100,    0,   10,    0,   62,
    0,    0,    0,    0,   11,   12,  105,  106,  107,  108,
  109,    0,  104,  103,  110,    0,    0,  102,    0,   69,
   99,    0,   66,   65,    0,   61,    0,    0,    0,    0,
    0,    0,    0,    0,   52,    0,   19,   20,    0,    0,
   21,   13,   17,    0,   15,    0,    0,    0,   22,    0,
   14,   18,   16,   77,    0,   70,   63,    0,    0,   34,
    0,   33,   57,   58,    0,   60,   59,    0,    0,   23,
    0,   54,   51,   53,    0,   45,   49,    0,    0,    0,
    0,    0,    0,   24,    0,   47,    0,   35,   32,   48,
    0,   72,    0,    0,   27,    0,   25,    0,   50,    0,
    0,    0,   75,   74,   31,    0,   26,    0,    0,    0,
    0,   36,   30,   37,    0,   43,   38,   41,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  304,  305,  306,  307,  308,  309,  324,  325,  326,
  327,  328,  329,  347,  351,   42,  306,  262,  322,  323,
  341,  346,   42,  308,  273,   40,  348,  326,   42,   61,
   91,   59,   44,  342,  344,   59,   44,   59,   44,   41,
  305,  347,  349,  123,   59,  350,  257,  258,  259,  260,
  261,  262,  319,  340,  346,  340,  262,  322,   61,  342,
  322,  262,  341,  262,   44,   41,  274,  275,  276,  277,
  278,  279,  281,  283,  125,  305,  310,  311,  312,  313,
  314,  320,  321,  329,  330,  331,  332,  334,  336,  340,
  350,  352,  353,   93,  123,  345,  349,   40,  337,  332,
   40,  333,   59,   59,  333,   59,  330,  333,  262,  332,
  312,  331,  125,  331,  280,  335,   59,  340,  343,  345,
   59,  338,  340,  332,  340,  350,  123,  315,   59,  350,
   44,  125,   44,   59,  339,  340,   41,   59,   41,  284,
  285,  316,  343,  343,  340,   59,  339,  317,  340,   58,
  318,  125,  340,  316,   58,  332,  316,  332,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         12,
   86,   14,   15,   16,   17,   87,   88,   89,   90,   91,
  138,  152,  158,  161,   63,   92,   93,   29,   30,   18,
   19,   20,   21,   22,   94,   95,   96,   97,  112,   98,
  126,   99,  109,  132,  145,  100,   31,   44,  129,   45,
  130,   65,   24,   37,   53,  101,   25,  102,  103,
};
static const YYINT yysindex[] = {                      -141,
  -31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -237,  -13, -208,    0, -243,    0,    0,    0,
    0,    0,    0,   -2, -141,    0,    2,  -16,    0,  -22,
   -7,   12,    0,    0,    0,  -41,  -45,    0,    0, -160,
 -160,    0, -200,    0,  -43,    0, -200,    0, -185,    0,
 -183,   38,   39,  -92,    0,    0,    0,    0,    0,    0,
    0,   -6,    0,    0,    0,   -5,   -4,    0,  -37,    0,
    0,   -6,    0,    0, -141,    0,   47,   36,   49,   35,
   44,   49,  -58,   49,    0, -158,    0,    0,   36, -171,
    0,    0,    0,  -12,    0,  -11,  -12, -173,    0,   51,
    0,    0,    0,    0,   65,    0,    0,  -52,   36,    0,
 -160,    0,    0,    0,   10,    0,    0,   11,  -16,    0,
   53,    0,    0,    0,   10,    0,    0,   73,   67,   74,
  -46,   78,   61,    0,   94,    0, -264,    0,    0,    0,
   65,    0,   65, -160,    0,  102,    0,  -46,    0, -160,
  132,   72,    0,    0,    0, -160,    0, -264,  140,   36,
 -264,    0,    0,    0,   36,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
  -44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -42,  -19,    0,  -18,    0,    0,    0,
    0,    0,    0,    0,  217,    0,    6,  179,    0,    0,
    0,  162,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -32,    0,    0,    0,    0,    0,
    0,  229,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  147,    0,    0,  148, -121,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  149,    0,  150,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  235,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  236,    0,  153,    0,  -91,
  154,    0,    0,    0,  -89,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   17,  279,    0,  266,    0,    0,    0,  192,    0,    0,
    0,  -95,    0,    0,    0,    0,    0,    4,    0,    0,
    0,  258,    0,    0,   16,  201,  -26,  -70,  -15,    0,
    0,    0,    0,    0,  137,  -35,  237,  242,  -69,    0,
  219,   -3,  -21,    0,  214,  -34,    0,    0,    0,
};
#define YYTABLESIZE 327
static const YYINT yytable[] = {                         50,
  116,   46,   56,   46,   64,   66,  131,  110,   71,   32,
   26,   71,  144,   55,   52,   23,   13,   69,  120,  150,
  151,   47,   85,   93,   28,   71,   71,   43,   33,   35,
   54,  111,   85,   44,  111,   42,   46,   36,  134,   43,
   23,   13,   42,   39,   40,   32,   68,   41,  111,  111,
   71,   48,   51,   52,   42,   49,   40,    4,    5,    6,
   71,   67,  164,   10,   11,  167,  115,  122,  118,  128,
  124,  153,  133,  154,   41,  135,   72,   54,   74,   76,
  136,   75,   32,  111,   41,  105,  108,  104,  111,  166,
  140,   51,   71,  113,  168,  146,   57,   58,   59,   60,
   61,   62,  114,  119,   79,  128,  125,  128,  155,  127,
   54,  139,  146,  123,  159,  111,  141,  143,  147,  148,
  163,    1,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   54,  137,  149,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   54,   46,
  156,   46,   46,   46,   57,   58,   59,   60,   61,   62,
    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   77,   78,   79,   80,   81,   82,  105,   83,  160,
   84,  142,   44,   44,   42,   42,  162,  165,   57,   58,
   59,   60,   61,   62,   57,   58,   59,   60,   61,   62,
   57,   58,   59,   60,   61,   62,    3,   80,   65,   79,
   67,    1,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   85,   93,   57,   58,   59,   60,   61,   62,
    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   77,   78,   79,   80,   81,   82,   78,   83,   64,
   84,   56,   55,   76,   73,   29,   28,   39,   40,   27,
   34,  121,   38,  117,  157,   73,   70,  106,  107,    0,
    0,    0,   57,   58,   59,   60,   61,   62,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   77,
   78,   79,   80,   81,   82,    0,   83,    0,   84,    0,
    0,   57,   58,   59,   60,   61,   62,
};
static const YYINT yycheck[] = {                         41,
   59,  123,   37,  125,   40,   41,   59,   78,   41,   13,
   42,   44,   59,   59,   36,    0,    0,   61,   89,  284,
  285,   44,   42,   42,  262,   58,   59,   44,   42,  273,
  123,   41,  125,  125,   44,  125,   59,   40,  109,   44,
   25,   25,   59,   42,   61,   49,   43,   91,   58,   59,
   47,   59,   36,   75,   59,   44,   61,  266,  267,  268,
   93,  262,  158,  272,  273,  161,   82,   94,   84,  105,
   97,  141,  108,  143,   91,  111,  262,  123,  262,   41,
  115,   44,   86,   93,   91,  123,   40,   93,   40,  160,
  125,   75,  125,   59,  165,  131,  257,  258,  259,  260,
  261,  262,   59,  262,  276,  141,  280,  143,  144,   59,
  123,   59,  148,  125,  150,  125,   44,   44,   41,   59,
  156,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  123,  123,   41,  257,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  123,  281,
   59,  283,  284,  285,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  123,  281,   58,
  283,  125,  284,  285,  284,  285,  125,   58,  257,  258,
  259,  260,  261,  262,  257,  258,  259,  260,  261,  262,
  257,  258,  259,  260,  261,  262,    0,  262,   40,  262,
   59,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  262,  262,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  262,  281,   41,
  283,  125,  125,  125,  125,   41,   41,  125,  125,    1,
   15,   90,   25,   83,  148,   49,   45,   69,   75,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
  275,  276,  277,  278,  279,   -1,  281,   -1,  283,   -1,
   -1,  257,  258,  259,  260,  261,  262,
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
#define YYMAXTOKEN 302
#define YYUNDFTOKEN 354
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","INT_NUM","FLOAT_NUM",
"STRING","CHARACTER","NULL_SIGNAL","ID","CONST","SIGN","USIGN","LONG","LLONG",
"SHRT","FLOAT","DOUBLE","VOID","CHAR","INT","FOR","DO","WHILE","BREAK",
"CONTINUE","IF","ELSE","RETURN","STRUCT","SWITCH","CASE","DEFALUT","ENTER",
"\"||\"","\"&&\"","\"==\"","\"!=\"","\">=\"","\"<=\"","LEFT_SHIFT",
"RIGHT_SHIFT","\"++\"","\"--\"","DEREF","UMINUS","UPLUS","ADDRESS","INCREMENT",
"DECREMENT","$accept","init","type_decl","type_layer","sign_usgn","int_char",
"long_shrt","while_stmt","do_while_stmt","while_tag","do_tag","switch_stmt",
"switch_clause","switch_content","case_expr","default_expr","factor",
"if_else_stmt","break_stmt","ident","var_init","scalar_decl","func_decl",
"program","array_decl","func_def","var_decl","expr_stmt",
"compound_stmt_content","stmt","condition","if_stmt","else_stmt","for_stmt",
"for_condition","for_content","for_layer_2","expr","arr_ident","arr_tag",
"arr_content","box","arr_cnt_fmt","arr_id","type_ident","parameter_info",
"parameters","compound_stmt","section","continue_stmt","return_stmt",
"illegal-symbol",
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
"array_decl : type_decl arr_ident ';'",
"func_decl : type_ident parameter_info ';'",
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
"stmt : for_stmt",
"while_stmt : while_tag stmt",
"for_stmt : FOR for_condition stmt",
"for_condition : '(' for_content ')'",
"for_content : expr ';' for_layer_2",
"for_content : ';' for_layer_2",
"for_layer_2 : expr ';'",
"for_layer_2 : ';'",
"for_layer_2 : expr ';' expr",
"for_layer_2 : ';' expr",
"do_while_stmt : do_tag while_tag ';'",
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
"expr_stmt : expr ';'",
"condition : '(' expr ')'",
"compound_stmt : '{' compound_stmt_content '}'",
"compound_stmt : '{' '}'",
"compound_stmt_content : stmt compound_stmt_content",
"compound_stmt_content : var_decl compound_stmt_content",
"compound_stmt_content : stmt",
"compound_stmt_content : var_decl",
"break_stmt : BREAK ';'",
"continue_stmt : CONTINUE ';'",
"return_stmt : RETURN expr_stmt",
"return_stmt : RETURN ';'",
"parameter_info : '(' parameters ')'",
"parameter_info : '(' ')'",
"parameters : type_ident ',' parameters",
"parameters : type_ident",
"type_ident : type_decl ID",
"arr_ident : arr_id ',' arr_ident",
"arr_ident : arr_id",
"arr_id : ID arr_tag",
"arr_tag : box arr_tag",
"arr_tag : box '=' arr_cnt_fmt",
"arr_tag : box",
"arr_cnt_fmt : '{' arr_content '}'",
"arr_content : arr_cnt_fmt",
"arr_content : arr_cnt_fmt ',' arr_content",
"arr_content : expr ',' arr_content",
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
"ident : var_init ',' ident",
"ident : var_init ';'",
"ident : ID ';'",
"ident : ID ',' ident",
"var_init : ID '=' expr",
"expr : factor",
"factor : INT_NUM",
"factor : FLOAT_NUM",
"factor : STRING",
"factor : CHARACTER",
"factor : NULL_SIGNAL",
"factor : arr_id",
"factor : ID",

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
#line 342 "parser.y"

int yylex(void);

int main(int argc, char* argv[]) {
    if(argc ==2 && !strcmp(argv[1],"-d")) yydebug = 1;//= tkn 
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
    //if(tkn) printf("symbol_table[%d].name: %s\n", top, symbol_table[top].name);
    //if(tkn) printf("symbol_table[%d].name: %p\n", top, symbol_table[top].name);
    top++;
    return symbol_table[top-1].name;
}

char* reduce_nonterminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
    free(r1);
    return buffer;                           
}

char* reduce_terminal(char* r1){
    size_t buffer_size = strlen(r1)+1;
    char* buffer = (char*)malloc(buffer_size);
    strcpy(buffer,r1);
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
#line 826 "y.tab.c"

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
#line 83 "parser.y"
	{
                                                        size_t n1 = strlen(yystack.l_mark[0].charv);
                                                        char* buffer = (char*)malloc(n1+1);
                                                        strcpy(buffer,yystack.l_mark[0].charv);
                                                        printf("%s", buffer);   
                                                        free(yystack.l_mark[0].charv);
                                                        free(buffer);
                                                    }
#line 1506 "y.tab.c"
break;
case 2:
#line 92 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1511 "y.tab.c"
break;
case 3:
#line 93 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1516 "y.tab.c"
break;
case 4:
#line 96 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1521 "y.tab.c"
break;
case 5:
#line 97 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1526 "y.tab.c"
break;
case 6:
#line 98 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1531 "y.tab.c"
break;
case 7:
#line 101 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1536 "y.tab.c"
break;
case 8:
#line 102 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1541 "y.tab.c"
break;
case 9:
#line 105 "parser.y"
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
#line 1559 "y.tab.c"
break;
case 10:
#line 120 "parser.y"
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
#line 1579 "y.tab.c"
break;
case 11:
#line 138 "parser.y"
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
#line 1600 "y.tab.c"
break;
case 12:
#line 156 "parser.y"
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
#line 1622 "y.tab.c"
break;
case 13:
#line 176 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1627 "y.tab.c"
break;
case 14:
#line 177 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1632 "y.tab.c"
break;
case 15:
#line 178 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1637 "y.tab.c"
break;
case 16:
#line 179 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1642 "y.tab.c"
break;
case 17:
#line 180 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1647 "y.tab.c"
break;
case 18:
#line 181 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1652 "y.tab.c"
break;
case 19:
#line 182 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1657 "y.tab.c"
break;
case 20:
#line 183 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1662 "y.tab.c"
break;
case 21:
#line 184 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1667 "y.tab.c"
break;
case 22:
#line 185 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1672 "y.tab.c"
break;
case 23:
#line 188 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1677 "y.tab.c"
break;
case 24:
#line 190 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1682 "y.tab.c"
break;
case 25:
#line 191 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1687 "y.tab.c"
break;
case 26:
#line 192 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1692 "y.tab.c"
break;
case 27:
#line 193 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1697 "y.tab.c"
break;
case 28:
#line 195 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1702 "y.tab.c"
break;
case 29:
#line 196 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv); }
#line 1707 "y.tab.c"
break;
case 30:
#line 197 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1712 "y.tab.c"
break;
case 31:
#line 198 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1717 "y.tab.c"
break;
case 32:
#line 201 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal_terminal(yystack.l_mark[-2].charv,yystack.l_mark[-1].charv,yystack.l_mark[0].charv);  }
#line 1722 "y.tab.c"
break;
case 33:
#line 203 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1727 "y.tab.c"
break;
case 34:
#line 205 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1732 "y.tab.c"
break;
case 35:
#line 207 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1737 "y.tab.c"
break;
case 36:
#line 209 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1742 "y.tab.c"
break;
case 37:
#line 211 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1747 "y.tab.c"
break;
case 38:
#line 212 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1752 "y.tab.c"
break;
case 39:
#line 213 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1757 "y.tab.c"
break;
case 40:
#line 214 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1762 "y.tab.c"
break;
case 41:
#line 217 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1767 "y.tab.c"
break;
case 42:
#line 218 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1772 "y.tab.c"
break;
case 43:
#line 221 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1777 "y.tab.c"
break;
case 44:
#line 222 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);    }
#line 1782 "y.tab.c"
break;
case 45:
#line 224 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1787 "y.tab.c"
break;
case 46:
#line 225 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1792 "y.tab.c"
break;
case 47:
#line 228 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1797 "y.tab.c"
break;
case 48:
#line 230 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1802 "y.tab.c"
break;
case 49:
#line 232 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1807 "y.tab.c"
break;
case 50:
#line 234 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1812 "y.tab.c"
break;
case 51:
#line 236 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1817 "y.tab.c"
break;
case 52:
#line 237 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1822 "y.tab.c"
break;
case 53:
#line 240 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1827 "y.tab.c"
break;
case 54:
#line 241 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1832 "y.tab.c"
break;
case 55:
#line 242 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1837 "y.tab.c"
break;
case 56:
#line 243 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1842 "y.tab.c"
break;
case 57:
#line 246 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1847 "y.tab.c"
break;
case 58:
#line 247 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1852 "y.tab.c"
break;
case 59:
#line 248 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1857 "y.tab.c"
break;
case 60:
#line 249 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1862 "y.tab.c"
break;
case 61:
#line 251 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1867 "y.tab.c"
break;
case 62:
#line 252 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1872 "y.tab.c"
break;
case 63:
#line 255 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1877 "y.tab.c"
break;
case 64:
#line 256 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1882 "y.tab.c"
break;
case 65:
#line 259 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1887 "y.tab.c"
break;
case 66:
#line 261 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1892 "y.tab.c"
break;
case 67:
#line 262 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1897 "y.tab.c"
break;
case 68:
#line 265 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1902 "y.tab.c"
break;
case 69:
#line 267 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1907 "y.tab.c"
break;
case 70:
#line 268 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1912 "y.tab.c"
break;
case 71:
#line 269 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1917 "y.tab.c"
break;
case 72:
#line 272 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1922 "y.tab.c"
break;
case 73:
#line 274 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1927 "y.tab.c"
break;
case 74:
#line 275 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1932 "y.tab.c"
break;
case 75:
#line 276 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1937 "y.tab.c"
break;
case 76:
#line 277 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1942 "y.tab.c"
break;
case 77:
#line 280 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1947 "y.tab.c"
break;
case 78:
#line 282 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1952 "y.tab.c"
break;
case 79:
#line 283 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1957 "y.tab.c"
break;
case 80:
#line 284 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1962 "y.tab.c"
break;
case 81:
#line 285 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(type_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1967 "y.tab.c"
break;
case 82:
#line 286 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1972 "y.tab.c"
break;
case 83:
#line 287 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1977 "y.tab.c"
break;
case 84:
#line 290 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1982 "y.tab.c"
break;
case 85:
#line 291 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1987 "y.tab.c"
break;
case 86:
#line 292 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1992 "y.tab.c"
break;
case 87:
#line 293 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1997 "y.tab.c"
break;
case 88:
#line 294 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2002 "y.tab.c"
break;
case 89:
#line 295 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2007 "y.tab.c"
break;
case 90:
#line 298 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2012 "y.tab.c"
break;
case 91:
#line 299 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2017 "y.tab.c"
break;
case 92:
#line 302 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, type_table[yystack.l_mark[0].token]);   }
#line 2022 "y.tab.c"
break;
case 93:
#line 303 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2027 "y.tab.c"
break;
case 94:
#line 304 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2032 "y.tab.c"
break;
case 95:
#line 305 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2037 "y.tab.c"
break;
case 96:
#line 308 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2042 "y.tab.c"
break;
case 97:
#line 309 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2047 "y.tab.c"
break;
case 98:
#line 310 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2052 "y.tab.c"
break;
case 99:
#line 313 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2057 "y.tab.c"
break;
case 100:
#line 314 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2062 "y.tab.c"
break;
case 101:
#line 315 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2067 "y.tab.c"
break;
case 102:
#line 316 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2072 "y.tab.c"
break;
case 103:
#line 319 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2077 "y.tab.c"
break;
case 104:
#line 321 "parser.y"
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
#line 2091 "y.tab.c"
break;
case 105:
#line 333 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);   }
#line 2096 "y.tab.c"
break;
case 106:
#line 334 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2101 "y.tab.c"
break;
case 107:
#line 335 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2106 "y.tab.c"
break;
case 108:
#line 336 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2111 "y.tab.c"
break;
case 109:
#line 337 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2116 "y.tab.c"
break;
case 110:
#line 338 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2121 "y.tab.c"
break;
case 111:
#line 339 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);      }
#line 2126 "y.tab.c"
break;
#line 2128 "y.tab.c"
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
