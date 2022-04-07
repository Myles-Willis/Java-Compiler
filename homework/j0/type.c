#include "type.h"
#include "symboltable.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo float_type = { FLOAT_TYPE };
struct typeinfo char_type = { CHAR_TYPE };
struct typeinfo class_type = { CLASS_TYPE };
struct typeinfo func_type = { FUNC_TYPE };
struct typeinfo construct_type = { CONSTRUCT_TYPE };

typeptr null_typeptr = &null_type;
typeptr integer_typeptr = &integer_type;
typeptr double_typeptr = &double_type;
typeptr float_typeptr = &float_type;
typeptr char_typeptr = &char_type;
typeptr class_typeptr = &class_type;
typeptr func_typeptr = &func_type;
typeptr construct_typeptr = &construct_type;

char *typenam[] =
   {"null", "int", "double", "function", "class", "constructor", "char",
    "boolean", "String", "name", "float"};

int typenamSize = 11;

typeptr alctype(int base) {

   typeptr rv;
   if (base == NULL_TYPE) return null_typeptr;
   else if (base == INT_TYPE) return integer_typeptr;
   else if (base == DOUBLE_TYPE) return double_typeptr;
   else if (base == FLOAT_TYPE) return float_typeptr;
   else if (base == CHAR_TYPE) return char_typeptr;
   // else if (base == CLASS_TYPE) return class_typeptr;
   // else if (base == FUNC_TYPE) return func_typeptr;

   rv = (typeptr) calloc(1, sizeof(struct typeinfo));
   if (rv == NULL) return rv;
   rv->basetype = base;

   return rv;
}

/* in order for this to make any sense, you have to pass in the subtrees
 * for the return type (r) and the parameter list (p), but the calls to
 * to this function in the example are just passing NULL at present!
 */
typeptr alcfunctype(SymbolTable st) {

   typeptr rv = alctype(FUNC_TYPE);
   if (rv == NULL) return NULL;
   rv->u.f.st = st;
   /* fill in return type and paramlist by traversing subtrees */
   /* rf->u.f.returntype = ... */
   return rv;
}

typeptr alcclasstype(SymbolTable st) {

   typeptr rv = alctype(CLASS_TYPE);
   if (rv == NULL) return NULL;
   rv->u.c.st = st;
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
	// printf("conv_to_type: %s\n", type_string);
	//typenamSize needs to be updated if new types added
	for (int i = 0; i < (typenamSize); i++) {
		// printf("typenam[%d] = %s, type_string = %s\n", i, typenam[i], type_string);
		if (strcmp(typenam[i], type_string) == 0) {
			// printf("i :%d\n", i);
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
				case 10:
					return FLOAT_TYPE;
					break;
			}
		}
	}
	return NULL_TYPE;
}

typeptr determinetype(struct tree *t) {
	for (int i = 0; i < t->nkids; i++) {

		determinetype(t->kids[i]);

		 switch (t->prodrule) {

		 	case prodR_FieldDecl: {
				printf("determinetype FieldDecl\n");
				typeptr typ = t->kids[0]->type;
				// printf("setting %d type\n", t->type->basetype);
				return typ;
			}

			case TOKEN: {

				printf("determinetype Token\n");
				struct token *tok = t->leaf;

				switch (tok->category) {
					case IDENTIFIER: {
						typeptr typ = alctype(NULL_TYPE); //Need to mark as class type
						return typ;
						break;
					}

					case INTLIT: {
						typeptr typ = alctype(conv_to_type(tok->text));
						return typ;
						break;
					}

					default: {
						printf("Can't determine type of %s\n", tok->text);
						exit(2);
					}
				}
			}

			default:
				printf("Throw semantic error: can't determine type for: %s\n", t->symbolname);
				exit(2);
		 }
	}
	return NULL;
}

typeptr get_type(SymbolTable st, struct token *tok) {

	SymbolTableEntry ste;

	if (tok->type != NULL) {
		return tok->type;
	}

	if (tok->category == IDENTIFIER) {
		ste = lookup_st(st, tok->text);

		if (ste != NULL) {
			tok->type = ste->type;
			return tok->type;
		} else {
			printf("Throw semantic error here: cant check type of %s\n", tok->text);
			exit(3);
		}
	}

	return NULL;
}

void check_types(struct tree *t) {

	if (t == NULL) return;

	int i;

	for (i = 0; i < t->nkids; i++) {
		check_types(t->kids[i]);
	}


	switch(t->prodrule) {


		case prodR_TypeAssignment: {

			printf("Type assignment found\n");
			typeptr typ = alctype(conv_to_type(t->kids[0]->leaf->text));
			printf("***convd type to %s\n", t->kids[0]->leaf->text);
			t->type = typ;

			break;
		}

		case prodR_AddExpr: {
			printf("prodR_AddExpr found\n");
			break;
		}

		case prodR_BlockStmts: {
			printf("prodR_BlockStmts found\n");
			break;
		}

		case prodR_MethodCall: {
			printf("prodR_MethodCall found\n");
			break;
		}

		case prodR_QualifiedName: {
			printf("prodR_QualifiedName found\n");
			break;
		}

		case TOKEN: {

			printf("TOKEN: %s, %s\n", t->symbolname, t->leaf->text);

			if (t->type) {
				printf("Has Type\n");
			}
			break;
		}

		default: {

		}

	}

}

// typeptr check_types (typeptr a, typeptr b) {
//
// 	return NULL;
// }

// void assigntype(struct tree *t, typeinfo typ) {
//
// 	switch (t->prodrule) {
//
// 		case prodR_VarDecls: {
//
// 		}
// 	}
// }
