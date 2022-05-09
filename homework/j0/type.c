#include "type.h"
#include "symboltable.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo float_type = { FLOAT_TYPE };
struct typeinfo void_type = { VOID_TYPE };
struct typeinfo char_type = { CHAR_TYPE };
struct typeinfo class_type = { CLASS_TYPE };
struct typeinfo array_type = { ARRAY_TYPE };
struct typeinfo func_type = { FUNC_TYPE };
struct typeinfo construct_type = { CONSTRUCT_TYPE };

typeptr null_typeptr = &null_type;
typeptr integer_typeptr = &integer_type;
typeptr double_typeptr = &double_type;
typeptr float_typeptr = &float_type;
typeptr char_typeptr = &char_type;
typeptr class_typeptr = &class_type;
typeptr func_typeptr = &func_type;
typeptr array_typeptr = &array_type;
typeptr construct_typeptr = &construct_type;
typeptr void_typeptr = &void_type;

char *typenam[] =
   {"null", "int", "double", "function", "class", "constructor", "char",
    "boolean", "String", "name", "float", "void", "array"};

int typenamSize = 13;

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

   return rv;
}

typeptr alcclasstype(SymbolTable st) {

   typeptr rv = alctype(CLASS_TYPE);
   if (rv == NULL) return NULL;
   rv->u.c.st = st;

   return rv;
}

typeptr alcarraytype(typeptr elemtype, int size) {

   typeptr rv = alctype(ARRAY_TYPE);
   if (rv == NULL) return NULL;
   rv->u.a.elemtype = elemtype;
   rv->u.a.size = size;

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
	// printf("couldn't convert %s to a type\n", type_string);
	return NULL_TYPE;
}

int get_arg_count(struct tree *args) {

	int argument_count = 0;

	if (args->symbolname) {

		if (args->kids[0]->nkids == 0) {
			argument_count = argument_count + 2;
		} else {
			argument_count++;
			argument_count = argument_count +
				get_arg_count(args->kids[0]);
		}
	} else {
		argument_count++;
	}

	return argument_count;
}

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
					int line_number = t->leaf->lineno;
					char* msg = "unable to determine typel\n";
					throw_semantic_error(msg, line_number);
				}
			}
		}

	// printf("### Could Not Get Type ###\n");
	return NULL;
}

int match_param(typeptr method_info, struct tree *arg, int arg_index) {

	paramlist ptr = method_info->u.f.parameters;
	typeptr arg_type = get_type(arg);

	// printf("Matching against %d declared parameters\n", method_info->u.f.nparams);

	while (ptr->next != NULL) {

		typeptr ptr_type = ptr->type;
		// printf("declared[%d] vs submitted[%d]\n", ptr->position, arg_index);
		if (ptr->position == arg_index) {
			// printf("index match found\n");

			if (ptr_type->basetype != arg_type->basetype) {

				int line_number = arg->leaf->lineno;
				char* msg = "incompatible parameter in call\n";
				throw_semantic_error(msg, line_number);
			}

			// printf("*** Types match at corresponding index ***\n");
			return 1;
		}

		ptr = ptr->next;
	}

	if (ptr->position == arg_index) {
		// printf("index match found\n");
		typeptr ptr_type = ptr->type;
		if (ptr_type->basetype != arg_type->basetype) {

			int line_number = arg->leaf->lineno;
			char* msg = "incompatible parameter in call\n";
			throw_semantic_error(msg, line_number);
		}

		// printf("*** Types match at corresponding index ***\n");
		return 1;

	}

	return 0;

}

void validate_params(struct tree *args, typeptr method_info, int start_index) {

	if (args->symbolname) {

		if (args->kids[0]->nkids == 0) {
			// printf("%s %s\n", typename(get_type(args->kids[1])) ,args->kids[1]->leaf->text);
			match_param(method_info, args->kids[1], 1);
			// printf("%s %s\n", typename(get_type(args->kids[0])) ,args->kids[0]->leaf->text);
			match_param(method_info, args->kids[0], 0);
		} else {
			// printf("%s %s\n", typename(get_type(args->kids[1])) ,args->kids[1]->leaf->text);
			match_param(method_info, args->kids[1], start_index);
			start_index = start_index - 1;
			validate_params(args->kids[0], method_info, start_index--);
		}

	} else {
		// printf("Expr (single)\n");
		// printf("%s\n", args->leaf->text);
		match_param(method_info, args, start_index);
	}
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

struct tree *get_last_name(struct tree *name_head) {

	struct tree *current = name_head;

	if (name_head->nkids == 0) {
		return name_head;
	}

	while (current->kids[1]->nkids != 0) {
		current = current->kids[1];
	}

	current = current->kids[1];

	// printf("Returning %s\n", current->leaf->text);
	return current;
}

typeptr type_promotion (typeptr left, typeptr right) {

	if ((left != NULL) && (right != NULL)) {

		//ensure they are numbers
		int left_correct = ((is_number(left)) || (left->basetype == CHAR_TYPE));
		int right_correct = ((is_number(right)) || (right->basetype == CHAR_TYPE));

		if (left_correct && right_correct) {

			switch (left->basetype) {

				case INT_TYPE:
				case CHAR_TYPE: {

					if ((right->basetype != left->basetype) &&
						(right->basetype != CHAR_TYPE)) {

						// printf("result type should be %s\n", typename(right));
						return right;
					} else {
						// printf("**Matching ints on L and R ");
						// printf("result type should be INT\n");
						return alctype(INT_TYPE);
					}
					break;
				}

				case DOUBLE_TYPE: {
					if (right->basetype == FLOAT_TYPE) {
						// printf("result type should be %s\n", typename(right));
						return right;
					}
					break;
				}

				case FLOAT_TYPE: {
					// printf("result type should be %s\n", typename(left));
					return left;
					break;
				}
			}
		}
		//If type is not a number, return the left type since it must match
		return left;
	}
	printf("Promotion could not be checked!\n");
	return NULL;
}

void check_types(struct tree *t) {

	int i;

	if (t == NULL) return;
	for (i = 0; i < t->nkids; i++) { check_types(t->kids[i]); }

	switch(t->prodrule) {

		// case prodR_QualifiedName: {
		// 	break;
		// }

		case prodR_TypeAssignment:
		case prodR_FieldDeclAssign: {

			// printf("prodR_TypeAssignment found\n");

			if (strcmp(t->symbolname, "FieldDeclAssignment") == 0) {
				// printf("Right side must be literal\n");

				switch (t->kids[3]->leaf->category) {
					case INTLIT:
					case REALLIT:
					case STRINGLIT:
					case BOOLLIT:
					case CHARLIT: {
						break;
					}
					default: {
						int line_number = t->kids[3]->leaf->lineno;
						char* msg = "static field declaration must be assigned a literal\n";
						throw_semantic_error(msg, line_number);
					}
				}
			}

			typeptr left;
			typeptr right;

			left = get_type(t->kids[1]);
			right = get_type(t->kids[3]);

			// printf("L[%s] = R[%s]\n", left, right);

			if (left->basetype != right->basetype) {
				int line_number = t->kids[1]->leaf->lineno;
				char* msg = "incompatible types in assignment\n";
				throw_semantic_error(msg, line_number);
			}

			break;
		}

		case prodR_UnaryAssignment: {

			// printf("prodR_UnaryAssignment found\n");

			typeptr left = get_type(t->kids[0]);

			// printf("L[%s] = R[%s]\n", left, right);
			switch (left->basetype) {
				case INT_TYPE:
				case FLOAT_TYPE:
				case DOUBLE_TYPE:
					break;
				default: {
					int line_number = t->kids[0]->leaf->lineno;
					char* msg = "incompatible type for unary assignment\n";
					throw_semantic_error(msg, line_number);
				}
			}

			break;
		}

		case prodR_Assignment: {

			// printf("prodR_Assignment found\n");
			// printf("[0]: %s, [1]: %s\n",t->kids[0]->leaf->text, t->kids[2]->leaf->text);
			typeptr left = NULL;
			typeptr right = NULL;
			int line_number = 0;

			if (t->kids[2]->prodrule == prodR_ArrayInstantiation) {
				// printf("prodR_ArrayInstantiation found\n");
				// left = get_type(t->kids[0]);

				if(t->kids[2]->kids[0]->nkids == 2) {
					char* type_str = t->kids[2]->kids[0]->kids[0]->leaf->text;
					right = alctype(conv_to_type(type_str));
				} else {
					char* type_str = t->kids[2]->kids[0]->leaf->text;
					right = alctype(conv_to_type(type_str));
				}
			} else if (t->kids[2]->prodrule == prodR_PostBracketArray) {

				// left = get_type(t->kids[0]);
				char* type_str = t->kids[2]->kids[0]->leaf->text;
				right = alctype(conv_to_type(type_str));

			} else {
				// look up in current table and save type;
				if (t->kids[2]->nkids == 2 && t->kids[2]->kids[0]->prodrule == prodR_MulExpr) {
					right = get_type(t->kids[2]->kids[0]->kids[0]);
				} else {
					right = get_type(t->kids[2]);
				}
			}

			if (t->kids[0]->prodrule == prodR_PostBracketArray) {
				left = get_type(t->kids[0]->kids[0]);
				line_number = t->kids[0]->kids[0]->leaf->lineno;
			} else {
				left = get_type(t->kids[0]);
				line_number = t->kids[0]->leaf->lineno;
			}


			if ((left != NULL) && (right != NULL)) {
				typeptr promo = type_promotion(left, right);
				// printf("Promo1 returned %s\n", typename(promo));

				if (is_number(promo)) {
					t->type = promo;
				} else if (left->basetype == right->basetype) {
					t->type = promo;
				} else {
					char* msg = "incompatible types in assignment\n";
					throw_semantic_error(msg, line_number);
				}
			}

			break;
		}

		case prodR_UnaryExpr: {

			// printf("prodR_UnaryExpr found\n");
			// printf("*** %s\n", t->symbolname);

			if (strcmp(t->symbolname, "UnaryExpr_Neg") == 0) {

				typeptr type = get_type(t->kids[1]);

				switch (type->basetype) {
					case INT_TYPE:
					case FLOAT_TYPE:
					case DOUBLE_TYPE:
					case CHAR_TYPE:
						break;
					default: {
						int line_number = t->kids[1]->leaf->lineno;
						char* msg = "incompatible type in expression (not a number)\n";
						throw_semantic_error(msg, line_number);
					}
				}

				t->type = type;

			} else if (strcmp(t->symbolname, "UnaryExpr_Excl") == 0) {
				// printf("UnaryExpr_Excl found\n");

				typeptr type = get_type(t->kids[1]);

				switch (type->basetype) {
					case BOOL_TYPE:
						break;
					default: {
						int line_number = t->kids[1]->leaf->lineno;
						char* msg = "incompatible type in expression (not a boolean)\n";
						throw_semantic_error(msg, line_number);
					}
				}

				t->type = type;


			} else {
				//PostFixExpr
				// printf("\t\tPostFixExpr type: %s\n", typename(t->type));

			}

			break;
		}

		case prodR_RelExpr: {

			// printf("prodR_RelExpr found\n");

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
					int line_number = t->kids[0]->leaf->lineno;
					char* msg = "incompatible type in expression (not a number)\n";
					throw_semantic_error(msg, line_number);
				}
			}

			break;
		}

		case prodR_EqExpr: {

			// printf("prodR_EqExpr found\n");

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
					int line_number = t->kids[0]->leaf->lineno;
					char* msg = "incompatible types in expression\n";
					throw_semantic_error(msg, line_number);
				}
			}
			break;
		}


		case prodR_CondAndExpr:
		case prodR_CondOrExpr: {

			// printf("prodR_Cond AND/OR Expr found\n");

			typeptr left, right;

			// printf("L[%s], R[%s]\n", t->kids[0]->leaf->text, t->kids[2]->leaf->text);

			left = get_type(t->kids[0]);
			right = get_type(t->kids[1]);

			if ((left != NULL) && (right != NULL)) {

				int left_correct = (left->basetype == BOOL_TYPE);
				int right_correct = ( right->basetype == BOOL_TYPE);

				if (left_correct && right_correct) {
					t->type = alctype(BOOL_TYPE);
				} else {
					int line_number = t->kids[0]->leaf->lineno;
					char* msg = "incompatible types in expression (not a boolean)\n";
					throw_semantic_error(msg, line_number);
				}
			}
			break;
		}

		case prodR_MulExpr:
		case prodR_AddExpr: {

			// printf("prodR_MulExpr/prodR_AddExpr found\n");

			typeptr left, right;
			// int line_number;

			if (t->kids[0]->nkids == 2) { //prodrule == prodR_MulExpr
				left = get_type(t->kids[0]->kids[0]);
				// line_number = t->kids[1]->leaf->lineno;
			} else {
				left = get_type(t->kids[0]);
				// line_number = t->kids[0]->leaf->lineno;
			}

			right = get_type(t->kids[1]);

			if ((left != NULL) && (right != NULL)) {

				if (left->basetype == STRING_TYPE && right->basetype == STRING_TYPE) {
					t->type = alctype(STRING_TYPE);
					break;
				}

				if (!(is_number(left) && is_number(right))) {
					// char* msg = "expression requires numerical or String-only values\n";
					// throw_semantic_error(msg, line_number);
					// line_number = line_number;
				}

				typeptr promo = type_promotion(left, right);
				// printf("Promo2 returned %s\n", typename(promo));

				if(is_number(promo)) {
					t->type = type_promotion(left, right);
				} else {
					// int line_number = t->kids[0]->leaf->lineno;
					// char* msg = "expression requires numerical or String-only values\n";
					// throw_semantic_error(msg, line_number);
					// line_number = line_number;
				}
			}
			break;
		}

		case prodR_MethodCall: { // parens/curly
			// printf("prodR_MethodCall found\n");

			// *** WEIRD behavior when surrounding in if condition ****
				typeptr typ = NULL;

				if (t->kids[0]->symbolname) {
					break;

					// printf("Found: %s\n", t->kids[0]->symbolname);
					//
					// struct tree *last_name = get_last_name(t->kids[0]->kids[1]);
					// // typ = get_type(last_name);
					// printf("FUNCT %s\n", last_name->leaf->text);
					// SymbolTableEntry st = check_if_undeclared(t->kids[0]->stab, last_name->leaf->text);
					// printf("%s\n", st->s);
					// printf("TYPE %s\n", typename(get_type(last_name)));
					// printf("PARAM %s\n", typename(t->kids[1]->leaf->type));


				}
				typ = get_type(t->kids[0]);
				int defined_num_args = typ->u.f.nparams;

				if (t->kids[1]) {

					int num_args = get_arg_count(t->kids[1]);

					if (num_args == defined_num_args) {
						validate_params(t->kids[1], typ, num_args - 1);
					} else {
						int line_number = t->kids[0]->leaf->lineno;
						char* msg = "invalid number of arguments to method call\n";
						throw_semantic_error(msg, line_number);
					}

					t->type = typ->u.f.returntype;

				} else {
					// printf("method call with no arguments\n");
					if (defined_num_args != 0) {
						int line_number = t->kids[0]->leaf->lineno;
						char* msg = "invalid number of arguments to method call\n\n";
						throw_semantic_error(msg, line_number);
					}
				}

				// printf("Method return type is %s\n", typename(typ->u.f.returntype));
				t->type = typ->u.f.returntype;

			break;
		}

		case prodR_MethodCallPrimary: {
			printf("prodR_MethodCallPrimary found\n");

				//get last of the qualified name sequence
				typeptr typ = get_type(t->kids[0]);
				int defined_num_args = typ->u.f.nparams;

				if (t->kids[1]) {

					int num_args = get_arg_count(t->kids[1]);

					if (num_args == defined_num_args) {
						validate_params(t->kids[1], typ, num_args - 1);
					} else {
						int line_number = t->kids[0]->leaf->lineno;
						char* msg = "invalid number of arguments to method call\n";
						throw_semantic_error(msg, line_number);
					}

					t->type = typ->u.f.returntype;

				} else {
					// printf("method call with no arguments\n");
					if (defined_num_args != 0) {
						int line_number = t->kids[0]->leaf->lineno;
						char* msg = "invalid number of arguments to method call\n\n";
						throw_semantic_error(msg, line_number);
					}
				}

				// printf("Method return type is %s\n", typename(typ->u.f.returntype));
				t->type = typ->u.f.returntype;

			break;
		}

		case prodR_QualifiedName: {
			// printf("prodR_QualifiedName found\n");
			break;
		}

		case TOKEN: {

			switch (t->leaf->category) {

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
