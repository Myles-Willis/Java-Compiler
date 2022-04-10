#ifndef ERROR_H
#define ERROR_H

#include "defs.h"
int yyerror(const char *s);
void print_error(char *errorMsg);
void throw_semantic_error(char *errorMsg, int line);
void throw_lexical_error(char *errorMsg);
void throw_syntax_error(char *errorMsg);
void throw_error(char *errorMsg);

#endif
