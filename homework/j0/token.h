#include "defs.h"

struct token {
   int category;   /* the integer code returned by yylex */
   char *text;     /* the actual string (lexeme) matched */
   int lineno;     /* the line number on which the token occurs */
   char *filename; /* the source file in which the token occurs */
   int ival;       /* for integer constants, store binary value here */
   double dval;	   /* for real constants, store binary value here */
   char *sval;     /* for string constants, malloc space, de-escape, store */
                   /* the string (less quotes and after escapes) here */
};

struct tokenlist {
   struct token *t;
   struct tokenlist *next;
};

struct token *allocate_token();
int handle_token(int category_value);
