#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern char *yytext;

int main(int argc, char *argv[]) {

  yyin = fopen(argv[1], "r");
  int value = 0;

    //YYLEX RETURNS 0 AT EOF
    while((value = yylex()) != 0) {
      if (value == 308) {
        printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
        exit(-1);
      } else if (value == 309) {
        printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
        exit(-1);
      } else if (value == 310) {
        printf("\n%s:%d: error: %s Invalid char literal\n\n", argv[1], rows + 1, yytext);
        exit(-1);
      } else {
        printf("Code: %d \t yytext: %s\n",value, yytext);
      }
    }

    fclose(yyin);
    return 0;
}
