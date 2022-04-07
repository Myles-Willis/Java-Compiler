#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "type.h"

typedef struct sym_table {
	char* table_name;
  	int nBuckets;			/* # of buckets */
  	int nEntries;			/* # of symbols in the table */
	struct sym_table *parent;		/* enclosing scope, superclass etc. */
	struct typeinfo *scope;			/* what type do we belong to? class/method? */
  	struct sym_entry **tbl;
  	/* more per-scope/per-symbol-table attributes go here */
} *SymbolTable;

typedef struct sym_entry {
   SymbolTable table;	//what symbol table do we belong to
   char *s;				/* string */
   // more symbol attributes go here for code generation
   struct typeinfo *type;
   struct sym_entry *next;
   } *SymbolTableEntry;


SymbolTable make_sym_table(int size, char *table);

void populate_symbol_tables(struct tree * n);
// void dovariabledeclarator(struct tree * n);

extern SymbolTable globals;	       /* global symbols */
extern SymbolTable current;	       /* current */

void printsymbols(SymbolTable st, int level);
SymbolTableEntry lookup_st(SymbolTable st, char *s);

void enter_newscope(char *s, int typ, struct tree * n);
int insert_symbol(SymbolTable st, char *s, typeptr t);
void load_builtins();

#define pushscope(stp) do { stp->parent = current; current = stp; } while (0)
#define popscope() do { current = current->parent; } while(0)

#endif
