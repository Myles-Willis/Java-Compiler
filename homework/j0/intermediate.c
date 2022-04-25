#include "intermediate.h"

struct addr empty_address = {R_NONE, OFFSET, {0}};


int print_intermediate_tree(struct tree* tree, int depth) {


	if (tree == NULL) {
		return 0;
	}

	if (tree->nkids == 0) {
		//print_addr(*tree->address);
		if (tree->address) {
			printf("%*s %s %d: %s [has address]\n", depth*4, " ", humanreadable(tree->prodrule),
			tree->leaf->category, tree->leaf->text);
		} else {
			printf("%*s %s %d: %s\n", depth*4, " ", humanreadable(tree->prodrule),
			tree->leaf->category, tree->leaf->text);
		}

		return 0;

	}

	printf("%*s %s: %d\n", depth*4, " ", humanreadable(tree->prodrule),
	 tree->nkids);

	for(int i = 0; i < tree->nkids; i++) {
		print_tree(tree->kids[i], depth+1);
	}

	return 0;

}

void gen_intermediate_code(struct tree *n) {

	int i;
	if (n == NULL) return;

	for (i = 0; i < n->nkids; i++) { gen_intermediate_code(n->kids[i]); }

	if (n->symbolname) {
		/* code */
		// printf("\n********** current node is %s\n", n->symbolname);
	}

	switch (n->prodrule) {

		case prodR_TypeAssignment:
		case prodR_FieldDeclAssign: {

			n->address = newtemp(1);

			int field_assn = strcmp(n->symbolname, "FieldDeclAssignment");

			struct instr *current_instr;
			struct instr *other_instr;

			current_instr = gen(O_ASN, *n->kids[1]->address, *n->kids[3]->address, empty_address);
			other_instr = n->kids[3]->icode;

			if (field_assn == 0) {
				n->address->region = R_GLOBAL;
			} else {
				//TypeAssignment
				n->address->region = R_LOCAL;
			}

			n->icode = append(other_instr, current_instr);
			tacprint(n->icode);

			break;
		}

		case prodR_UnaryAssignment: {
			break;
		}

		case prodR_Assignment: {

			n->address = n->kids[0]->address;
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			struct instr *other_instr;

			current_instr = gen(O_ASN, *n->kids[0]->address, *n->kids[2]->address, empty_address);
			other_instr = n->kids[2]->icode;

			n->icode = append(other_instr, current_instr);
			tacprint(n->icode);

			break;
		}

		case prodR_UnaryExpr: {

			int neg = strcmp(n->symbolname, "UnaryExpr_Neg");
			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			struct instr *other_instr;

			if (neg) {
				current_instr = gen(O_NEG, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			} else {
				//Exclamation
				current_instr = gen(O_NOT, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			}

			other_instr = n->kids[1]->icode;
			n->icode = append(other_instr, current_instr);
			tacprint(n->icode);

			break;
		}

		case prodR_RelExpr: {
			printf("The symbol is: %d\n", n->kids[1]->leaf->category);
			switch (n->kids[1]->leaf->category) {
				case 60:
					break;
				case 62:
					break;
				case 293:
					break;
				case 294:
					break;
			}
			break;
		}

		case prodR_EqExpr: {
			break;
		}

		case prodR_CondAndExpr:
		case prodR_CondOrExpr: {
			break;
		}

		case prodR_MethodDecl: {
			// printf("%s\n", n->symbolname);
			break;
		}

		case prodR_MethodDeclarator: {
			// printf("%s\n", n->kids[0]->leaf->text);

			n->address = newtemp(1);
			n->address->region = R_PROCNAME;
			// gen_method(n->kids[0]->leaf->text, int nparams, struct addr a, int code)
			// n->icode = gen_method(n->kids[0]->leaf->text, );
			//


			SymbolTableEntry method = check_if_undeclared(n->stab, n->kids[0]->leaf->text);

			if (method != NULL) {
				char* method_name = method->type->u.f.name;
				int params = method->type->u.f.nparams;
				n->icode = gen_method(method_name, params, *method->address, D_PROC);
				n->icode->code_type = DECLARATION;
				n->icode->block_bytes = method->table->byte_words * 8;
				tacprint(n->icode);

			} else {
				printf("Method not found in symtab!\n");
			}


			break;
		}

		case prodR_AddExpr: {

			int add = strcmp(n->symbolname, "AddExpr_add");
			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			struct instr *other_instr;

			if (add == 0) {
				current_instr = gen(O_ADD, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			} else {
				//Subtraction
				current_instr = gen(O_SUB, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			}

			other_instr = append(n->kids[0]->icode, n->kids[1]->icode);
			n->icode = append(other_instr, current_instr);
			tacprint(n->icode);

 			break;
		}

		case prodR_MulExpr: {

			int multiply = strcmp(n->symbolname, "MulExpr_multiply");
			int divide = strcmp(n->symbolname, "MulExpr_divide");

			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			struct instr *other_instr;

			if (multiply == 0) {
				current_instr = gen(O_MUL, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			} else if (divide == 0) {
				current_instr = gen(O_DIV, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			} else {
				current_instr = gen(O_MOD, *n->address, *n->kids[0]->address,
					 *n->kids[1]->address);
			}

			other_instr = append(n->kids[0]->icode, n->kids[1]->icode);
			n->icode = append(other_instr, current_instr);
			tacprint(n->icode);
			break;
		}

		case prodR_MethodCall: {

			struct instr *method_params;
			struct instr *method_call;

			if (n->kids[1]->nkids == 0) {
				//Expr
				switch (n->kids[1]->leaf->category) {
					case IDENTIFIER: {

						int set = set_identifier_addr(n->kids[1]);

						if (set == 1) {
							method_params = gen(O_PARM, *n->kids[1]->address, empty_address, empty_address);
							// tacprint(method_params);
						}
						break;
					}

					case INTLIT:
					case STRINGLIT:
					case REALLIT:
					case BOOLLIT:
					case CHARLIT:
						// printf("Handle literals here\n");
						gentoken(n->kids[1]);
						method_params = gen(O_PARM, *n->kids[1]->address, empty_address, empty_address);

						break;
				}
			} else {
				// Arglist in kids[1]
				method_params = gen_arglist(n->kids[1]);
			}

			SymbolTableEntry method = check_if_undeclared(n->stab, n->kids[0]->leaf->text);

			if (method != NULL) {
				char* method_name = method->type->u.f.name;
				int params = method->type->u.f.nparams;
				method_call = gen_method(method_name, params, *method->address, O_CALL);

				n->icode = append(method_params, method_call);
				tacprint(n->icode);

			} else {
				printf("Method not found in symtab!\n");
			}

			break;
		}

		case prodR_MethodCallPrimary: {
			// printf("METHODCALLPRIMARY*****\n");
			break;
		}

		case prodR_QualifiedName: {
			// printf("$$$$$$$$$$$ QualifiedName HERE ******\n");
			break;
		}

		case prodR_FieldDecl:
		case prodR_LocalVarDecl:
		case prodR_StaticFieldDecl: {
			// int region;
			break;
		}

		case TOKEN: {
			// printf("intermediate token %s\n", n->leaf->text);
			gentoken(n);
			break;
		}

	}

}

struct addr *newtemp(int num_bytes) {

	struct addr *temp = malloc(sizeof(struct addr));
	memset(temp, 0, sizeof(struct addr));

	return temp;
}


void genfirst(struct tree *t) {

	if (t->nkids != 0) {
		for (int i = 0; i < t->nkids; i++) {
			genfirst(t->kids[i]);
		}

		switch (t->prodrule) {

			case prodR_AddExpr:
			case prodR_MulExpr: {

				if (t->kids[0]->first != 0) {
					t->first = t->kids[0]->first;
				} else if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}
			}
		}
	}

}

int set_identifier_addr(struct tree *n) {

	SymbolTableEntry search = check_if_undeclared(n->stab ,n->leaf->text);

	if (search) {
		n->address = search->address;
		return 1;
	} else {
		printf("Could not find address for %s from Symboltable\n", n->leaf->text);
		printf("table name: %s\n", n->stab->table_name);
		return 0;
	}
}

void gentoken(struct tree *n) {

	n->icode = NULL;
	switch (n->leaf->category) {

		case IDENTIFIER: {
			// printf("Indentifier %s\n", n->leaf->text);
			set_identifier_addr(n);
			break;
		}
		case INTLIT: {

			n->address = newtemp(1);
			n->address->region = R_CONST;
			n->address->tag = OFFSET;
			n->address->u.offset = n->leaf->ival;
			break;
		}
		case STRINGLIT: {

			n->address = newtemp(1);
			n->address->region = R_CONST;
			n->address->tag = NAME;
			n->address->u.name = strdup(n->leaf->sval);

			break;
		}
		case REALLIT: {

			n->address = newtemp(1);
			n->address->region = R_CONST;
			n->address->tag = DVAL;
			n->address->u.dval = n->leaf->dval;
			break;
		}
		case BOOLLIT:
		case CHARLIT: {

			n->address = newtemp(1);
			n->address->region = R_CONST;
			n->address->tag = NAME;
			n->address->u.name = strdup(n->leaf->text);
			break;
		}
	}
}

struct instr *gen_arglist(struct tree *arglist) {

	struct instr *first_param;
	struct instr *second_param;
	struct instr *combined;

	if (arglist->kids[0]->nkids == 0) {

		gentoken(arglist->kids[0]);
		gentoken(arglist->kids[1]);

		first_param = gen(O_PARM, *arglist->kids[0]->address, empty_address,
			 empty_address);
		second_param = gen(O_PARM, *arglist->kids[1]->address, empty_address,
			 empty_address);
		combined = append(second_param, first_param);

	} else {
		second_param = gen(O_PARM, *arglist->kids[1]->address,
			 empty_address, empty_address);
		first_param = gen_arglist(arglist->kids[0]);
		combined = append(second_param, first_param);
	}
	return combined;
}

// int get_region(struct tree *n) {
// 	switch (n->prodrule) {
//
// 		case prodR_TypeAssignment:
//
// 			break
// 		case prodR_FieldDeclAssign:
//
// 			break
// 		case prodR_UnaryAssignment:
//
// 			break
// 		case prodR_Assignment:
//
// 			break
// 		case prodR_UnaryExpr:
//
// 			break
// 		case prodR_RelExpr:
//
// 			break
// 		case prodR_EqExpr:
//
// 			break
// 		case prodR_CondAndExpr:
//
// 			break
// 		case prodR_CondOrExpr:
//
// 			break
// 		case prodR_AddExpr:
//
// 			break
// 		case prodR_MulExpr:
//
// 			break
// 		case prodR_MethodCall:
//
// 			break
// 		case prodR_MethodCallPrimary:
//
// 			break
// 		case prodR_FieldDecl:
//
// 			break
// 		case prodR_LocalVarDecl:
//
// 			break
// 		case prodR_StaticFieldDecl:
//
// 			break
// 		case prodR_AddExpr:
//
// 			break
// 		case prodR_MulExpr:
//
// 			break
// 	}
// }
