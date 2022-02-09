#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "defs.h"

extern FILE *yyin;
extern int rows, words, chars;
extern int yylex();
extern char *yytext;

// extern struct token *yytoken;
struct token *yytoken;
struct tokenlist* head_token;
struct tokenlist* tail_token;
//extern void create_token();

void handle_token(int value, char *argv[]);
void print_tokenlist(struct tokenlist* head);
void free_tokenlist(struct tokenlist* head);

int main(int argc, char *argv[]) {


  head_token = NULL;
  tail_token = NULL;
  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
  } else {

    int value = 0;

    printf("\n\nCategory\tText\t\tLineno\t\tFilename\tIval/Sval\n");
    printf("-------------------------------------------------------------------------\n");

    // Malloc tokenlist

      //YYLEX RETURNS 0 AT EOF
    while((value = yylex()) != 0) {

      struct tokenlist* temp = (struct tokenlist*)malloc(sizeof(struct tokenlist));
      temp->t = NULL;
      temp->next = NULL;

      handle_token(value, argv); //need to update to handle multiple files

      //printf("yytoken after handle: %d\n", yytoken->category);

      // Create linked list of tokens
      temp->t = yytoken;
      temp->next = NULL;


      if (head_token == NULL) {
        head_token = temp;
        //tail_token = temp;
      }

      if (tail_token != NULL) {
      	tail_token->next = temp;
      }

        //tail_token->next = temp;
      tail_token = temp;

    }

  }
    print_tokenlist(head_token);
	free_tokenlist(head_token);
    fclose(yyin);
    return 0;
}

void handle_token(int value, char *argv[]) {
  int integer_literal; //need alternative, pointer to this gets overwritten
  char *string_literal;
  switch (value) {

    case NOT_IN_JZERO_RESERVED:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    case INVALID_PUNCTUATION:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    case INVALID_CHAR_LITERAL:
      printf("\n%s:%d: error: %s Invalid char literal\n\n", argv[1], rows + 1, yytext);
      exit(-1);
      break;

    case INTEGER_LITERAL:
      // Malloc new token struct for entry
      yytoken = (struct token*)malloc(sizeof(struct token));
      yytoken->category = value;
      yytoken->text = strdup(yytext);//free memory
      yytoken->lineno = rows + 1;
      yytoken->filename = argv[1]; //Need to modify to support multiple files
      integer_literal = atoi(yytext);
      yytoken->ival = integer_literal;
      yytoken->dval = 0;
      yytoken->sval = NULL;
      break;

    case STRING_LITERAL:
      // Malloc new token struct for entry
      yytoken = (struct token*)malloc(sizeof(struct token));
      yytoken->category = value;
      yytoken->text = strdup(yytext);//free memory
      yytoken->lineno = rows + 1;
      yytoken->filename = argv[1]; //Need to modify to support multiple files
      yytoken->ival = 0;
      yytoken->dval = 0;
      string_literal = yytext;
      yytoken->sval = string_literal;
      break;

    default:
      // Malloc new token struct for entry
      yytoken = (struct token*)malloc(sizeof(struct token));
      yytoken->category = value;
      yytoken->text = strdup(yytext);//free memory
      yytoken->lineno = rows + 1;
      yytoken->filename = argv[1]; //Need to modify to support multiple files
      yytoken->ival = 0;
      yytoken->dval = 0;
      yytoken->sval = NULL;
  }
}

void print_tokenlist(struct tokenlist* head) {
  //printf("in function!\n");
  struct tokenlist *current = head;

  while (current != NULL) {
    if (current->t->category == 311) {
      printf("%d\t\t%-16s%d\t\t%s\t\t%d\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->ival);
      current = current->next;
    } else if (current->t->sval != NULL) {
      printf("%d\t\t%-16s%d\t\t%s\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->sval);
      current = current->next;
    } else {
      printf("%d\t\t%-16s%d\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename);
      current = current->next;
     //printf("in print :%d\n", current->t->category);
     //current = current->next;
    }
  }
}

void free_tokenlist(struct tokenlist* head) {

  struct tokenlist *current;

  while (head != NULL) {
  	current = head;
		head = head->next;
		free(current->t->text);
		free(current->t);
		free(current);

  }
}
