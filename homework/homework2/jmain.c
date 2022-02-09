#include "defs.h"
//#include "token.c"

char *filename;
//extern void handle_token(int value, char *argv[]);
void print_tokenlist(struct tokenlist* head);
void free_tokenlist(struct tokenlist* head);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
  } else {

    head_token = NULL;
    tail_token = NULL;
    filename = argv[1];

    int value = 0;

    printf("\n\nCategory\tText\t\tLineno\t\tFilename\tIval/Sval\n");
    printf("-------------------------------------------------------------------------\n");

    // Malloc tokenlist

    //YYLEX RETURNS 0 AT EOF
    while((value = yylex()) != 0) {

      struct tokenlist* temp = (struct tokenlist*)malloc(sizeof(struct tokenlist));
      temp->t = NULL;
      temp->next = NULL;

      // Create linked list of tokens
      temp->t = yytoken;
      temp->next = NULL;

      if (head_token == NULL) {
        head_token = temp;
      }

      if (tail_token != NULL) {
      	tail_token->next = temp;
      }

      tail_token = temp;

    }

  }
    print_tokenlist(head_token);
	  free_tokenlist(head_token);
    fclose(yyin);
    return 0;
}

void print_tokenlist(struct tokenlist* head) {
  //printf("in function!\n");
  struct tokenlist *current = head;

  while (current != NULL) {
    if (current->t->category == 311) {
      printf("%d\t\t%-16s%d\t\t%s\t\t%d\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->ival);
    } else if (current->t->sval != NULL) {
      printf("%d\t\t%-16s%d\t\t%s\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->sval);
    } else {
      printf("%d\t\t%-16s%d\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename);
    }
    current = current->next;
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
