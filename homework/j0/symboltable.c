#include "symboltable.h"

SymbolTable globals;
SymbolTable current;

char *checked_alloc(int size);

SymbolTable make_sym_table(int size) {

	SymbolTable table;

	table = (SymbolTable) checked_alloc(sizeof(struct sym_table));

	table->tbl = (struct sym_entry **)
		checked_alloc((unsigned int) (size * sizeof(struct sym_entry *))); //* or **?
	table->nBuckets = size;
	table->nEntries = 0;

	return table;

}

int hash(SymbolTable st, char *s) {

	register int h = 0;
	register char c;

	while ((c = *s++)) {
		h += c & 0377;
		h *= 37;
	}

	if (h < 0) h = -h;
		return h % st->nBuckets;

}

int insert_symbol(SymbolTable st, char *s) { // removed typeptr t for now.
	//register int i;
   	int h;
   	struct sym_entry *se;
	se = malloc(sizeof(struct sym_entry));
	memset(se, 0, sizeof(struct sym_entry));
   	//int l;

   	h = hash(st, s);
   	for (se = st->tbl[h]; se != NULL; se = se->next)
      	if (!strcmp(s, se->s)) {
         	/*
          	* A copy of the string is already in the table.
          	*/
         	return 0;
        }

   	/*
    	* The string is not in the table. Add the copy from the
    	*  buffer to the table.
    */

   	se = (SymbolTableEntry) checked_alloc((unsigned int) sizeof (struct sym_entry));
   	se->next = st->tbl[h];
   	se->table = st;
   	st->tbl[h] = se;
   	se->s = strdup(s);
   	//se->type = t;    // add back function param upon implementation
   	st->nEntries++;
   	return 1;
}

SymbolTableEntry lookup_st(SymbolTable st, char *s) {
   	//register int i;
   	int h;
   	SymbolTableEntry se;

   	h = hash(st, s);
   	for (se = st->tbl[h]; se != NULL; se = se->next)
      	if (!strcmp(s, se->s)) {
         	/*
         	*  Return a pointer to the symbol table entry.
         	*/
        	return se;
        }
   	return NULL;
}

void print_symbol(char *s, char *symbolname) { 		//ONLY USED IN LAB #6

   printf("%s : %s\n", symbolname, s); fflush(stdout);

}

void printsyms(struct tree * n) {

	//printf("Printing Symbols\n");
	int i;
	if (n == NULL) return;

	switch (n->prodrule) {
		case prodR_VarDecls : {
			print_symbol(n->kids[0]->leaf->text, n->symbolname);
			// printf("%s\n", n->kids[0]->leaf->text);
			break;}

		case prodR_MultiVarDecls : {
			print_symbol(n->kids[1]->leaf->text, n->symbolname);
			break;}

		case prodR_MethodDeclarator : {
			print_symbol(n->kids[0]->leaf->text, n->symbolname);
			break;}

		case prodR_TypeAssignment : {
			print_symbol(n->kids[1]->leaf->text, n->symbolname);
			break;}
	}

	for (i = 0; i < n->nkids; i++) {
		printsyms(n->kids[i]);
	}

}

void printsymbols(SymbolTable st, int level) {
	int i, j;
   	SymbolTableEntry ste;
   	if (st == NULL) return;
   	for (i=0;i<st->nBuckets;i++) {
      	for (ste = st->tbl[i]; ste; ste=ste->next) {
	 	for (j=0; j < level; j++) printf("  ");
	 	printf("%s\n", ste->s);

	 	/* if this symbol has a subscope, print it recursively, indented
	 	printsymbols( // subscope symbol table
                    	, level+1);
          	*/
      }
   }
}

void populate_symbol_tables(struct tree * n) {

	int i;
	if (n == NULL) return;

	/* pre-order activity */
	switch (n->prodrule) {

		case prodR_MethodDeclarator/* whatever production rule(s) enter a function scope */ : {
			//enter_newscope(/* name of new function, from some leaf*/);
			insert_symbol(current, n->kids[0]->leaf->text);
		 	break;
		}

		case prodR_TypeAssignment :
			insert_symbol(current, n->kids[1]->leaf->text);
			break;

		case prodR_MultiVarDecls :
			insert_symbol(current, n->kids[1]->leaf->text);
			break;

		// case /* whatever production rule(s) enter a struct scope */ : {
		//  	enter_newscope(/* label of new struct */);
		//  	break;
		// }

		case prodR_VarDecls /* whatever production rule(s) designate a variable declaration*/: {

		   	/* figure out which kid is a "list" of variables */
		   	/* walk through the subtree that is the list of variables */
		    /* for each variable, insert it into the current symbol table*/

			int insert_result = insert_symbol(current, n->kids[0]->leaf->text);

			if (insert_result == 0) {
				fprintf(stderr, "Error: %s already exists sym_table\n"
					, n->symbolname);
			}

			break;
		}

		case  -10000/* whatever leaf denotes a variable name */: {
		  	//SymbolTableEntry ste = NULL;
		  	SymbolTable st = current;
		  	/* check if the symbol is already defined in current scope */
			SymbolTableEntry checked_entry = lookup_st(st, n->symbolname);
		  	/*   if it is, report a redeclaration error */
			if (checked_entry != NULL) {
				fprintf(stderr, "Redeclaration Error: %s already declared\n",
			 		checked_entry->s);
				exit(-1);
			}
		  	/*   if it is not, insert it into the current symbol table */
			int insert_result = insert_symbol(current, n->symbolname);

			if (insert_result == 0) {
				fprintf(stderr, "Error: %s already exists sym_table\n"
					, n->symbolname);
			}

		}

	}

	/* visit children */
	for (i = 0; i < n->nkids; i++)
	 	populate_symbol_tables(n->kids[i]); //compare with example file

	/* post-order activity */
	// switch (n->prodrule) {
	//
	// 	case /* we are back out to a node where we entered a subscope */:
	// 	popscope();
	// 	break;
	//
	// }
}


char *checked_alloc(int size) {

	char *p = calloc(size, sizeof(char));

	if (p == NULL) {
		fprintf(stderr, "Out of memory: %d bytes requested\n", size);
		exit(-1); //proper exit value?
	}

	return p;

}
