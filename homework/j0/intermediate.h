#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "tac.h"
#include "symboltable.h"

void gen_intermediate_code (struct tree *n);
struct addr *newtemp(int num_bytes);
int print_intermediate_tree(struct tree* tree, int depth);

#endif
