#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "tac.h"
#include "symboltable.h"

void gen_intermediate_code (struct tree *n);
void gentoken(struct tree *n);
void gen_qualified_addr(struct tree *name_head);
struct instr *gen_arglist(struct tree *arglist);
int set_identifier_addr(struct tree *n);
struct addr *newtemp(int num_bytes);
int print_intermediate_tree(struct tree* tree, int depth);

#endif
