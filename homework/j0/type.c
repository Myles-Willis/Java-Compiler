#include "type.h"
#include "symboltable.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo float_type = { FLOAT_TYPE };
struct typeinfo void_type = { VOID_TYPE };
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
typeptr void_typeptr = &void_type;

char *typenam[] =
   {"null", "int", "double", "function", "class", "constructor", "char",
    "boolean", "String", "name", "float", "void"};

int typenamSize = 12;

typeptr alctype(int base) {

   typeptr rv;
   if (base == NULL_TYPE) return null_typeptr;
   else if (base == INT_TYPE) return integer_typeptr;
   else if (base == DOUBLE_TYPE) return double_typeptr;
   else if (base == FLOAT_TYPE) return float_typeptr;
   else if (base == CHAR_TYPE) return char_typeptr;
   else if (base == VOID_TYPE) return void_typeptr;
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
				case 11:
					return VOID_TYPE;
					break;
			}
		}
	}
	printf("couldn't convert %s to a type\n", type_string);
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


// if (t->kids[0]->symbolname) {
// 	printf("reduced rule\n");
// } else if (t->kids[0]->leaf->category == IDENTIFIER) {
// 	printf("need to look up left side\n");
// } else {
// 	printf("access left as literal\n");
// }


typeptr get_type(struct tree *t) {

	SymbolTableEntry ste;

	if (t->type != NULL) {
		return t->type;
	}

	switch (t->leaf->category) {
		case INTLIT:
		case REALLIT:
		case STRINGLIT:
		case BOOLLIT:
		case CHARLIT: {
			return t->leaf->type;
			break;
		}

		case IDENTIFIER: {

			ste = lookup_st(t->stab, t->leaf->text);

			if (ste != NULL) {
				return ste->type;
			} else {
				printf("Throw semantic error here: cant check type of %s\n", t->leaf->text);
				exit(3);
			}
		}
	}
	printf("### Could Not Get Type ###\n");
	return NULL;
}


int is_number(typeptr t) {
	switch(t->basetype) {
		case INT_TYPE:
		case FLOAT_TYPE:
		case DOUBLE_TYPE:
			return 1;
			break;
	}

	return 0;
}

void check_types(struct tree *t) {

	if (t == NULL) return;

	int i;

	for (i = 0; i < t->nkids; i++) {
		check_types(t->kids[i]);
	}


	switch(t->prodrule) {


		case prodR_TypeAssignment: {

			printf("prodR_TypeAssignment found\n");

			typeptr left;
			typeptr right;

			left = get_type(t->kids[1]);
			right = get_type(t->kids[3]);

			// printf("L[%s] = R[%s]\n", left, right);

			if (left->basetype != right->basetype) {
				printf("INCOMPATIBLE Type Assignment!\n");
			}

			break;
		}

		case prodR_UnaryAssignment: {

			printf("prodR_UnaryAssignment found\n");

			typeptr left = get_type(t->kids[0]);

			// printf("L[%s] = R[%s]\n", left, right);
			switch (left->basetype) {
				case INT_TYPE:
				case FLOAT_TYPE:
				case DOUBLE_TYPE:
					break;
				default:
					printf("INCOMPATIBLE Unary Assignment!\n");
					exit(3);
			}

			break;
		}

		case prodR_Assignment: {

			printf("prodR_Assignment found\n");

			// look up in current table and save type;
			typeptr left = get_type(t->kids[0]);
			typeptr right = get_type(t->kids[2]);

			if (left->basetype != right->basetype) {
				printf("INCOMPATIBLE Type Assignment!\n");
				exit(3);
			} else {
				t->type = left;
			}

			break;
		}

		// case prodR_AddExpr: {
		// 	printf("prodR_AddExpr found\n");
		//
		//
		// 	break;
		// }

		case prodR_UnaryExpr: {
			printf("prodR_UnaryExpr found\n");
			// printf("*** %s\n", t->symbolname);

			if (strcmp(t->symbolname, "UnaryExpr_Neg") == 0) {

				// SymbolTableEntry ste =
				// lookup_st(t->kids[1]->stab, t->kids[1]->leaf->text);
				typeptr type = get_type(t->kids[1]);

				switch (type->basetype) {
					case INT_TYPE:
					case FLOAT_TYPE:
					case DOUBLE_TYPE:
						break;
					default:
						printf("INCOMPATIBLE Unary Expression NAN!\n");
						exit(3);
				}

				t->type = type;

			} else if (strcmp(t->symbolname, "UnaryExpr_Excl") == 0) {
				printf("UnaryExpr_Excl found\n");

				typeptr type = get_type(t->kids[1]);

				switch (type->basetype) {
					case BOOL_TYPE:
						break;
					default:
						printf("INCOMPATIBLE Unary Expression need BOOL_TYPE!\n");
						exit(3);
				}

				t->type = type;


			} else {
				//PostFixExpr
				printf("PostFixExpr type: %s\n", typename(t->type));

			}

			break;
		}

		case prodR_RelExpr: {
			printf("prodR_RelExpr found\n");

			typeptr left, right;

			// printf("L[%s], R[%s]\n", t->kids[0]->leaf->text, t->kids[2]->leaf->text);

			left = get_type(t->kids[0]);
			right = get_type(t->kids[2]);

			if ((left != NULL) && (right != NULL)) {

				int left_correct = (is_number(left) || left->basetype == CHAR_TYPE);
				int right_correct = (is_number(right) || right->basetype == CHAR_TYPE);

				if (left_correct && right_correct) {
					t->type = alctype(BOOL_TYPE);
				} else {
					printf("INCOMPATIBLE Rel Expression!\n");
					exit(3);
				}
			}

			break;
		}

		case prodR_EqExpr: {
			printf("prodR_EqExpr found\n");

			typeptr left, right;

			// printf("L[%s], R[%s]\n", t->kids[0]->leaf->text, t->kids[2]->leaf->text);

			left = get_type(t->kids[0]);
			right = get_type(t->kids[1]);

			if ((left != NULL) && (right != NULL)) {

				int left_num = (is_number(left) || left->basetype == CHAR_TYPE);
				int right_num = (is_number(right) || right->basetype == CHAR_TYPE);

				if (left_num && right_num) {
					// printf("BOTH NUMS\n");
					t->type = alctype(BOOL_TYPE);
				} else if(left->basetype == STRING_TYPE && right->basetype == STRING_TYPE) {
					// printf("BOTH STRING\n");
					t->type = alctype(BOOL_TYPE);
				} else if(left->basetype == BOOL_TYPE && right->basetype == BOOL_TYPE) {
					// printf("BOTH BOOLEAN\n");
					t->type = alctype(BOOL_TYPE);
				}else {
					printf("INCOMPATIBLE Rel Expression!\n");
					exit(3);
				}
			}
			break;
		}


		case prodR_CondAndExpr:
		case prodR_CondOrExpr: {
			printf("prodR_Cond AND/OR Expr found\n");

			typeptr left, right;

			// printf("L[%s], R[%s]\n", t->kids[0]->leaf->text, t->kids[2]->leaf->text);

			left = get_type(t->kids[0]);
			right = get_type(t->kids[1]);

			if ((left != NULL) && (right != NULL)) {

				int left_correct = (left->basetype == BOOL_TYPE);
				int right_correct = ( right->basetype == BOOL_TYPE);

				if (left_correct && right_correct) {
					// printf("BOTH NUMS\n");
					t->type = alctype(BOOL_TYPE);
				} else {
					printf("INCOMPATIBLE Cond Expression!\n");
					exit(3);
				}
			}
			break;
		}




		case prodR_MulExpr:
		case prodR_AddExpr: {
			printf("prodR_MulExpr/prodR_AddExpr found\n");

			typeptr left, right;

			left = get_type(t->kids[0]);
			right = get_type(t->kids[1]);

			if ((left != NULL) && (right != NULL)) {

				//ensure they are numbers
				if (is_number(left) && is_number(right)) {
					//set node type according to promotion helper function?
					switch (left->basetype) {

						case INT_TYPE: {
							if (right->basetype != left->basetype) {
								printf("result type should be %s\n", typename(right));
								t->type = right;
							} else {
								printf("**Matching ints on L and R ");
								printf("result type should be %s\n", typename(left));
								t->type = left;
							}
							break;
						}

						case DOUBLE_TYPE: {
							if (right->basetype == FLOAT_TYPE) {
								printf("result type should be %s\n", typename(right));
								t->type = right;
							}
							break;
						}

						case FLOAT_TYPE: {
							printf("result type should be %s\n", typename(left));
							t->type = left;
							break;
						}
					}
				} else {
					printf("INCOMPATIBLE MUL Expression NAN!\n");
					exit(3);
				}
			}
			break;
		}


		case prodR_BlockStmts: {
			// printf("prodR_BlockStmts found\n");
			break;
		}

		case prodR_MethodCall: {
			// printf("prodR_MethodCall found\n");
			break;
		}

		case prodR_QualifiedName: {
			// printf("prodR_QualifiedName found\n");
			break;
		}

		case TOKEN: {


			// if (t->stab) {
			// 	printf("Has table\n");
			// }
			//
			// if (t->leaf->category == IDENTIFIER) {
			// 	printf("IDENTIFIER TOKEN: %d, %s\n", t->leaf->category, t->leaf->text);
			//
			// 	if (t->leaf->type) {
			// 		printf("*Has type*\n");
			// 	}
			//
			//
			// }
			//

			switch (t->leaf->category) {

				//


				case IDENTIFIER:
				case INTLIT:
				case STRINGLIT:
				case REALLIT:
				case BOOLLIT:
				case CHARLIT: {
					if (t->leaf->type) {
						// printf("* Token %s Has type: %s *\n", t->leaf->text ,typename(t->leaf->type));
					} else {
						// IDENTIFIER without type?
					}
				}
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
