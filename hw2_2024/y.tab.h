#ifndef _yy_defines_h_
#define _yy_defines_h_

#define type_casting 257
#define INT_NUM 258
#define FLOAT_NUM 259
#define STRING 260
#define CHARACTER 261
#define NULL_SIGNAL 262
#define ID 263
#define CONST 264
#define SIGN 265
#define USIGN 266
#define LONG 267
#define LLONG 268
#define SHRT 269
#define FLOAT 270
#define DOUBLE 271
#define VOID 272
#define CHAR 273
#define INT 274
#define FOR 275
#define DO 276
#define WHILE 277
#define BREAK 278
#define CONTINUE 279
#define IF 280
#define ELSE 281
#define RETURN 282
#define STRUCT 283
#define SWITCH 284
#define CASE 285
#define DEFALUT 286
#define ENTER 287
#define OR 288
#define AND 289
#define IS_EQUAL 290
#define IS_NOT_EQUAL 291
#define LESS_OR_EQUAL 292
#define GREATER_OR_EQUAL 293
#define SHIFT_LEFT 294
#define SHIFT_RIGHT 295
#define INCREMENT 296
#define DECREMENT 297
#define PTRUSED 298
#define UMINUS 299
#define UPLUS 300
#define ADDRESS 301
#define CAST 302
#define POSTFIX 303
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
