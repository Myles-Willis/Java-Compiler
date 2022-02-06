#include <stdio.h>

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern char *yytext;

int main(int argc, char *argv[]) {

    if (argc == 1) {
      printf("Must provide file name as command line argument\n");
      return 0;
    } else if (fopen(argv[1], "r") == NULL) {
      printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
    } else {
        yyin = fopen(argv[1], "r");
        yylex();
        printf("\t%d\t%d\t%d\n", rows, words, chars);
    }
    fclose(yyin);
    return 0;
}
