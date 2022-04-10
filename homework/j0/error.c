#include "error.h"

void print_error(char *errorMsg) {
	printf("\n%s:%d: error: '%s' %s\n\n", filename, yylineno, yytext, errorMsg);
}

int yyerror(const char *s) {
   fprintf(stderr, "\n%s:%d: error: %s with token: %s \n\n", filename,
	  yylineno, s, yytext);
	  exit(2);
}

void throw_semantic_error(char *errorMsg, int line) {
	fprintf(stderr, "\n%s:%d: semantic error: %s\n\n", filename,
	   line, errorMsg);
	   exit(3);
}

void throw_lexical_error(char *errorMsg) {
	fprintf(stderr, "\n%s:%d: lexical error: '%s' %s\n\n", filename,
	   yylineno, yytext, errorMsg);
	   exit(1);
}

void throw_syntax_error(char *errorMsg) {
	fprintf(stderr, "\n%s:%d: syntax error: %s with: %s \n\n", filename,
	   yylineno, errorMsg, yytext);
	   exit(2);
}

void throw_error(char *errorMsg) {
	fprintf(stderr, "\nerror: %s\n\n", errorMsg);
	   exit(-1);
}
