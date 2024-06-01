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
char* reduce_for_expr(char* r1, char* r2, char* r3);
char* reduce_for_unary_expr(char* r1, char* r2);

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
#line 43 "parser.y"
typedef union YYSTYPE{
    int token;
    char* charv;
    struct symbol *sym;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 77 "y.tab.c"

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
   18,   18,   19,   36,   36,   36,   36,   36,   36,   36,
   36,   15,   15,   15,   15,   15,   15,   15,
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
    2,    3,    3,    1,    3,    3,    3,    3,    3,    2,
    2,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   90,   91,   97,   96,   98,   87,   88,   89,   94,
   95,    0,    0,    0,    0,   86,    0,    7,    5,    1,
    8,    6,    4,    0,    0,   83,    0,    0,    9,    0,
    0,    0,   82,   84,   92,    0,    0,    2,   81,    0,
    0,  101,    0,   68,    0,  100,    0,   10,    0,   62,
    0,    0,    0,    0,   11,   12,  112,  113,  114,  115,
  116,    0,    0,    0,  104,    0,  117,    0,    0,  102,
    0,   69,   99,    0,   66,   65,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,   52,    0,   19,   20,
    0,    0,   21,   13,   17,    0,   15,    0,    0,    0,
   22,    0,   14,   18,   16,  110,  111,    0,    0,    0,
    0,    0,   77,    0,   70,   63,    0,    0,   34,    0,
   33,   57,   58,    0,   60,   59,    0,    0,   23,    0,
   54,   51,   53,    0,   45,   49,    0,    0,    0,    0,
  109,    0,    0,    0,    0,    0,    0,   24,    0,   47,
    0,   35,   32,   48,    0,   72,    0,    0,   27,    0,
   25,    0,   50,    0,    0,    0,   75,   74,    0,    0,
   26,    0,    0,    0,    0,   36,    0,   37,    0,   43,
   38,   41,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  304,  305,  306,  307,  308,  309,  324,  325,  326,
  327,  328,  329,  347,  351,   42,  306,  262,  322,  323,
  341,  346,   42,  308,  273,   40,  348,  326,   42,   61,
   91,   59,   44,  342,  344,   59,   44,   59,   44,   41,
  305,  347,  349,  123,   59,  350,  257,  258,  259,  260,
  261,  262,   43,   45,  319,  340,  346,  340,  262,  322,
   61,  342,  322,  262,  341,  262,   44,   41,  274,  275,
  276,  277,  278,  279,  281,  283,  125,  305,  310,  311,
  312,  313,  314,  320,  321,  329,  330,  331,  332,  334,
  336,  340,  350,  352,  353,  340,  340,   60,   62,   43,
   45,   47,   93,  123,  345,  349,   40,  337,  332,   40,
  333,   59,   59,  333,   59,  330,  333,  262,  332,  312,
  331,  125,  331,  280,  335,   59,  340,  340,  340,  340,
  340,  340,  343,  345,   59,  338,  340,  332,  340,  350,
  123,  315,   59,  350,   44,  125,   44,   59,  339,  340,
   41,   59,   41,  284,  285,  316,  343,  343,  340,   59,
  339,  317,  340,   58,  318,  125,  340,  316,   58,  332,
  316,  332,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         12,
   88,   14,   15,   16,   17,   89,   90,   91,   92,   93,
  152,  166,  172,  175,   65,   94,   95,   29,   30,   18,
   19,   20,   21,   22,   96,   97,   98,   99,  121,  100,
  135,  101,  118,  146,  159,  102,   31,   44,  143,   45,
  144,   67,   24,   37,   53,  103,   25,  104,  105,
};
static const YYINT yysindex[] = {                       141,
   39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -251,  -17,  -69,    0, -257,    0,    0,    0,
    0,    0,    0,    5,  141,    0,   -6,   -4,    0,  -32,
   20,   24,    0,    0,    0,   61,  -53,    0,    0,  102,
  102,    0, -209,    0,  -40,    0, -209,    0, -187,    0,
 -173,   50,   66,  -14,    0,    0,    0,    0,    0,    0,
    0,   31,  102,  102,    0,  134,    0,   26,  -26,    0,
    1,    0,    0,   31,    0,    0,  141,    0,   77,   40,
   85,   71,   72,   85,   78,   85,    0, -130,    0,    0,
   40, -142,    0,    0,    0,   13,    0,   18,   13, -134,
    0,   54,    0,    0,    0,    0,    0,  102,  102,  102,
  102,  102,    0,   84,    0,    0,   90,   40,    0,  102,
    0,    0,    0,   25,    0,    0,   30,   -4,    0,  103,
    0,    0,    0,   25,    0,    0,   63,   63,  109,  109,
    0,  107,   47,  136,   96,  143,  123,    0,   97,    0,
 -225,    0,    0,    0,   84,    0,   84,  102,    0,  128,
    0,   96,    0,  102,  137,   67,    0,    0,  134,  102,
    0, -225,  131,   40, -225,    0,  134,    0,   40,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
  -62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -61,  -25,    0,  -23,    0,    0,    0,
    0,    0,    0,    0,  186,    0,  -60,  165,    0,    0,
    0,  147,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -21,    0,    0,    0,    0,    0,
    0,  167,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,    0,  -31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,    0,    0,   87,  -43,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  337,  359,   33,  332,
    0,   88,    0,  168,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  169,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  225,  227,
    0,  170,    0, -124,  188,    0,  279,    0, -120,    0,
    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    7,  208,    0,  307,    0,    0,    0,  275,    0,    0,
    0, -108,    0,    0,    0,    0,    0,  -33,    0,    0,
    0,  343,    0,    0,    9,  284,   16,  -76,   34,    0,
    0,    0,    0,    0,  209,  325,  321,  327, -103,    0,
  303,   17,  -28,    0,  302,  -34,    0,    0,    0,
};
#define YYTABLESIZE 495
static const YYINT yytable[] = {                         46,
   44,   46,   56,  119,   42,   55,   13,   52,   23,   70,
   28,   47,  103,   73,  129,   35,   85,   43,   93,   71,
   71,   71,   71,   71,   33,   71,   46,  103,   63,   32,
   64,   13,   42,   23,   40,   39,   71,   71,   71,   43,
   71,  148,   51,  118,   36,  118,  118,  118,   52,  118,
   41,  167,   69,  168,   42,   63,   40,   64,  164,  165,
  118,  118,  118,  178,  118,   32,  181,   49,  110,   54,
  111,   71,  112,  105,   74,  105,  105,  105,   48,   46,
   26,   46,   63,   51,   64,  108,   41,  109,   76,  150,
  105,  105,  105,   77,  105,  118,  110,  180,  111,  154,
  112,   50,  182,   71,   32,  110,   78,  111,   54,  112,
   87,  131,  136,  108,  133,  109,  117,  124,  113,  127,
   63,   41,   64,  114,  120,  105,   63,  118,   64,  122,
  123,  128,   63,   81,   64,   54,  125,  163,   63,  110,
   64,  111,  132,  112,   63,  134,   64,   54,  145,  110,
  155,  111,  151,  112,  158,  112,  108,  105,  109,   44,
   44,  153,   54,   42,   42,  110,  108,  111,  109,  112,
  110,  156,  111,  110,  112,  111,  110,  112,  111,  157,
  112,  162,  108,  161,  109,    3,  170,  108,  179,  109,
  108,  176,  109,  108,  174,  109,    4,    5,    6,   80,
   79,   78,   10,   11,   65,   67,  114,   64,   27,   29,
   56,   55,   76,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   85,   46,   93,   46,
   46,   46,   57,   58,   59,   60,   61,   62,    1,    2,
    3,    4,    5,    6,    7,    8,    9,   10,   11,   79,
   80,   81,   82,   83,   84,   31,   85,   28,   86,   57,
   58,   59,   60,   61,   62,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   79,   80,   81,   82,
   83,   84,   73,   85,   39,   86,   57,   58,   59,   60,
   61,   62,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   40,   79,   80,   81,   82,   83,   84,   30,
   85,   34,   86,    1,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,   57,   58,   59,   60,   61,   62,
   57,   58,   59,   60,   61,   62,   57,   58,   59,   60,
   61,   62,   57,   58,   59,   60,   61,   62,   57,   58,
   59,   60,   61,   62,   66,   68,  130,   38,  126,   75,
  171,   72,  106,  115,  106,  106,  106,  107,  116,    0,
  107,    0,    0,    0,    0,    0,    0,  106,  107,  106,
  106,  106,    0,  106,  107,  107,  107,    0,  107,  108,
    0,    0,  108,    1,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,    0,    0,  108,  108,  108,    0,
  108,    0,    0,    0,  106,    0,    0,    0,    0,  107,
    0,    0,  137,  138,  139,  140,  141,    0,  142,    0,
    0,  147,    0,    0,  149,    0,    0,    0,    0,    0,
    0,  108,    0,    0,    0,    0,  106,    0,    0,    0,
    0,  107,    0,    0,    0,    0,    0,    0,    0,  160,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  142,
    0,  142,  169,  108,    0,    0,  160,    0,  173,    0,
    0,    0,    0,    0,  177,
};
static const YYINT yycheck[] = {                         43,
  125,   45,   37,   80,  125,   59,    0,   36,    0,   43,
  262,   44,   44,   47,   91,  273,   42,   44,   42,   41,
   61,   43,   44,   45,   42,   47,   59,   59,   43,   13,
   45,   25,   59,   25,   61,   42,   58,   59,   60,   44,
   62,  118,   36,   41,   40,   43,   44,   45,   77,   47,
   91,  155,  262,  157,   59,   43,   61,   45,  284,  285,
   58,   59,   60,  172,   62,   49,  175,   44,   43,  123,
   45,   93,   47,   41,  262,   43,   44,   45,   59,  123,
   42,  125,   43,   77,   45,   60,   91,   62,  262,  124,
   58,   59,   60,   44,   62,   93,   43,  174,   45,  134,
   47,   41,  179,  125,   88,   43,   41,   45,  123,   47,
  125,   96,   59,   60,   99,   62,   40,   84,   93,   86,
   43,   91,   45,  123,   40,   93,   43,  125,   45,   59,
   59,  262,   43,  276,   45,  123,   59,   41,   43,   43,
   45,   45,  125,   47,   43,  280,   45,  123,   59,   43,
   44,   45,  123,   47,   59,   47,   60,  125,   62,  284,
  285,   59,  123,  284,  285,   43,   60,   45,   62,   47,
   43,  125,   45,   43,   47,   45,   43,   47,   45,   44,
   47,   59,   60,   41,   62,    0,   59,   60,   58,   62,
   60,  125,   62,   60,   58,   62,  266,  267,  268,  262,
  262,  262,  272,  273,   40,   59,  123,   41,    1,   41,
  125,  125,  125,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  262,  281,  262,  283,
  284,  285,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,   41,  281,   41,  283,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  125,  281,  125,  283,  257,  258,  259,  260,
  261,  262,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,  125,  274,  275,  276,  277,  278,  279,   41,
  281,   15,  283,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  257,  258,  259,  260,  261,  262,
  257,  258,  259,  260,  261,  262,  257,  258,  259,  260,
  261,  262,  257,  258,  259,  260,  261,  262,  257,  258,
  259,  260,  261,  262,   40,   41,   92,   25,   85,   49,
  162,   45,   41,   71,   43,   44,   45,   41,   77,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   -1,   63,   64,   58,
   59,   60,   -1,   62,   58,   59,   60,   -1,   62,   41,
   -1,   -1,   44,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,   -1,   -1,   58,   59,   60,   -1,
   62,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   93,
   -1,   -1,  108,  109,  110,  111,  112,   -1,  114,   -1,
   -1,  117,   -1,   -1,  120,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  145,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  155,
   -1,  157,  158,  125,   -1,   -1,  162,   -1,  164,   -1,
   -1,   -1,   -1,   -1,  170,
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
   -1,   -1,   -1,   -1,
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
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '/' expr",
"expr : '+' expr",
"expr : '-' expr",
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
#line 351 "parser.y"

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

char* reduce_for_expr(char* r1, char* r2, char* r3){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t n3 = strlen(r3);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+n3+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,r3);
    strcat(buffer,"</expr>");
    free(r1);
    free(r3);
    return buffer;
}

char* reduce_for_unary_expr(char* r1, char* r2){ 
    size_t l = strlen("<expr>");
    size_t n1 = strlen(r1);
    size_t n2 = strlen(r2);
    size_t r = strlen("</expr>");                      
    char* buffer = (char*)malloc(l+r+n1+n2+1);
    strcpy(buffer,"<expr>");
    strcat(buffer,r1);
    strcat(buffer,r2);
    strcat(buffer,"</expr>");
    free(r2);
    return buffer;
}
#line 927 "y.tab.c"

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
#line 85 "parser.y"
	{
                                                        size_t n1 = strlen(yystack.l_mark[0].charv);
                                                        char* buffer = (char*)malloc(n1+1);
                                                        strcpy(buffer,yystack.l_mark[0].charv);
                                                        printf("%s", buffer);   
                                                        free(yystack.l_mark[0].charv);
                                                        free(buffer);
                                                    }
#line 1607 "y.tab.c"
break;
case 2:
#line 94 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1612 "y.tab.c"
break;
case 3:
#line 95 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1617 "y.tab.c"
break;
case 4:
#line 98 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1622 "y.tab.c"
break;
case 5:
#line 99 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1627 "y.tab.c"
break;
case 6:
#line 100 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1632 "y.tab.c"
break;
case 7:
#line 103 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1637 "y.tab.c"
break;
case 8:
#line 104 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1642 "y.tab.c"
break;
case 9:
#line 107 "parser.y"
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
#line 1660 "y.tab.c"
break;
case 10:
#line 122 "parser.y"
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
#line 1680 "y.tab.c"
break;
case 11:
#line 140 "parser.y"
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
#line 1701 "y.tab.c"
break;
case 12:
#line 158 "parser.y"
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
#line 1723 "y.tab.c"
break;
case 13:
#line 178 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1728 "y.tab.c"
break;
case 14:
#line 179 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1733 "y.tab.c"
break;
case 15:
#line 180 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1738 "y.tab.c"
break;
case 16:
#line 181 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1743 "y.tab.c"
break;
case 17:
#line 182 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1748 "y.tab.c"
break;
case 18:
#line 183 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1753 "y.tab.c"
break;
case 19:
#line 184 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1758 "y.tab.c"
break;
case 20:
#line 185 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1763 "y.tab.c"
break;
case 21:
#line 186 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1768 "y.tab.c"
break;
case 22:
#line 187 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1773 "y.tab.c"
break;
case 23:
#line 190 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1778 "y.tab.c"
break;
case 24:
#line 192 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1783 "y.tab.c"
break;
case 25:
#line 193 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1788 "y.tab.c"
break;
case 26:
#line 194 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1793 "y.tab.c"
break;
case 27:
#line 195 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1798 "y.tab.c"
break;
case 28:
#line 197 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1803 "y.tab.c"
break;
case 29:
#line 198 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv); }
#line 1808 "y.tab.c"
break;
case 30:
#line 199 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1813 "y.tab.c"
break;
case 31:
#line 200 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1818 "y.tab.c"
break;
case 32:
#line 203 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal_terminal(yystack.l_mark[-2].charv,yystack.l_mark[-1].charv,yystack.l_mark[0].charv);  }
#line 1823 "y.tab.c"
break;
case 33:
#line 205 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1828 "y.tab.c"
break;
case 34:
#line 207 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1833 "y.tab.c"
break;
case 35:
#line 209 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1838 "y.tab.c"
break;
case 36:
#line 211 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1843 "y.tab.c"
break;
case 37:
#line 213 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1848 "y.tab.c"
break;
case 38:
#line 214 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1853 "y.tab.c"
break;
case 39:
#line 215 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1858 "y.tab.c"
break;
case 40:
#line 216 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1863 "y.tab.c"
break;
case 41:
#line 219 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1868 "y.tab.c"
break;
case 42:
#line 220 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1873 "y.tab.c"
break;
case 43:
#line 223 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1878 "y.tab.c"
break;
case 44:
#line 224 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);    }
#line 1883 "y.tab.c"
break;
case 45:
#line 226 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1888 "y.tab.c"
break;
case 46:
#line 227 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1893 "y.tab.c"
break;
case 47:
#line 230 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1898 "y.tab.c"
break;
case 48:
#line 232 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1903 "y.tab.c"
break;
case 49:
#line 234 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1908 "y.tab.c"
break;
case 50:
#line 236 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1913 "y.tab.c"
break;
case 51:
#line 238 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1918 "y.tab.c"
break;
case 52:
#line 239 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1923 "y.tab.c"
break;
case 53:
#line 242 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1928 "y.tab.c"
break;
case 54:
#line 243 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1933 "y.tab.c"
break;
case 55:
#line 244 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1938 "y.tab.c"
break;
case 56:
#line 245 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1943 "y.tab.c"
break;
case 57:
#line 248 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1948 "y.tab.c"
break;
case 58:
#line 249 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1953 "y.tab.c"
break;
case 59:
#line 250 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1958 "y.tab.c"
break;
case 60:
#line 251 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1963 "y.tab.c"
break;
case 61:
#line 253 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1968 "y.tab.c"
break;
case 62:
#line 254 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1973 "y.tab.c"
break;
case 63:
#line 257 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1978 "y.tab.c"
break;
case 64:
#line 258 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1983 "y.tab.c"
break;
case 65:
#line 261 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1988 "y.tab.c"
break;
case 66:
#line 263 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1993 "y.tab.c"
break;
case 67:
#line 264 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1998 "y.tab.c"
break;
case 68:
#line 267 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2003 "y.tab.c"
break;
case 69:
#line 269 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 2008 "y.tab.c"
break;
case 70:
#line 270 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2013 "y.tab.c"
break;
case 71:
#line 271 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2018 "y.tab.c"
break;
case 72:
#line 274 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 2023 "y.tab.c"
break;
case 73:
#line 276 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2028 "y.tab.c"
break;
case 74:
#line 277 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2033 "y.tab.c"
break;
case 75:
#line 278 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2038 "y.tab.c"
break;
case 76:
#line 279 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2043 "y.tab.c"
break;
case 77:
#line 282 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 2048 "y.tab.c"
break;
case 78:
#line 284 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 2053 "y.tab.c"
break;
case 79:
#line 285 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2058 "y.tab.c"
break;
case 80:
#line 286 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2063 "y.tab.c"
break;
case 81:
#line 287 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(type_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 2068 "y.tab.c"
break;
case 82:
#line 288 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2073 "y.tab.c"
break;
case 83:
#line 289 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 2078 "y.tab.c"
break;
case 84:
#line 292 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 2083 "y.tab.c"
break;
case 85:
#line 293 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2088 "y.tab.c"
break;
case 86:
#line 294 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2093 "y.tab.c"
break;
case 87:
#line 295 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2098 "y.tab.c"
break;
case 88:
#line 296 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2103 "y.tab.c"
break;
case 89:
#line 297 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2108 "y.tab.c"
break;
case 90:
#line 300 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2113 "y.tab.c"
break;
case 91:
#line 301 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2118 "y.tab.c"
break;
case 92:
#line 304 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, type_table[yystack.l_mark[0].token]);   }
#line 2123 "y.tab.c"
break;
case 93:
#line 305 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 2128 "y.tab.c"
break;
case 94:
#line 306 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2133 "y.tab.c"
break;
case 95:
#line 307 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2138 "y.tab.c"
break;
case 96:
#line 310 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2143 "y.tab.c"
break;
case 97:
#line 311 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2148 "y.tab.c"
break;
case 98:
#line 312 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2153 "y.tab.c"
break;
case 99:
#line 315 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2158 "y.tab.c"
break;
case 100:
#line 316 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2163 "y.tab.c"
break;
case 101:
#line 317 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2168 "y.tab.c"
break;
case 102:
#line 318 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2173 "y.tab.c"
break;
case 103:
#line 321 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2178 "y.tab.c"
break;
case 104:
#line 323 "parser.y"
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
#line 2192 "y.tab.c"
break;
case 105:
#line 333 "parser.y"
	{   yyval.charv = reduce_for_expr(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2197 "y.tab.c"
break;
case 106:
#line 334 "parser.y"
	{   yyval.charv = reduce_for_expr(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2202 "y.tab.c"
break;
case 107:
#line 335 "parser.y"
	{   yyval.charv = reduce_for_expr(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2207 "y.tab.c"
break;
case 108:
#line 336 "parser.y"
	{   yyval.charv = reduce_for_expr(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2212 "y.tab.c"
break;
case 109:
#line 337 "parser.y"
	{   yyval.charv = reduce_for_expr(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2217 "y.tab.c"
break;
case 110:
#line 338 "parser.y"
	{   yyval.charv = reduce_for_unary_expr(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2222 "y.tab.c"
break;
case 111:
#line 339 "parser.y"
	{   yyval.charv = reduce_for_unary_expr(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2227 "y.tab.c"
break;
case 112:
#line 342 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);   }
#line 2232 "y.tab.c"
break;
case 113:
#line 343 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2237 "y.tab.c"
break;
case 114:
#line 344 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2242 "y.tab.c"
break;
case 115:
#line 345 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2247 "y.tab.c"
break;
case 116:
#line 346 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2252 "y.tab.c"
break;
case 117:
#line 347 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);   }
#line 2257 "y.tab.c"
break;
case 118:
#line 348 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);      }
#line 2262 "y.tab.c"
break;
#line 2264 "y.tab.c"
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
