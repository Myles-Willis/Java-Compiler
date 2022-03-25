#ifndef TYPE_H
#define TYPE_H

#include "tree.h"
// #include "token.h"
// #include "j0gram.tab.h"
// #include "symboltable.h"
// #include "defs.h"

typedef struct param {
	char *name;
	struct type *type;
	struct param *next;
} *paramlist;

struct field {			/* members (fields) of structs */
	char *name;
	struct type *elemtype;
};

/* base types. How many more base types do we need? */
#define FIRST_TYPE   1000000

#define NULL_TYPE    1000000
#define INT_TYPE     1000001
#define DOUBLE_TYPE  1000002
#define FUNC_TYPE    1000003
#define CLASS_TYPE   1000006
#define CONSTRUCT_TYPE   1000007
#define CHAR_TYPE    1000008

#define LAST_TYPE    1000008

typedef struct typeinfo {
	int basetype;
	union {
		struct arrayinfo {
			int size;
			struct type *elemtype;
		}a;
		struct funcinfo {
			char *name; /* ? */
			int defined; /* 0 == prototype, 1 == not prototype */
			struct sym_table *st;
			struct type *returntype;
			int nparams;
			struct param *parameters;
		}f;
		struct classinfo {
			char *name; /* ? */
			int defined; /* 0 == prototype, 1 == not prototype */
			struct sym_table *st;
			int nparams;
			struct param *parameters;
		}c;

	} u;
} *typeptr;

extern struct sym_table *globals;

typeptr alctype(int);
typeptr alcclasstype(struct tree * r, struct tree * p, struct sym_table * st);
typeptr alcfunctype(struct tree * r, struct tree * p, struct sym_table * st);
char *typename(typeptr t);

extern typeptr integer_typeptr;
extern typeptr double_typeptr;
extern typeptr char_typeptr;
extern typeptr null_typeptr;
extern typeptr string_typeptr;
extern typeptr class_typeptr;
extern typeptr func_typeptr;
extern typeptr construct_typeptr;

extern char *typenam[];

#endif
