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
#define stmt 282
#define SEMICOLON 283
#define ENTER 284
#define COMMA 285
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
