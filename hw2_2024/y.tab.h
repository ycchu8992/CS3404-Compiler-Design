#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define OR 287
#define AND 288
#define IS_EQUAL 289
#define IS_NOT_EQUAL 290
#define LESS_OR_EQUAL 291
#define GREATER_OR_EQUAL 292
#define SHIFT_LEFT 293
#define SHIFT_RIGHT 294
#define INCREMENT 295
#define DECREMENT 296
#define PTRUSED 297
#define UMINUS 298
#define UPLUS 299
#define ADDRESS 300
#define POSTFIX 301
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
