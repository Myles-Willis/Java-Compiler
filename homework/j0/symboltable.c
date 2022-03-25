#include "symboltable.h"

SymbolTable globals;
SymbolTable current;

char *checked_alloc(int size);

SymbolTable make_sym_table(int size, char* table_name) {

	SymbolTable table;

	table = (SymbolTable) checked_alloc(sizeof(struct sym_table));

	table->tbl = (struct sym_entry **)
		checked_alloc((unsigned int) (size * sizeof(struct sym_entry *))); //* or **?
	table->nBuckets = size;
	table->nEntries = 0;
	table->table_name = table_name;

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

int insert_symbol(SymbolTable st, char *s, typeptr t) {
	//register int i;
   	int h;
   	struct sym_entry *se;
	se = malloc(sizeof(struct sym_entry));
	memset(se, 0, sizeof(struct sym_entry));

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

void print_symbol(char *s, char *symbolname) { 		//ONLY USED IN LAB #6...

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

	printf("--- symbol table for: %s\n", st->table_name);
	int i,j;
   	SymbolTableEntry ste;
   	if (st == NULL) return;
   	for (i=0;i<st->nBuckets;i++) {
      	for (ste = st->tbl[i]; ste; ste=ste->next) {
			for (j=0; j < level; j++) printf("  ");
				/* if this symbol has a subscope,
				 print it recursively, indented*/
				if (ste->type){
					printf("PRINT!\n");
					printsymbols(ste->table, level + 1);
				} else {

					printf("%s\n", ste->s);
				}
      }
   }
}

void populate_symbol_tables(struct tree * n) {

	int i;
	if (n == NULL) return;

	/* pre-order activity */
	switch (n->prodrule) {

		/* whatever production rule(s) enter a function scope */
		case prodR_ConstructorDecl: {
			printf("prodR_ConstructorDeclarator case hit \n");
			enter_newscope(n->kids[0]->kids[0]->leaf->text, CONSTRUCT_TYPE);
			break;
		}

		case prodR_MethodDecl: {

			printf("prodR_MethodDeclarator case hit \n");
			enter_newscope(n->kids[0]->kids[2]->kids[0]->leaf->text, FUNC_TYPE);
		 	break;
		}

		case prodR_ClassDecl: {
			printf("prodR_ClassDecl case hit \n");
			enter_newscope(n->kids[2]->leaf->text, CLASS_TYPE);
			break;
		}

		// case FD_DS_FDE_CS: {
		//    	/* construct a type for this function */
		// 	n->type = alcfunctype(n->kids[0],
		//  		n->kids[1]->kids[1] /* paramlist subtree */,
		// 		NULL /* add parent symbol table */);
		//    /* enter scope, inserting this function's type into the global */
		//    enter_newscope(NULL /* function name found in $2 */, FUNC_TYPE);
		// }

		// case prodR_TypeAssignment :
		// 	// insert_symbol(current, n->kids[1]->leaf->text);
		// 	enter_newscope(n->kids[1]->leaf->text);
		// 	break;

		// case prodR_MultiVarDecls :
		// 	// insert_symbol(current, n->kids[1]->leaf->text);
		// 	enter_newscope(n->kids[1]->leaf->text);
		// 	break;

		// case /* whatever production rule(s) enter a struct scope */ : {
		//  	enter_newscope(/* label of new struct */);
		//  	break;
		// }


		/* whatever production rule(s) designate a variable declaration*/
		// case prodR_FieldDecl:
		// case prodR_LocalVarDecl:
		//LocalVarDeclStmt

		case prodR_FieldDecl:
		case prodR_LocalVarDecl: {

			printf("prodR_FieldDecl case hit \n");
		   	/* figure out which kid is a "list" of variables */
			typeptr t;
			t = alctype(NULL_TYPE);
			//struct tree *var_list = n->kids[1];
			int insert_result = insert_symbol(current, n->kids[1]->kids[0]->leaf->text, t);
			printf("Inserting %s\n", n->kids[1]->kids[0]->leaf->text);
			if (insert_result == 0) {
				fprintf(stderr, "Error: %s already exists sym_table\n"
					, n->symbolname);
			}
			/* walk through the subtree that is the list of variables */
			// for (i = 0; i < var_list->nkids; i++) {
			// 	/* for each variable, insert it into the current symbol table*/
			// 	int insert_result = insert_symbol(current, var_list->kids[i]->leaf->text);
			// 	printf("Inserting %s\n", var_list->kids[i]->leaf->text);
			// 	if (insert_result == 0) {
			// 		fprintf(stderr, "Error: %s already exists sym_table\n"
			// 			, n->symbolname);
			// 	}
			// }
			break;
		}

		// case  -10000/* whatever leaf denotes a variable name */: {
		//
		//   	//SymbolTableEntry ste = NULL;
		//   	SymbolTable st = current;
		//   	/* check if the symbol is already defined in current scope */
		// 	SymbolTableEntry checked_entry = lookup_st(st, n->symbolname);
		//   	/*   if it is, report a redeclaration error */
		// 	if (checked_entry != NULL) {
		// 		fprintf(stderr, "Redeclaration Error: %s already declared\n",
		// 	 		checked_entry->s);
		// 		exit(-1);
		// 	}
		//   	/*   if it is not, insert it into the current symbol table */
		// 	int insert_result = insert_symbol(current, n->symbolname);
		//
		// 	if (insert_result == 0) {
		// 		fprintf(stderr, "Error: %s already exists sym_table\n"
		// 			, n->symbolname);
		// 	}
		//
		// }

	}

	/* visit children */
	for (i = 0; i < n->nkids; i++)
	 	populate_symbol_tables(n->kids[i]); //compare with example file

	/* post-order activity */
	switch (n->prodrule) {
		/* we are back out to a node where we entered a subscope */

		case prodR_ConstructorDecl:
		case prodR_MethodDecl:
		case prodR_ClassDecl:
			printf("popping scope\n");
			popscope();
			break;

	}
}

// void dovariabledeclarator(struct tree * n) { //, typeptr t
// 	insert_symbol(current, n->kids[0]->leaf->text);
// }

char *checked_alloc(int size) {

	char *p = calloc(size, sizeof(char));

	if (p == NULL) {
		fprintf(stderr, "Out of memory: %d bytes requested\n", size);
		exit(-1); //proper exit value?
	}

	return p;

}

void enter_newscope(char *s, int typ) {     // , int typ
	printf("\nCurrent scope of :%s\n", current->table_name);
	/* allocate a new symbol table */
	typeptr t;
	t = alctype(typ);
	//printf("Type set to :%d\n", t->basetype);
  	SymbolTable new_st = make_sym_table(20, s);
	new_st->scope = t;
  	new_st->parent = current;


	/* insert s into current symbol table */
  	insert_symbol(current, s, t);

	/* attach new symbol table to s's symbol table in the current symbol table*/
  	lookup_st(current, s)->table = new_st;

	/* push new symbol on the stack, making it the current symbol table */
  	// new_st->parent = current;
  	// current = new_st;
  	pushscope(new_st);
	printf("Entered scope of :%s\n", current->table_name);
	printf("Type set to :%d\n", t->basetype);

}
