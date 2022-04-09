#ifndef TYPE_H
#define TYPE_H

#include "tree.h"

typedef struct param {
	char *name;
	int position;
	struct typeinfo *type;
	struct param *next;
} *paramlist;

struct field {			/* members (fields) of structs */
	char *name;
	struct typeinfo *elemtype;
};

/* base types. How many more base types do we need? */
#define FIRST_TYPE   1000000

#define NULL_TYPE    1000000
#define INT_TYPE     1000001
#define DOUBLE_TYPE  1000002
#define FUNC_TYPE    1000003
#define CLASS_TYPE   1000004
#define CONSTRUCT_TYPE   1000005
#define CHAR_TYPE    1000006
#define BOOL_TYPE	 1000007
#define STRING_TYPE  1000008
#define NAME_TYPE    1000009
#define FLOAT_TYPE 1000010
#define VOID_TYPE 1000011

#define LAST_TYPE    1000011

typedef struct typeinfo {
	int basetype;
	struct sym_table *type_sym_table;

	union {
		struct arrayinfo {
			int size;
			struct typeinfo *elemtype;
		}a;
		struct funcinfo {
			char *name; /* ? */
			int defined; /* 0 == prototype, 1 == not prototype */
			struct sym_table *st;
			struct typeinfo *returntype;
			int nparams;
			int has_param;
			struct param *parameters;
		}f;
		struct classinfo {
			char *name; /* ? */
			struct sym_table *st;
			// struct typeinfo *paramtype;
			// struct param *methods;
			// struct field *fields
			//lists of zero or more fields, methods, and constructors
		}c;

	} u;
} *typeptr;

extern struct typeinfo integer_type;
extern struct sym_table *globals;

typeptr alctype(int);
int conv_to_type(char* type_string);
char *typename(typeptr t);
typeptr alcclasstype(struct sym_table * st);
typeptr alcfunctype(struct sym_table * st);
typeptr determinetype(struct tree *t);
void check_types(struct tree *t);
void assigntype(typeptr t);

extern typeptr integer_typeptr;
extern typeptr null_typeptr;
extern typeptr string_typeptr;
extern typeptr double_typeptr;
extern typeptr float_typeptr;
extern typeptr void_typeptr;
extern typeptr char_typeptr;
// extern typeptr class_typeptr;
// extern typeptr func_typeptr;
extern typeptr construct_typeptr;

extern char *typenam[];

#endif
