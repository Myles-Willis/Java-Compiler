#include <stdio.h>

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern char *yytext;

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    yylex();
    printf("\t%d\t%d\t%d\n", rows, words, chars);
    fclose(yyin);
    return 0;
}
