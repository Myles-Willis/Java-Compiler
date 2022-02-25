#include "defs.h"
#include "prodrules.h"
#include <stdarg.h>

struct tree {
   int prodrule;
   char *symbolname;
   int nkids;
   struct tree *kids[9]; /* if nkids >0 */
   struct token *leaf;   /* if nkids == 0; NULL for ε productions */
};

struct tree *allocate_tree();
struct tree *create_leaf(int category_value, char* yytext, int lineno, char* filename);
struct tree *create_branch(prodrule prodrule, char *symbolname, int nkids, ...);
void print_node(struct tree* tree);
