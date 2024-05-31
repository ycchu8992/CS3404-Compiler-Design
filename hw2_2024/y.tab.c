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
    0,   19,   19,   44,   44,   44,   22,   22,   17,   20,
   18,   21,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,    6,   29,   30,   31,   31,   32,   32,   32,
   32,    7,    8,    9,   10,   11,   12,   12,   12,   12,
   13,   13,   14,   14,   45,   45,   27,   28,   23,   26,
   43,   43,   24,   24,   24,   24,   46,   47,   48,   48,
   41,   41,   42,   42,   40,   34,   34,   39,   35,   35,
   35,   38,   36,   36,   36,   36,   37,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    2,    2,    2,    3,
    3,    4,    4,    4,    4,    5,    5,    5,   15,   15,
   15,   15,   16,   33,
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
    2,    3,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   90,   91,   97,   96,   98,   87,   88,   89,   94,
   95,    0,    0,    0,    0,   86,    0,    7,    5,    1,
    8,    6,    4,    0,    0,   83,    0,    0,    9,    0,
    0,    0,   82,   84,   92,    0,    0,    2,   81,    0,
    0,  101,    0,   68,    0,  100,    0,   10,    0,   62,
    0,    0,    0,    0,   11,   12,  104,  103,    0,    0,
  102,    0,   69,   99,    0,   66,   65,    0,   61,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,   19,
   20,    0,    0,   21,    0,   15,    0,    0,    0,   22,
    0,   14,   13,   17,   18,   16,   77,    0,   70,   63,
    0,    0,   34,    0,   33,   57,   58,    0,   60,   59,
    0,    0,   23,    0,   54,   51,   53,    0,   45,   49,
    0,    0,    0,    0,    0,    0,   24,    0,   47,    0,
   35,   32,   48,    0,   72,    0,    0,   27,    0,   25,
    0,   50,    0,    0,    0,   75,   74,   31,    0,   26,
    0,    0,    0,    0,   36,   30,   37,    0,   43,   38,
   41,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  286,  287,  288,  289,  290,  291,  303,  304,  305,
  306,  307,  308,  326,  330,   42,  288,  258,  301,  302,
  320,  325,   42,  290,  269,   40,  327,  305,   42,   61,
   91,  282,  284,  321,  323,  282,  284,  282,  284,   41,
  287,  326,  328,  123,  282,  329,  257,  319,  319,  258,
  301,   61,  321,  301,  258,  320,  258,  284,   41,  270,
  271,  272,  273,  274,  275,  277,  279,  125,  287,  292,
  293,  294,  295,  296,  308,  309,  310,  311,  313,  315,
  319,  329,  331,  332,  333,  334,   93,  123,  324,  328,
   40,  316,  311,   40,  312,  282,  282,  312,  282,  309,
  312,  258,  311,  294,  310,  125,  310,  276,  314,  282,
  319,  322,  324,  282,  317,  319,  311,  319,  329,  123,
  297,  282,  329,  284,  125,  284,  282,  318,  319,   41,
  282,   41,  280,  281,  298,  322,  322,  319,  282,  318,
  299,  319,   58,  300,  125,  319,  298,   58,  311,  298,
  311,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         12,
   79,   14,   15,   16,   17,   80,   81,   82,   83,   84,
  131,  145,  151,  154,   29,   30,   18,   19,   20,   21,
   22,   85,   86,   87,   88,  105,   89,  119,   90,  102,
  125,  138,   91,   31,   44,  122,   45,  123,   32,   24,
   37,   53,   92,   25,   93,   94,   95,   96,
};
static const YYINT yysindex[] = {                      -146,
  -31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -246,    2, -194,    0, -219,    0,    0,    0,
    0,    0,    0,   15, -146,    0,   16,  -43,    0, -253,
 -225, -224,    0,    0,    0,  -41, -122,    0,    0, -198,
 -198,    0, -196,    0,  -48,    0, -196,    0, -195,    0,
 -193, -218,   30,  -93,    0,    0,    0,    0,  -21,  -42,
    0,  -50,    0,    0,  -13,    0,    0, -146,    0,   36,
  -12,   40, -201, -200,   40, -243,   40,    0, -175,    0,
    0,  -12, -188,    0,  -72,    0,  -40,  -72, -190,    0,
 -192,    0,    0,    0,    0,    0,    0, -121,    0,    0,
 -242,  -12,    0, -198,    0,    0,    0,  -32,    0,    0,
  -28,  -43,    0, -186,    0,    0,    0,  -32,    0,    0,
 -183,  -33, -182, -241,   53, -184,    0,   62,    0, -228,
    0,    0,    0, -121,    0, -121, -198,    0, -177,    0,
 -241,    0, -198,   49,  -17,    0,    0,    0, -198,    0,
 -228,   51,  -12, -228,    0,    0,    0,  -12,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
 -148,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -134,  -15,    0,  -14,    0,    0,    0,
    0,    0,    0,    0,  125,    0, -132,   87,    0,    0,
    0, -154,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -249,    0,    0,    0,    0,    0,
    0,   88,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    6, -118,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7,    0,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   93,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   94,    0,
   12,    0,  -71,   13,    0,    0,    0,  -69,    0,    0,
    0,
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
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    9,  139,    0,  143,    0,    0,    0,   82,    0,    0,
    0, -129,    0,    0,  -23,    0,    0,    0,  158,    0,
    0,   21,  128,  -62,  -65,  -39,    0,    0,    0,    0,
    0,   65,  -37,  159,  168,  -87,    0,  152,    0,  -26,
    0,  147,  -29,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 267
static const YYINT yytable[] = {                         50,
   54,   98,   58,   59,   46,  103,   46,   56,   13,   52,
   26,   28,   62,   57,   57,   57,  113,   40,   40,   61,
   23,  157,  115,   64,  160,  117,   85,   93,   46,   54,
   47,   78,   71,   13,   71,  108,  127,  111,  109,  124,
  137,   52,   41,   33,   51,   23,  146,   41,  147,   35,
   54,  143,  144,   44,   36,   42,   48,   39,   57,   49,
  121,   60,   65,  126,   67,   68,  128,    4,    5,    6,
   69,   97,   98,   10,   11,  101,   51,   41,  129,  104,
  106,  107,  112,   72,  116,  118,  139,  159,  133,  120,
   54,  135,  161,  140,  130,  132,  121,  141,  121,  148,
  134,  136,  142,  139,  149,  152,  153,  155,  158,   80,
   54,  156,    1,    2,    3,    4,    5,    6,    7,    8,
    9,   10,   11,   79,    3,   78,   65,   67,   64,   56,
   55,   76,   73,   29,   28,   57,   39,   40,   46,   27,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,   46,   46,   46,   34,   46,   55,
   46,   46,   46,   57,  114,    1,    2,    3,    4,    5,
    6,    7,    8,    9,   10,   11,   70,   71,   72,   73,
   74,   75,   38,   76,   57,   77,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   11,   70,   71,   72,
   73,   74,   75,  110,   76,  150,   77,   66,   44,   44,
   42,   42,   63,   99,  100,    0,    0,    1,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,    2,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   42,   42,
   43,   43,   85,   93,   57,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   71,   72,
   73,   74,   75,    0,   76,    0,   77,
};
static const YYINT yycheck[] = {                         41,
  123,  123,   40,   41,  123,   71,  125,   37,    0,   36,
   42,  258,   61,  257,  257,  257,   82,   61,   61,   43,
    0,  151,   85,   47,  154,   88,   42,   42,  282,  123,
  284,  125,  282,   25,  284,   75,  102,   77,  282,  282,
  282,   68,   91,   42,   36,   25,  134,   91,  136,  269,
  123,  280,  281,  125,   40,  125,  282,   42,  257,  284,
   98,  258,  258,  101,  258,  284,  104,  262,  263,  264,
   41,   93,  123,  268,  269,   40,   68,   91,  108,   40,
  282,  282,  258,  272,  125,  276,  124,  153,  118,  282,
  123,  125,  158,   41,  123,  282,  134,  282,  136,  137,
  284,  284,   41,  141,  282,  143,   58,  125,   58,  258,
  123,  149,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  258,    0,  258,   40,  282,   41,  125,
  125,  125,  125,   41,   41,  257,  125,  125,  257,    1,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  275,   15,  277,  282,
  279,  280,  281,  257,   83,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,   25,  277,  257,  279,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  274,  275,   76,  277,  141,  279,   49,  280,  281,
  280,  281,   45,   62,   68,   -1,   -1,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  282,  282,
  284,  284,  258,  258,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
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
#define YYUNDFTOKEN 335
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
"compound_stmt_content","stmt","condition","if_stmt","else_stmt","for_stmt",
"for_condition","for_content","for_layer_2","expr","arr_ident","arr_tag",
"arr_content","box","arr_cnt_fmt","arr_id","type_ident","parameter_info",
"parameters","compound_stmt","section","if_else_stmt","break_stmt",
"continue_stmt","return_stmt","illegal-symbol",
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
"stmt : for_stmt",
"while_stmt : while_tag stmt",
"for_stmt : FOR for_condition stmt",
"for_condition : '(' for_content ')'",
"for_content : expr SEMICOLON for_layer_2",
"for_content : SEMICOLON for_layer_2",
"for_layer_2 : expr SEMICOLON",
"for_layer_2 : SEMICOLON",
"for_layer_2 : expr SEMICOLON expr",
"for_layer_2 : SEMICOLON expr",
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
#line 314 "parser.y"

int yylex(void);

int main(int argc, char* argv[]) {
    if(argc ==2 && !strcmp(argv[1],"-d")) yydebug = 1; //tkn 
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
#line 787 "y.tab.c"

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
#line 64 "parser.y"
	{
                                                        size_t n1 = strlen(yystack.l_mark[0].charv);
                                                        char* buffer = (char*)malloc(n1+1);
                                                        strcpy(buffer,yystack.l_mark[0].charv);
                                                        printf("%s", buffer);   
                                                        free(yystack.l_mark[0].charv);
                                                        free(buffer);
                                                    }
#line 1467 "y.tab.c"
break;
case 2:
#line 73 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1472 "y.tab.c"
break;
case 3:
#line 74 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1477 "y.tab.c"
break;
case 4:
#line 77 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1482 "y.tab.c"
break;
case 5:
#line 78 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1487 "y.tab.c"
break;
case 6:
#line 79 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1492 "y.tab.c"
break;
case 7:
#line 82 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1497 "y.tab.c"
break;
case 8:
#line 83 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1502 "y.tab.c"
break;
case 9:
#line 86 "parser.y"
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
#line 1520 "y.tab.c"
break;
case 10:
#line 101 "parser.y"
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
#line 1540 "y.tab.c"
break;
case 11:
#line 119 "parser.y"
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
#line 1561 "y.tab.c"
break;
case 12:
#line 137 "parser.y"
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
#line 1583 "y.tab.c"
break;
case 13:
#line 157 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1588 "y.tab.c"
break;
case 14:
#line 158 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1593 "y.tab.c"
break;
case 15:
#line 159 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1598 "y.tab.c"
break;
case 16:
#line 160 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1603 "y.tab.c"
break;
case 17:
#line 161 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1608 "y.tab.c"
break;
case 18:
#line 162 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1613 "y.tab.c"
break;
case 19:
#line 163 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1618 "y.tab.c"
break;
case 20:
#line 164 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1623 "y.tab.c"
break;
case 21:
#line 165 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1628 "y.tab.c"
break;
case 22:
#line 166 "parser.y"
	{   yyval.charv = reduce_for_stmt(yystack.l_mark[0].charv);   }
#line 1633 "y.tab.c"
break;
case 23:
#line 169 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1638 "y.tab.c"
break;
case 24:
#line 171 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1643 "y.tab.c"
break;
case 25:
#line 172 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1648 "y.tab.c"
break;
case 26:
#line 173 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1653 "y.tab.c"
break;
case 27:
#line 174 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1658 "y.tab.c"
break;
case 28:
#line 176 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1663 "y.tab.c"
break;
case 29:
#line 177 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv); }
#line 1668 "y.tab.c"
break;
case 30:
#line 178 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1673 "y.tab.c"
break;
case 31:
#line 179 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1678 "y.tab.c"
break;
case 32:
#line 182 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal_terminal(yystack.l_mark[-2].charv,yystack.l_mark[-1].charv,yystack.l_mark[0].charv);  }
#line 1683 "y.tab.c"
break;
case 33:
#line 184 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1688 "y.tab.c"
break;
case 34:
#line 186 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1693 "y.tab.c"
break;
case 35:
#line 188 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1698 "y.tab.c"
break;
case 36:
#line 190 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1703 "y.tab.c"
break;
case 37:
#line 192 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1708 "y.tab.c"
break;
case 38:
#line 193 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1713 "y.tab.c"
break;
case 39:
#line 194 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1718 "y.tab.c"
break;
case 40:
#line 195 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1723 "y.tab.c"
break;
case 41:
#line 198 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv); }
#line 1728 "y.tab.c"
break;
case 42:
#line 199 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1733 "y.tab.c"
break;
case 43:
#line 202 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1738 "y.tab.c"
break;
case 44:
#line 203 "parser.y"
	{   yyval.charv = reduce_terminal(yystack.l_mark[0].charv);    }
#line 1743 "y.tab.c"
break;
case 45:
#line 205 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1748 "y.tab.c"
break;
case 46:
#line 206 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1753 "y.tab.c"
break;
case 47:
#line 209 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_nonterminal(keyword_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1758 "y.tab.c"
break;
case 48:
#line 211 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1763 "y.tab.c"
break;
case 49:
#line 213 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1768 "y.tab.c"
break;
case 50:
#line 215 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1773 "y.tab.c"
break;
case 51:
#line 217 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1778 "y.tab.c"
break;
case 52:
#line 218 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1783 "y.tab.c"
break;
case 53:
#line 221 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1788 "y.tab.c"
break;
case 54:
#line 222 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv,yystack.l_mark[0].charv);   }
#line 1793 "y.tab.c"
break;
case 55:
#line 223 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1798 "y.tab.c"
break;
case 56:
#line 224 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1803 "y.tab.c"
break;
case 57:
#line 227 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1808 "y.tab.c"
break;
case 58:
#line 228 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1813 "y.tab.c"
break;
case 59:
#line 229 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1818 "y.tab.c"
break;
case 60:
#line 230 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(keyword_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1823 "y.tab.c"
break;
case 61:
#line 232 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1828 "y.tab.c"
break;
case 62:
#line 233 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 1833 "y.tab.c"
break;
case 63:
#line 236 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1838 "y.tab.c"
break;
case 64:
#line 237 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1843 "y.tab.c"
break;
case 65:
#line 240 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1848 "y.tab.c"
break;
case 66:
#line 242 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1853 "y.tab.c"
break;
case 67:
#line 243 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1858 "y.tab.c"
break;
case 68:
#line 246 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1863 "y.tab.c"
break;
case 69:
#line 248 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1868 "y.tab.c"
break;
case 70:
#line 249 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1873 "y.tab.c"
break;
case 71:
#line 250 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1878 "y.tab.c"
break;
case 72:
#line 253 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1883 "y.tab.c"
break;
case 73:
#line 255 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1888 "y.tab.c"
break;
case 74:
#line 256 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1893 "y.tab.c"
break;
case 75:
#line 257 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1898 "y.tab.c"
break;
case 76:
#line 258 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1903 "y.tab.c"
break;
case 77:
#line 261 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1908 "y.tab.c"
break;
case 78:
#line 263 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);   }
#line 1913 "y.tab.c"
break;
case 79:
#line 264 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1918 "y.tab.c"
break;
case 80:
#line 265 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1923 "y.tab.c"
break;
case 81:
#line 266 "parser.y"
	{   yyval.charv = reduce_terminal_nonterminal_terminal(type_table[yystack.l_mark[-2].token], yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1928 "y.tab.c"
break;
case 82:
#line 267 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 1933 "y.tab.c"
break;
case 83:
#line 268 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(type_table[yystack.l_mark[-1].token], yystack.l_mark[0].charv);  }
#line 1938 "y.tab.c"
break;
case 84:
#line 271 "parser.y"
	{   yyval.charv = reduce_nonterminal_nonterminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);    }
#line 1943 "y.tab.c"
break;
case 85:
#line 272 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1948 "y.tab.c"
break;
case 86:
#line 273 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1953 "y.tab.c"
break;
case 87:
#line 274 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1958 "y.tab.c"
break;
case 88:
#line 275 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1963 "y.tab.c"
break;
case 89:
#line 276 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1968 "y.tab.c"
break;
case 90:
#line 279 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1973 "y.tab.c"
break;
case 91:
#line 280 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1978 "y.tab.c"
break;
case 92:
#line 283 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, type_table[yystack.l_mark[0].token]);   }
#line 1983 "y.tab.c"
break;
case 93:
#line 284 "parser.y"
	{   yyval.charv = reduce_nonterminal(yystack.l_mark[0].charv);    }
#line 1988 "y.tab.c"
break;
case 94:
#line 285 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1993 "y.tab.c"
break;
case 95:
#line 286 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 1998 "y.tab.c"
break;
case 96:
#line 289 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2003 "y.tab.c"
break;
case 97:
#line 290 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2008 "y.tab.c"
break;
case 98:
#line 291 "parser.y"
	{   yyval.charv = reduce_terminal(type_table[yystack.l_mark[0].token]);   }
#line 2013 "y.tab.c"
break;
case 99:
#line 294 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2018 "y.tab.c"
break;
case 100:
#line 295 "parser.y"
	{   yyval.charv = reduce_nonterminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);   }
#line 2023 "y.tab.c"
break;
case 101:
#line 296 "parser.y"
	{   yyval.charv = reduce_terminal_terminal(yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2028 "y.tab.c"
break;
case 102:
#line 297 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2033 "y.tab.c"
break;
case 103:
#line 300 "parser.y"
	{   yyval.charv = reduce_terminal_terminal_nonterminal(yystack.l_mark[-2].charv, yystack.l_mark[-1].charv, yystack.l_mark[0].charv);  }
#line 2038 "y.tab.c"
break;
case 104:
#line 302 "parser.y"
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
#line 2052 "y.tab.c"
break;
#line 2054 "y.tab.c"
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
