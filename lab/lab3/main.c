#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yylex();
extern int yyparse();

int yyerror(char *s);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
  }

  int parseValue = yyparse();
  printf("yyparse returns %d\n", parseValue);

}

int yyerror(char *s) {
   fprintf(stderr, "%s\n", s); exit(1);
}
