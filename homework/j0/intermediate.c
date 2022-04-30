#include "intermediate.h"

struct addr empty_address = {R_NONE, OFFSET, {0}};
// struct instr instructions = NULL;


int print_intermediate_tree(struct tree* tree, int depth) {


	if (tree == NULL) {
		return 0;
	}

	if (tree->nkids == 0) {
		// print_addr(*tree->address);
		//
		if (tree->address != NULL) {
			printf("%*s %s %d: %s [has address] \n", depth*4, " ", humanreadable(tree->prodrule),
			tree->leaf->category, tree->leaf->text);

		} else {
			printf("%*s %s %d: %s\n", depth*4, " ", humanreadable(tree->prodrule),
			tree->leaf->category, tree->leaf->text);
		}

		return 0;

	}

	printf("%*s %s: %d ", depth*4, " ", humanreadable(tree->prodrule),
	 tree->nkids);

	 if (tree->first) {
	 	printf("[#first] ");
	 }

	 if (tree->follow) {
		printf("[#has follow]\n");
	} else {
		printf("\n");
	}

	for(int i = 0; i < tree->nkids; i++) {
		print_intermediate_tree(tree->kids[i], depth+1);
	}

	return 0;

}

void gen_intermediate_code(struct tree *n) {

	int i;
	if (n == NULL) return;

	for (i = 0; i < n->nkids; i++) {
		if(n->kids[i] == NULL) {
			printf("null child\n");
			continue;
		}
		if (n->kids[i]->prodrule == prodR_QualifiedName) {
			// printf("Qualified name found here \n");
			gen_qualified_addr(n->kids[i]);

		} else {
			 // n->kids[i]->icode
			 // struct instr *child = gen_intermediate_code(n->kids[i]);
			 // n->icode->next = child;
			 gen_intermediate_code(n->kids[i]);
		}
	 }

	if (n->symbolname) {
		/* code */
		// printf("\n********** current node is %s\n", n->symbolname);
		// printf("\n********** kids %d\n", n->nkids);
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

			n->icode = concat(other_instr, current_instr);
			// //tacprint(n->icode);

			break;
		}

		case prodR_ReturnStmt: {
			// printf("return statement found\n");
			// if (n->stab) {
			// 	printf("and has stab %s\n", n->stab->table_name);
			// }

			if (n->kids[0] == NULL) {
				// printf("Empty return statement\n");
				n->address = newtemp(1);
				n->icode = gen(O_RET, *n->address, empty_address, empty_address);

			} else {
				// printf("Return statement has an expresstion\n");
				n->address = newtemp(1);
				n->icode = gen(O_RET, *n->kids[0]->address, empty_address, empty_address);
				// printf("%s\n", );
			}


			break;
		}

		// case prodR_UnaryAssignment: {
		// 	break;
		// }

		case prodR_Assignment: {

			n->address = n->kids[0]->address;
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			struct instr *other_instr;

			current_instr = gen(O_ASN, *n->kids[0]->address, *n->kids[2]->address, empty_address);
			other_instr = n->kids[2]->icode;

			n->icode = concat(other_instr, current_instr);
			//tacprint(n->icode);

			break;
		}

		case prodR_UnaryExpr: {

			int neg = strcmp(n->symbolname, "UnaryExpr_Neg");
			n->address = newtemp(1);
			n->address->region = R_LOCAL;
			n->address->u.offset = n->stab->byte_words *  8;
			n->stab->byte_words++;

			struct instr *current_instr;
			// struct instr *other_instr;

			if (neg == 0) {
				current_instr = gen(O_NEG, *n->address, *n->kids[1]->address,
					 empty_address);
			} else {
				//Exclamation
				current_instr = gen(O_NOT, *n->address, *n->kids[1]->address,
					 empty_address);
			}

			// other_instr = n->kids[1]->icode;
			n->icode = current_instr;
			//tacprint(n->icode);

			break;
		}

		case prodR_RelExpr: {

			// printf("The symbol is: %d\n", n->kids[1]->leaf->category);
			struct instr *current_instr = NULL;
			struct instr *other_instr = NULL;

			n->address = newtemp(1);

			switch (n->kids[1]->leaf->category) {
				case 60:
					// <
					current_instr = gen(O_BLT, *n->onTrue,
						 *n->kids[0]->address, *n->kids[2]->address);
					break;
				case 62:
					// >
					current_instr = gen(O_BGT, *n->onTrue,
						 *n->kids[0]->address, *n->kids[2]->address);
					break;
				case 293:
					// >=
					current_instr = gen(O_BGE, *n->onTrue,
						 *n->kids[0]->address, *n->kids[2]->address);
					break;
				case 294:
					// <=
					current_instr = gen(O_BLE, *n->onTrue,
						 *n->kids[0]->address, *n->kids[2]->address);
					break;
			}

			other_instr = concat(n->kids[0]->icode, n->kids[2]->icode);
			n->icode = concat(current_instr, other_instr);
			// printf("\n");
			// printf("Region %d\n", n->icode->dest.region);
			// tacprint(n->icode);
			break;
		}

		// case prodR_MethodDecl: {
		// 	n->address = newtemp(1);
		// 	n->address->region = R_LOCAL;
		//
		// 	struct instr *label = gen(D_LABEL, *n->first, empty_address, empty_address);
		// 	label = concat(label, n->kids[1]->icode);
		// 	label->code_type = DECLARATION;
		// 	n->icode = concat(n->icode, label);
		//
		// 	tacprint(n->icode);
		//
		// 	break;
		// }

		case prodR_MethodDeclarator: {
			// printf("%s\n", n->kids[0]->leaf->text);

			n->address = newtemp(1);
			n->address->region = R_PROCNAME;

			SymbolTableEntry method = check_if_undeclared(n->stab, n->kids[0]->leaf->text);

			if (method != NULL) {

				char* method_name = method->type->u.f.name;
				int params = method->type->u.f.nparams;

				n->icode = gen_method(method_name, params, *method->address, D_PROC);
				n->icode->code_type = DECLARATION;
				n->icode->block_bytes = method->table->byte_words * 8;
				// tacprint(n->icode);

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

			other_instr = concat(n->kids[0]->icode, n->kids[1]->icode);
			n->icode = concat(other_instr, current_instr);
			//tacprint(n->icode);

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

			other_instr = concat(n->kids[0]->icode, n->kids[1]->icode);
			n->icode = concat(other_instr, current_instr);
			//tacprint(n->icode);
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
							// //tacprint(method_params);
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

			SymbolTableEntry method;

			if (n->kids[0]->prodrule == prodR_QualifiedName) {
				struct tree *last_name = get_last_name(n->kids[0]);
				method = check_if_undeclared(last_name->stab, last_name->leaf->text);

			} else {
				method = check_if_undeclared(n->stab, n->kids[0]->leaf->text);
			}

			if (method != NULL) {
				char* method_name = method->type->u.f.name;
				int params = method->type->u.f.nparams;
				method_call = gen_method(method_name, params, *method->address, O_CALL);

				n->icode = concat(method_params, method_call);
				//tacprint(n->icode);

			} else {
				printf("Method not found in symtab!\n");
			}

			break;
		}

		case prodR_IfThenStmt: {

			if (n->kids[0]->icode != NULL) {
				n->icode = n->kids[0]->icode;
			} else {
				n->icode = gen(O_BIF, *n->kids[0]->onFalse,
					 *n->kids[0]->address, empty_address);
			}

			struct instr *label = gen(D_LABEL, *n->kids[0]->onTrue, empty_address, empty_address);
			label = concat(label, n->kids[1]->icode);
			label->code_type = DECLARATION;
			n->icode = concat(n->icode, label);

			break;
		}


		case prodR_BlockStmts: {
			n->kids[0]->follow = n->kids[1]->first;
			n->kids[1]->follow = n->kids[0]->follow;

			n->icode = concat(n->kids[0]->icode, n->kids[1]->icode);
			// tacprint(n->icode);
			break;
		}




		case TOKEN: {
			gentoken(n);
			break;
		}

		default:

			n->icode = NULL;

			for (int i=0; i < n->nkids; i++) {
				// printf("%s --> %s\n", n->kids[i]->symbolname,n->symbolname);
				n->icode = concat(n->icode, n->kids[i]->icode);
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
		// printf("________ %s ________\n\n", t->symbolname);
		switch (t->prodrule) {

			case prodR_AddExpr:
			case prodR_MulExpr: {

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}

				// printf("L%d %s\n", t->first->u.offset, t->symbolname);

				break;
			}

			case prodR_UnaryExpr: {

				if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else {
					t->first = genlabel();
				}

				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_Assignment: {

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}

				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_TypeAssignment:
			case prodR_FieldDeclAssign: {

				if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else if (t->kids[3]->first != NULL) {
					t->first = t->kids[3]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_RelExpr: {
				// printf("RELEXPR case\n");
				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else if (t->kids[2]->first != NULL) {
					t->first = t->kids[2]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_EqExpr:
			case prodR_CondAndExpr:
			case prodR_CondOrExpr: {

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else if (t->kids[1]->first != NULL) {
					t->first = t->kids[1]->first;
				} else {
					struct addr *temp = genlabel();
					t->first = temp;
				}
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_WhileStmt: {

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else {
					t->first = genlabel();
				}
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_IfThenStmt:
			case prodR_IfThenElseStmt:
			case prodR_IfThenElseIfStmt:
			case prodR_IfThenElseIfElseStmt: {

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else {
					t->first = genlabel();
				}
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_BlockStmts: {

				// printf("Hit Block stmt\n");
				if (t->kids[1]->first == NULL) {t->kids[1]->first = genlabel();}

				if (t->kids[0]->first != NULL) {
					t->first = t->kids[0]->first;
				} else {
					t->first = t->kids[1]->first;
				}
				// printf("And assigned FIRST\n");
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);
				break;
			}

			case prodR_MethodDecl: {

				if (t->kids[1]->first == NULL) {t->kids[1]->first = genlabel();}

				t->first = t->kids[1]->first;
				// printf("And assigned FIRST\n");
				// printf("L%d %s\n", t->first->u.offset, t->symbolname);

				break;
			}


			default: {
				if (t->nkids != 0) {
					for (int i=0; i < t->nkids; i++) {
						if (t->kids[i] != NULL) {
							t->first = t->kids[i]->first;
							break;
						}
					}
				}
			}

		}
	}

}

void genfollow(struct tree *t) {

	// printf("GENFOLLOW %s\n", t->symbolname);
	int i;
	if (t == NULL) return;

	if (t->symbolname) {
		// printf("\n_______________________________\n");
		// printf("GENFOLLOW %s\n", t->symbolname);

	}
	switch (t->prodrule) {

		case prodR_MethodDecl: {
			// printf("GENFOLLOW %s\n", t->symbolname);
			t->kids[1]->follow = genlabel();
			// printf("FL%d %s\n", t->kids[1]->follow->u.offset, t->kids[1]->symbolname);

			break;
		}

		case prodR_BlockStmts: {
			// printf("GENFOLLOW %s\n", t->symbolname);
			t->kids[0]->follow = t->kids[1]->first;
			t->kids[1]->follow = t->follow;
			// printf("FL%d %s\n", t->follow->u.offset, t->symbolname);
			break;
		}

		case prodR_IfThenStmt: {
			// printf("GENFOLLOW %s\n", t->symbolname);
			t->kids[0]->follow = t->kids[1]->first;
			t->kids[1]->follow = t->follow;
			// printf("FL%d %s\n", t->follow->u.offset, t->symbolname);
			break;
		}

	}

	if (t->nkids != 0) {
		for (i = 0; i < t->nkids; i++) {
			// printf("loop case!\n");
			genfollow(t->kids[i]);
		}
	}
}

void gentargets(struct tree *t) {

	int i;
	if (t == NULL) return;

	switch (t->prodrule) {

		case prodR_IfThenStmt: {
			t->kids[0]->onTrue = t->kids[1]->first;
			t->kids[0]->onFalse = t->follow;
			// printf("%s onTrue->L%d, onFalse->L%d\n", t->symbolname,
			 // t->kids[0]->onTrue->u.offset, t->kids[0]->onFalse->u.offset);


			break;
		}

		case prodR_CondAndExpr: {
			t->kids[0]->onTrue = t->kids[1]->first;
			t->kids[0]->onFalse = t->onFalse;
			t->kids[1]->onTrue = t->onTrue;
			t->kids[1]->onFalse = t->onFalse;

			break;
		}
	}

	if (t->nkids != 0) {
		for (i = 0; i < t->nkids; i++) {
			gentargets(t->kids[i]);
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

	// n->icode = NULL;
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
			n->address->region = R_STRING;
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
		combined = concat(second_param, first_param);

	} else {
		second_param = gen(O_PARM, *arglist->kids[1]->address,
			 empty_address, empty_address);
		first_param = gen_arglist(arglist->kids[0]);
		combined = concat(second_param, first_param);
	}
	return combined;
}

/**
 * Initialize symbol tables for each token in a qualified name
 * @param  name_head the first name in a qualified name
 */
void gen_qualified_addr(struct tree *name_head) {

	struct tree *current = name_head;
	SymbolTableEntry outer_addr = NULL;
	SymbolTableEntry addr_check = NULL;

	if (name_head->nkids == 0) {
		// printf("Name: %s\n", name_head->leaf->text);
		addr_check = check_if_undeclared(name_head->stab, name_head->leaf->text);
		name_head->stab = addr_check->table;
		// printf("Has table %s\n", addr_check->table->table_name);

	}

	// printf("Name: %s\n", name_head->kids[0]->leaf->text);
	outer_addr = check_if_undeclared(name_head->stab, name_head->kids[0]->leaf->text);
	SymbolTable inner_name_table = outer_addr->type->type_sym_table;
	// printf("Has table %s\n", outer_addr->table->table_name);
	name_head->kids[0]->stab = outer_addr->table;


	while (current->kids[1]->nkids != 0) {
		current = current->kids[1];
		// printf("Name: %s\n", current->kids[0]->leaf->text);
		addr_check = check_if_undeclared(inner_name_table, current->kids[0]->leaf->text);
		// printf("Has table %s\n", addr_check->table->table_name);
		current->kids[0]->stab = addr_check->table;
		inner_name_table = addr_check->type->type_sym_table;

	}
	current = current->kids[1];
	// printf("Name: %s\n", current->leaf->text);
	addr_check = check_if_undeclared(inner_name_table, current->leaf->text);
	// printf("Has table %s\n", addr_check->table->table_name);
	current->stab = addr_check->table;
}
