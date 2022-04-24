#ifndef TREE_H
#define TREE_H

#include "defs.h"
#include "token.h"
#include "tac.h"
#include <stdarg.h>

struct tree {
   int prodrule;
   char *symbolname;
   int nkids;
   struct tree *kids[9]; /* if nkids >0 */
   struct token *leaf;   /* if nkids == 0; NULL for ε productions */
   int is_const;
   struct sym_table *stab;
   struct typeinfo *type;

   struct instr *icode;
   struct addr *address;
   struct addr *first;
   struct addr *follow;
   struct addr *onTrue;
   struct addr *onFalse;

};

struct tree *allocate_tree();
struct tree *create_leaf(int category_value, char* yytext, int lineno, char* filename);
struct tree *create_branch(prodrule prodrule, char *symbolname, int nkids, ...);

int print_tree(struct tree* tree, int depth);
char* humanreadable(prodrule rule);
int free_tree(struct tree* tree, int depth);
void genfirst();

#endif
