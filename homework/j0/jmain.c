#include "defs.h"
#include "tree.h"
#include "error.h"
#include "symboltable.h"
#include "dot.h"

extern int yydebug;
char *filename;
extern struct tree *root;

extern SymbolTable globals;
extern SymbolTable current;

// struct tree_list *trees;
int check_file_extension(char *file);

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else {
		while (--argc > 0) {
			if ((yyin = fopen(*++argv, "r")) == NULL) {
				printf("\nCan not open '%s': File does not exist\n\n", *argv);
			} else if(check_file_extension(*argv) != 1) {
		  		printf("\nCan not open '%s': File does not have .java extension\n\n", *argv);
			} else {

	    		filename = *argv;

				// initialize trees linked list.
				// trees = malloc(sizeof (struct tree_list));
				// memset(trees, 0, sizeof(struct tree_list));

				printf("\nBeginning Parse of: %s\n", filename);
				// yydebug = 1;
				yyparse();
				printf("\n");
				print_tree(root, 0);
				printf("\nprint_symbols() output:\n\n");
				printsyms(root);
				globals = make_sym_table(20);
				current = globals;
				// printf("\nSymbol table output:\n\n");
				// populate_symbol_tables(root);
				// printsymbols(globals, 1);
				// printf("\n");
				print_graph(root);
				// populate_symbol_tables(root);
				//free_tree(root, 0);
			}
		}
	}
}

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
