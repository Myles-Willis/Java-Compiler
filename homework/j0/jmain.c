#include "defs.h"
#include "tree.h"
#include "j0gram.tab.h"

// include and set yydebug to 1 to enable error tracing
extern int yydebug;
char *filename;
extern struct tree *root;

void free_tokenlist(struct tokenlist* head);
int check_file_extension(char *file);
int yyerror(char *s);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else if ((yyin = fopen(argv[1], "r")) == NULL) {
    printf("\nCan not open '%s': File does not exist\n\n", argv[1]);
  } else if (check_file_extension(argv[1]) != 1) {
    printf("\nCan not open '%s': File does not have .java extension\n\n", argv[1]);
  } else {

    head_token = NULL;
    tail_token = NULL;
    filename = argv[1];

    // printf("\n\nPrinting Tree Nodes After Allocation of Each\n");
    // printf("-------------------------------------------------------------------------\n");
    // printf("Category\tText\t\tLineno\t\tFilename\tIval/Sval\n");
    // printf("-------------------------------------------------------------------------\n");

		//yydebug = 1;
		yyparse();
		printf("\n");
		print_tree(root, 0);
		printf("\n");

	}
}

int yyerror(char *s) {
   fprintf(stderr, "%s\n", s); exit(1);
}

// void print_tokenlist(struct tokenlist* head) {
//   //printf("in function!\n");
//   struct tokenlist *current = head;
//
//   while (current != NULL) {
//     if (current->t->category == INTLIT) {
//       printf("%d\t\t%-16s%d\t\t%s\t\t%d\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->ival);
//     } else if (current->t->category == STRINGLIT) {
//       printf("%d\t\t%-16s%d\t\t%s\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->sval);
//     } else if (current->t->category == REALLIT){
//       printf("%d\t\t%-16s%d\t\t%s\t\t%f\n", current->t->category, current->t->text, current->t->lineno, current->t->filename, current->t->dval);
//     } else {
//       printf("%d\t\t%-16s%d\t\t%s\n", current->t->category, current->t->text, current->t->lineno, current->t->filename);
//     }
//     current = current->next;
//   }
// }

// void free_tokenlist(struct tokenlist* head) {
//
//   struct tokenlist *current;
//
//   while (head != NULL) {
//   	current = head;
// 		head = head->next;
// 		free(current->t->text);
// 		free(current->t);
// 		free(current);
//   }
// }

int check_file_extension(char *file) {
  if (strlen(file) >= 6) {
    char *dot_javaLocation = (strlen(file) - 5) + file;
    if (strcmp(dot_javaLocation, ".java") != 0) {
      return 0;
    } else {
      return 1;
    }
  }

  return 0;
}
