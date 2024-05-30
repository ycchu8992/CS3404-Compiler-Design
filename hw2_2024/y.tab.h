#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define SEMICOLON 270
#define ENTER 271
#define COMMA 272
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE{
    int token;
    char* charv;
    struct symbol *sym;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
