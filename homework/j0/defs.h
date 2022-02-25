#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "j0gram.tab.h"

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern int yyparse();
extern int yyerror(char *s);
extern int yylineno;
extern char *yytext;
extern char *filename;

struct token *yytoken;
struct tokenlist* head_token;
struct tokenlist* tail_token;
