#include "defs.h"
#include "tree.h"
#include "error.h"
#include "symboltable.h"

extern int yydebug;
char *filename;
extern struct tree *root;

extern SymbolTable globals;
extern SymbolTable current;

// struct tree_list *trees;
int check_file_extension(char *file);

int main(int argc, char *argv[]) {

  //int symtab_print = 0;

  if (argc == 1) {
    printf("Must provide file name as command line argument\n");
    return 0;
  } else {
		while (--argc > 0) {
			//printf("While argv: %s\n", *++argv);
			/* if (strcmp(*++argv, "-symtab") == 0) {
				symtab_print = 1;
				continue;
			} else*/ if ((yyin = fopen(*++argv, "r")) == NULL) {
				printf("\nCan not open '%s': File does not exist\n\n", *argv);
			} else if(check_file_extension(*argv) != 1) {
		  		printf("\nCan not open '%s': File does not have .java extension\n\n", *argv);
			} else {

	    		filename = *argv;

				printf("\n\nOpened File: %s\n", filename);
				// yydebug = 1;
				yyparse();
				printf("\n");
				print_tree(root, 0);
				globals = make_sym_table(20, "global");
				current = globals;
				populate_symbol_tables(root);

				// if (symtab_print) {
					printf("\n\nprintsymbols() output:\n");
					printf("---------------------------------------\n\n");
					printsymbols(globals, 1);
				// }
				printf("\n");
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
