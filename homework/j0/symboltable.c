#include "symboltable.h"

#define SBufSize 1024               /* initial size of the string buffer */

/*
 * str_buf references a string buffer. Strings are built a
 *  character at a time. When a buffer "fragment" is filled,
 *  another is allocated and the the current string copied to it.
 */
struct str_buf_frag {
   struct str_buf_frag *next;     /* next buffer fragment */
   char s[1];                     /* variable size buffer */
};

struct str_buf {
   unsigned int size;             /* total size of current buffer */
   char *p;                       /* next free character in buffer */
   char *end;                     /* end of current buffer */
   struct str_buf_frag *frag_lst; /* list of buffer fragments */
};

static struct str_buf buf;
SymbolTable stringpool;

SymbolTable globals;
SymbolTable current;


void init_sbuf(struct str_buf *);   /* initialize an sbuf struct */
void clear_sbuf(struct str_buf *);  /* free struct buffer storage */
void new_sbuf(struct str_buf *);    /* allocate add'l buffer */
char *checked_alloc(int size);

/*
* init_sbuf - initialize a new sbuf struct, allocating an initial buffer.
*/
void init_sbuf(struct str_buf *sbuf) {
	sbuf->size = SBufSize;
	sbuf->frag_lst = (struct str_buf_frag *)checked_alloc((unsigned int)
	(sizeof(struct str_buf_frag) + (SBufSize - 1)));
	sbuf->frag_lst->next = NULL;
	sbuf->p = sbuf->frag_lst->s;
	sbuf->end = sbuf->p + SBufSize;
}

/*
* clear_sbuf - free string buffer storage.
*/
void clear_sbuf(struct str_buf *sbuf) {
	struct str_buf_frag *sbf, *sbf1;

	for (sbf = sbuf->frag_lst; sbf != NULL; sbf = sbf1) {
		sbf1 = sbf->next;
		free((char *)sbf);
	}
	sbuf->frag_lst = NULL;
	sbuf->p = NULL;
	sbuf->end = NULL;
}

/*
* new_sbuf - allocate a new buffer for a sbuf struct, copying the
*   partially created string from the end of full buffer to the new one.
*/
void new_sbuf(struct str_buf *sbuf) {
	struct str_buf_frag *sbf;

	/*
	* The new buffer is larger than the old one to insure that any
	*  size string can be buffered.
	*/
	sbuf->size *= 2;
	sbf = (struct str_buf_frag *)checked_alloc((unsigned int)
	(sizeof(struct str_buf_frag) + (sbuf->size - 1)));
	sbf->next = sbuf->frag_lst;
	sbuf->frag_lst = sbf;
	sbuf->p = sbf->s;
	sbuf->end = sbuf->p + sbuf->size;
}


static char *insert_sbuf(struct str_buf *sb, char *s) {
	char *rv;
	int l = strlen(s);
	if (sb->p + l + 1 >= sb->end)
	new_sbuf(sb);
	strcpy(sb->p, s);
	rv = sb->p;
	sb->p += l + 1;
	return rv;
}

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

	printf("inserting for %s inside %s\n", s, st->table_name);

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
	printf("\t%s->table = %s\n", s,st->table_name);
   	st->tbl[h] = se;
   	if (st ==stringpool) se->s = insert_sbuf(&buf, s);
   	else se->s = s;
   	// se->s = strdup(s);
	se->type = t;

	//Debugging print
	printf("\t%s->type = %s\n", s,typename(t));
	if ((t->basetype == CLASS_TYPE) || (t->basetype == FUNC_TYPE)) {
		printf("\t%s->type->type_sym_table = %s\n", s, t->type_sym_table->table_name);
	}

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
	printf("\t%s NOT FOUND in %s\n", s, st->table_name);
   	return NULL;
}

// void print_symbol(char *s, char *symbolname) { 		//ONLY USED IN LAB #6...
//
//    printf("%s : %s\n", symbolname, s); fflush(stdout);
//
// }

void printsymbols(SymbolTable st, int level) {

	// printf("--- symbol table for: %s\n", st->table_name);
	//
	int i,j;
   	SymbolTableEntry ste;
   	if (st == NULL) return;
   	for (i=0;i<st->nBuckets;i++) {
      	for (ste = st->tbl[i]; ste; ste=ste->next) {

			for (j=0; j < level; j++) printf("  ");
			printf("%s %s\n", typename(ste->type),ste->s);
			for (j=0; j < level; j++) printf("  ");
			// printf("Belongs to: %s\n", ste->table->table_name);

			/* if this symbol has a subscope,
			 print it recursively, indented*/
			if (!ste->type) continue;

			switch (ste->type->basetype) {
				case CLASS_TYPE:
				case FUNC_TYPE:
					for (j=0; j < level+1; j++) printf("  ");
					printf("--- symbol table for: %s %s ---\n", typename(ste->type), ste->s);
					for (j=0; j < level+1; j++) printf("  ");
					// printf("now printing symbols for %s\n", ste->type->type_sym_table->table_name);
					printsymbols(ste->type->type_sym_table, level + 1);
					for (j=0; j < level+1; j++) printf("  ");
					printf("-----\n");
					break;
			}
      }
   }
}

void redeclaration_error(struct token *t) {

	fprintf(stderr, "\n%s:%d: semantic error: Redeclaration of variable: %s \n\n"
		, t->filename, t->lineno, t->text);

	exit(3);
}

void undeclared_error(struct token *t) {

	fprintf(stderr, "\n%s:%d: semantic error: Undeclared of variable: %s \n\n"
		, t->filename, t->lineno, t->text);

	exit(3);
}

void populate_symbol_tables(struct tree * n) {

	int i;
	if (n == NULL) return;

	/* pre-order activity */
	switch (n->prodrule) {

		case prodR_ConstructorDecl: {

			if (lookup_st(current, n->kids[0]->kids[0]->leaf->text)) {
				redeclaration_error(n->kids[0]->kids[0]->leaf);
			}
			enter_newscope(n->kids[0]->kids[0]->leaf->text, CONSTRUCT_TYPE);
			break;
		}

		case prodR_MethodDecl: {

			printf("Method Declaration found for: %s\n", n->kids[0]->kids[2]->kids[0]->leaf->text);
			printf("\tvvv redeclaration check\n");
			if (lookup_st(current, n->kids[0]->kids[2]->kids[0]->leaf->text)) {
				redeclaration_error(n->kids[0]->kids[2]->kids[0]->leaf);
			}
			enter_newscope(n->kids[0]->kids[2]->kids[0]->leaf->text, FUNC_TYPE);
		 	break;
		}

		case prodR_ClassDecl: {

			if (lookup_st(current, n->kids[2]->leaf->text)) {
				redeclaration_error(n->kids[2]->leaf);
			}
			enter_newscope(n->kids[2]->leaf->text, CLASS_TYPE);
			break;
		}

		case prodR_FieldDecl:
		case prodR_LocalVarDecl: {

			typeptr t = alctype(conv_to_type(n->kids[0]->leaf->text));
			int insert_result = insert_symbol(current,
				 n->kids[1]->kids[0]->leaf->text, t);

			 SymbolTableEntry testing = malloc(sizeof(SymbolTableEntry));
			 testing = lookup_st(current, n->kids[1]->kids[0]->leaf->text);

			 if(testing == NULL) {
				 printf("NULL!\n");
			 } else {
				 printf("\tPOPInserted: %s to %s\n", testing->s, current->table_name);
			 }


			if (insert_result == 0) {
				redeclaration_error(n->kids[1]->kids[0]->leaf);
			}
			break;
		}

		case prodR_TypeAssignment:
		case prodR_FormalParm: {

			typeptr t = alctype(conv_to_type(n->kids[0]->leaf->text));
			int insert_result = insert_symbol(current,
				 n->kids[1]->leaf->text, t);

			SymbolTableEntry testing = malloc(sizeof(SymbolTableEntry));
			testing = lookup_st(current, n->kids[1]->leaf->text);

			if(testing == NULL) {
				printf("NULL!\n");
			} else {
				printf("\tPOPInserted: %s to %s\n", testing->s, current->table_name);
			}

			// printf("Inserted: %s to %s\n", testing->s, current->table_name);
			// struct sym_entry *test = malloc(sizeof(struct sym_entry));
			// test = lookup_st(current, "a");
			//
			// printf("Found %s in table: %s\n", test->s, test->table->table_name);

			if (insert_result == 0) {
				redeclaration_error(n->kids[1]->leaf);
			}
			break;
		}
	}

	/* visit children */
	for (i = 0; i < n->nkids; i++)
	 	populate_symbol_tables(n->kids[i]);

	/* post-order activity */
	switch (n->prodrule) {

		/* we are back out to a node where we entered a subscope */
		case prodR_ConstructorDecl:
		case prodR_MethodDecl:
		case prodR_ClassDecl:
			popscope();
			printf("popping scope, now in scope: %s\n", current->table_name);
			break;
	}
}

char *checked_alloc(int size) {

	char *p = calloc(size, sizeof(char));

	if (p == NULL) {
		fprintf(stderr, "Out of memory: %d bytes requested\n", size);
		exit(-1); //proper exit value?
	}

	return p;
}

void enter_newscope(char *s, int typ) {

	printf("enterScope for: %s\n", s);
	/* allocate a new symbol table */
  	SymbolTable new_st = make_sym_table(20, s);
	struct typeinfo *t;

	if (typ == CLASS_TYPE) {
		t = alcclasstype(new_st);
	} else {
		t = alcfunctype(new_st);
	}
	// if (t->type_sym_table == NULL) {
	// 	printf("***FRESH*** symtab for %s\n", s);
	// } else if (t->type_sym_table != NULL) {
	// 	printf("***EXISTING*** symtab for %s\n", s);
	// 	printf("***%s***\n", t->type_sym_table->table_name);
	// }
	t->type_sym_table = new_st;
	new_st->scope = t;

	// new_st->parent = current;
	// printf("set parent table to %s\n", new_st->parent->table_name);

	/* insert s into current symbol table */
  	insert_symbol(current, s, t);

	SymbolTableEntry testing = malloc(sizeof(SymbolTableEntry));
	testing = lookup_st(current, s);

	if(testing == NULL) {
		printf("NULL!\n");
	} else {
		printf("\tENTERInserted: %s to %s\n", testing->s, current->table_name);
	}

	/* attach new symbol table to s's symbol table in the current symbol table*/
  	// lookup_st(current, s)->table = new_st;


	/* push new symbol on the stack, making it the current symbol table */
  	pushscope(new_st);
	printf("Scope pushed. Now in scope of: %s\n", current->table_name);
}

// void load_builtins() {
//
// }
