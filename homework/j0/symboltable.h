#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "prodrules.h"
#include "tree.h"

typedef struct sym_table {
  	int nBuckets;			/* # of buckets */
  	int nEntries;			/* # of symbols in the table */
	//struct sym_table *parent;		/* enclosing scope, superclass etc. */
  	struct sym_entry **tbl;
  	/* more per-scope/per-symbol-table attributes go here */
} *SymbolTable;

typedef struct sym_entry {
   SymbolTable table;	//what symbol table do we belong to
   char *s;				/* string */
   // more symbol attributes go here for code generation
   struct sym_entry *next;
   } *SymbolTableEntry;


SymbolTable make_sym_table(int size);
int insert_symbol(SymbolTable st, char *s); //removed typeptr t for now
void populate_symbol_tables(struct tree * n);

extern SymbolTable globals;	       /* global symbols */
extern SymbolTable current;	       /* current */

void print_symbol(char *s, char *symbolname); //ONLY USED IN LAB #6
void printsyms(struct tree *); //ONLY USED IN LAB #6
void printsymbols(SymbolTable st, int level);

#endif
