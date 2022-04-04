#ifndef DOT_H
#define DOT_H

#include "defs.h"
#include "tree.h"

extern const char* yyname(int sym);

int dot_serialId;
void print_graph(struct tree* tree);
int print_graph2(struct tree* tree, FILE *dotFile, int parent_serialId);

#endif
