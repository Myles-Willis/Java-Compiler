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
		printf("\n********** current node is %s\n", n->symbolname);
	}

	switch (n->prodrule) {

		case prodR_TypeAssignment:
		case prodR_FieldDeclAssign: {
			// printf("TypeAssignment/FieldDeclAssign Found\n");
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
			// tacprint(n->icode);
			// print_addr(*n->address);
			tacprint(n->icode);
			// printf("\n");

			break;
		}

		case prodR_UnaryAssignment: {
			break;
		}

		case prodR_Assignment: {

			n->address = n->kids[0]->address;
			n->address->region = R_LOCAL;

			struct instr *current_instr;
			struct instr *other_instr;

			current_instr = gen(O_ASN, *n->kids[0]->address, *n->kids[2]->address, empty_address);
			other_instr = n->kids[2]->icode;

			n->icode = append(other_instr, current_instr);
			// tacprint(n->icode);
			//print_addr(*n->address);
			tacprint(n->icode);

			break;
		}

		case prodR_UnaryExpr: {

			int neg = strcmp(n->symbolname, "UnaryExpr_Neg");
			n->address = newtemp(1);
			n->address->region = R_LOCAL;

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
			break;
		}

		case prodR_EqExpr: {
			break;
		}

		case prodR_CondAndExpr:
		case prodR_CondOrExpr: {
			break;
		}

		case prodR_AddExpr: {

			int add = strcmp(n->symbolname, "AddExpr_add");
			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->kids[0]->kids[0]->stab->byte_words *  8;
			n->kids[0]->kids[0]->stab++;

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

			// int offset_bytes = n->stab->byte_words *  8;

			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->kids[0]->stab->byte_words *  8;
			n->kids[0]->stab->byte_words++;

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
			break;
		}

		case prodR_MethodCallPrimary: {
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
			//gentoken();
			n->icode = NULL;
			switch (n->leaf->category) {

				case IDENTIFIER: {
					// printf("Indentifier address %s\n", n->leaf->text);

					SymbolTableEntry search = lookup_st(n->stab ,n->leaf->text);

					if (search) {
						// printf("\tfound in SymbolTable\n");
						n->address = search->address;
						//print_addr(*n->address);
					} else {
						printf("Could not find address for %s from Symboltable\n", n->leaf->text);
					}
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
