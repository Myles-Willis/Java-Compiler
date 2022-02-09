struct token {
   int category;   /* the integer code returned by yylex */
   char *text;     /* the actual string (lexeme) matched */
   int lineno;     /* the line number on which the token occurs */
   char *filename; /* the source file in which the token occurs */
   int ival;       /* for integer constants, store binary value here */
   double dval;	   /* for real constants, store binary value here */
   char *sval;     /* for string constants, malloc space, de-escape, store */
                   /*    the string (less quotes and after escapes) here */
};

struct tokenlist {
   struct token *t;
   struct tokenlist *next;
};

#define WORD          257

//Jzero Reserved Words
#define BOOLEAN       258
#define BREAK         259
#define CASE          260
#define CHAR          261
#define CLASS         262
#define CONTINUE      263
#define DEFAULT       264
#define DOUBLE        265
#define ELSE          266
#define FLOAT         267
#define FOR           268
#define IF            269
#define INSTANCEOF    270
#define INT           271
#define LONG          272
#define NEW           273
#define PUBLIC        274
#define RETURN        275
#define STATIC        276
#define SWITCH        277
#define VOID          278
#define WHILE         279



//Jzero Operators
#define EQUALS              280
#define PLUS                281
#define MINUS               282
#define MULTIPLY            283
#define DIVIDE              284
#define MODULO              285
#define INCREMENT           286
#define DECREMENT           287
#define IS_EQUAL_TO         288
#define NOT_EQUAL_TO        289
#define GREATER_THAN        290
#define LESS_THAN           291
#define GREATER_THAN_EQUAL  292
#define LESS_THAN_EQUAL     293
#define LOGICAL_AND         294
#define LOGICAL_OR          295
#define LOGICAL_NOT         296
#define LEFT_BRACKET        297
#define RIGHT_BRACKET       298
#define DOT                 299
#define TYPE                300

//Jzero Operators
#define LEFT_PARENTHESIS    301
#define RIGHT_PARENTHESIS   302
#define COMMA               303
#define SEMICOLON           304
#define LEFT_BRACE          305
#define RIGHT_BRACE         306
#define COLON               307

//NOT in Jzero Reserved Words
#define NOT_IN_JZERO_RESERVED   308

//NOT in Jzero Punctuation
#define INVALID_PUNCTUATION 309

#define INVALID_CHAR_LITERAL 310

//Jzero Literals
#define INTEGER_LITERAL     311
#define FLOAT_LITERAL       312
#define STRING_LITERAL      313
#define CHAR_LITERAL        314
#define BOOLEAN_LITERAL     315

#define UNRECOGNIZED_CHARACTER 316
