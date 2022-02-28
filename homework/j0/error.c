#include "error.h"

void print_error(char *errorMsg) {
	printf("\n%s:%d: error: '%s' %s\n\n", filename, yylineno, yytext, errorMsg);
}

int yyerror(const char *s) {
   fprintf(stderr, "\n%s:%d: error: %s with token: %s \n\n", filename,
	  yylineno, s, yytext);
	  exit(2);
}
