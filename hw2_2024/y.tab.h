#ifndef _yy_defines_h_
#define _yy_defines_h_

#define NUM 257
#define ID 258
#define TYPE 259
#define array_decl 268
#define func_decl 269
#define func_def 270
#define stmt 271
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
    int token;
    double token_float;
    char* charv;
    char punc_symbol;
    char* op;
    char* data_type;
    char* identifier;
    char* expression;
    struct symbol *sym;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
