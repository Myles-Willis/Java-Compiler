#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

char *regionnames[] = {"global", "loc", "class", "L", "const", "name", "none", "procname"};
char *regionname(int i) { return regionnames[i-R_GLOBAL]; }

char *opcodenames[] = {
   "ADD","SUB", "MUL", "DIV","NEG", "ASN", "ADDR", "LCONT", "SCONT", "GOTO",
   "BLT", "BLE", "BGT", "BGE", "BEQ", "BNE", "BIF", "BNIF", "PARM", "CALL",
   "RETURN", "MOD", "NOT"
   };

char *opcodename(int i) { return opcodenames[i-O_ADD]; }
char *pseudonames[] = { "glob","proc", "loc", "lab", "end", "prot" };
char *pseudoname(int i) { return pseudonames[i-D_GLOB]; }

int labelcounter;

struct addr *genlabel() {

   struct addr *a = malloc(sizeof(struct addr));
   a->region = R_LABEL;
   a->u.offset = labelcounter++;
   // // *printf("generated a label %d\n", a->u.offset);

   return a;
}

struct instr *gen(int op, struct addr a1, struct addr a2, struct addr a3) {

  	struct instr *rv = malloc(sizeof (struct instr));

	if (rv == NULL) {
		fprintf(stderr, "out of memory\n");
     	exit(4);
	}

	rv->opcode = op;
	rv->dest = a1;
	rv->src1 = a2;
	rv->src2 = a3;
	// rv->next = NULL;
	rv->name = NULL;
	rv->nparams = 0;

	return rv;
}

struct instr *gen_method(char* method_name, int nparams, struct addr a, int code) {

	struct instr *rv = malloc(sizeof (struct instr));

	if (rv == NULL) {
		fprintf(stderr, "out of memory\n");
		exit(4);
	 }

	struct addr empty_address = {R_NONE, OFFSET, {0}};
	rv->opcode = code;
	rv->dest = a;
	rv->src1 = empty_address;
	rv->src2 = empty_address;
	// rv->next = NULL;
	rv->name = method_name;
	rv->nparams = nparams;

	// // *printf("CALL\t");
	// // *printf("%s, %d, %s:%d\n", method_name, nparams, regionname(a.region), a.u.offset);

	return rv;
}

struct instr *copylist(struct instr *l) {

	if (l == NULL) return NULL;

	struct instr *lcopy;

	if (l->opcode == D_PROC) {
		lcopy = gen_method(l->name, l->nparams, l->dest, D_PROC);
		lcopy->code_type = DECLARATION;
		lcopy->block_bytes = l->block_bytes;
	} else if(l->opcode == O_CALL) {
		lcopy = gen_method(l->name, l->nparams, l->dest, O_CALL);
	} else {
		lcopy = gen(l->opcode, l->dest, l->src1, l->src2);
	}

	lcopy->next = copylist(l->next);

	return lcopy;
}

struct instr *append(struct instr *l1, struct instr *l2) {

	if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL) {
		return l1;
	}

	struct instr *ltmp = l1;
	while(ltmp->next != NULL) ltmp = ltmp->next;
	ltmp->next = l2;

	return l1;
}

struct instr *concat(struct instr *l1, struct instr *l2) {
	return append(copylist(l1), l2);
}

void print_proc(struct instr *rv, FILE *icn_out) {
	// *printf("%s, %d, %d ", rv->name, (rv->nparams*8), rv->block_bytes);
	fprintf(icn_out, "%s, %d, %d ", rv->name, (rv->nparams*8), rv->block_bytes);
}

void print_instr(struct instr *rv, FILE *icn_out) {

	char *opcode_name = NULL;

	switch (rv->code_type) {

		case DECLARATION: {
			// // *printf("Declaration in print\n");
			opcode_name = pseudoname(rv->opcode);
			if (strcmp(opcode_name, "lab") == 0) {
				break;
			}
			// *printf("%s\t", opcode_name);
			fprintf(icn_out, "%s\t", opcode_name);
			break;
		}

		default: {
			opcode_name = opcodename(rv->opcode);
			// *printf("\t%s\t", opcode_name);
			fprintf(icn_out, "\t%s\t", opcode_name);
			break;
		}
	}

	if (rv->opcode == O_CALL) {

		// *printf("%s,%d,", rv->name, rv->nparams);
		fprintf(icn_out, "%s,%d,", rv->name, rv->nparams);
		print_addr(rv->dest, icn_out);
	} else if (rv->opcode == D_PROC) {

		print_proc(rv, icn_out);

	} else if (rv->opcode == D_LABEL) {
		// // *printf("print labels here\n");
		// *printf("L:%d\n", rv->dest.u.offset);
		fprintf(icn_out, "L:%d\n", rv->dest.u.offset);
		// print_addr(rv->dest);

	} else {

		print_addr(rv->dest, icn_out);
		if (rv->src1.region != R_NONE) {
			// *printf(",");
			fprintf(icn_out, ",");
		}
		print_addr(rv->src1, icn_out);

		if (rv->src2.region != R_NONE) {
			// *printf(",");
			fprintf(icn_out, ",");
		}
		print_addr(rv->src2, icn_out);
	}


	// *printf("\n");
	fprintf(icn_out, "\n");

}

void tacprint(struct instr *head, FILE *icn_out) {

	// *printf(".code\n");
	fprintf(icn_out, ".code\n");
	struct instr *temp = head;

	while (temp->next != NULL) {
		print_instr(temp, icn_out);
		temp = temp->next;
	}

	print_instr(temp, icn_out);
	// *printf("\n");
	fprintf(icn_out, "\n");

}

char print_addr(struct addr a, FILE *icn_out) {

	if (a.region == R_NONE) { return 0; }


	char *r = regionname(a.region);

	switch (a.tag) {

		case NAME:
			// *printf("%s:%s", r, a.u.name);
			fprintf(icn_out, "%s:%s", r, a.u.name);
			break;
		case DVAL:
			// *printf("%s:%f", r, a.u.dval);
			fprintf(icn_out, "%s:%f", r, a.u.dval);
			break;
		case OFFSET:
			// *printf("%s:%d", r, a.u.offset);
			fprintf(icn_out,"%s:%d", r, a.u.offset);
			break;
	}

	return 0;

}
