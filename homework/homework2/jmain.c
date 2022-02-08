#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern char *yytext;

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

struct token *yytoken;

void handle_token(int value, char *argv[]);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else if (fopen(argv[1], "r") == NULL) {
    printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
  } else {
    yyin = fopen(argv[1], "r");
    int value = 0;

    printf("\n\nCategory\tText\t\tLineno\t\tFilename\tIval/Sval\n");
    printf("-------------------------------------------------------------------------\n");

    // if ((value = yylex()) != 0) {
    //   handle_token(value, argv);
    // }

    //set the initial token to the first call to yylex()
    //head->t = yytoken;


    // Malloc tokenlist
    struct tokenlist* head_token = (struct tokenlist*)malloc(sizeof(struct tokenlist));
    struct tokenlist* tail_token = (struct tokenlist*)malloc(sizeof(struct tokenlist));

      //YYLEX RETURNS 0 AT EOF
    while((value = yylex()) != 0) {

      struct tokenlist* temp = (struct tokenlist*)malloc(sizeof(struct tokenlist));
      handle_token(value, argv);

      // Assign to temporary struct from global yytoken
      temp->t = yytoken;
      temp->next = NULL;

      if (tail_token == NULL) {
        head_token = temp;
        tail_token = temp;
      } else {
        tail_token->next = temp;
        tail_token = temp;
      }
    }
  }

    fclose(yyin);
    return 0;
}

void handle_token(int value, char *argv[]) {
  switch (value) {

    case 308:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    case 309:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    case 310:
      printf("\n%s:%d: error: %s Invalid char literal\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    default:
      // Malloc new token struct for entry
      yytoken = (struct token*)malloc(sizeof(struct token));
      yytoken->category = value;
      yytoken->text = yytext;
      yytoken->lineno = rows + 1;
      yytoken->filename = argv[1]; //Need to modify to support multiple files

      //printf("%d\t\t%s\t\t%d\t\t%s\n",value, yytext, rows + 1, argv[1]);
      printf("linkedlist: %d\t\t%s\t\t%d\t\t%s\n",yytoken->category, yytoken->text, yytoken->lineno, yytoken->filename);
  }
}
