#include "type.h"
#include "symboltable.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo char_type = { CHAR_TYPE };
struct typeinfo class_type = { CLASS_TYPE };
struct typeinfo func_type = { FUNC_TYPE };
struct typeinfo construct_type = { CONSTRUCT_TYPE };

typeptr null_typeptr = &null_type;
typeptr integer_typeptr = &integer_type;
typeptr double_typeptr = &double_type;
typeptr char_typeptr = &char_type;
typeptr class_typeptr = &class_type;
typeptr func_typeptr = &func_type;
typeptr construct_typeptr = &construct_type;

char *typenam[] =
   {"null", "int", "double", "function", "class", "constructor", "char",
    "boolean", "String", "name"};

int typenamSize = 10;

typeptr alctype(int base) {

   typeptr rv;
   if (base == NULL_TYPE) return null_typeptr;
   else if (base == INT_TYPE) return integer_typeptr;
   else if (base == DOUBLE_TYPE) return double_typeptr;
   else if (base == CHAR_TYPE) return char_typeptr;
   else if (base == CLASS_TYPE) return class_typeptr;
   else if (base == FUNC_TYPE) return func_typeptr;

   rv = (typeptr) calloc(1, sizeof(struct typeinfo));
   if (rv == NULL) return rv;
   rv->basetype = base;

   return rv;
}

/* in order for this to make any sense, you have to pass in the subtrees
 * for the return type (r) and the parameter list (p), but the calls to
 * to this function in the example are just passing NULL at present!
 */
typeptr alcfunctype(struct tree * r, struct tree * p, SymbolTable st) {

   typeptr rv = alctype(FUNC_TYPE);
   if (rv == NULL) return NULL;
   rv->u.f.st = st;
   /* fill in return type and paramlist by traversing subtrees */
   /* rf->u.f.returntype = ... */
   return rv;
}

char *typename(typeptr t) {

   if (!t) return "(NULL)";
   else if (t->basetype < FIRST_TYPE || t->basetype > LAST_TYPE)
      return "(BOGUS)";
   else return typenam[t->basetype-1000000];

}

int conv_to_type(char* type_string) {

	for (int i = 0; i < (typenamSize - 1); i++) {
		if (strcmp(typenam[i], type_string) == 0) {
			
			switch (i) {
				case 1:
					return INT_TYPE;
					break;
				case 2:
					return DOUBLE_TYPE;
					break;
				case 7:
					return BOOL_TYPE;
					break;
				case 8:
					return STRING_TYPE;
					break;
				case 9:
					return NAME_TYPE;
					break;
				case 6:
					return CHAR_TYPE;
					break;
			}
		}
	}
	return NULL_TYPE;
}
