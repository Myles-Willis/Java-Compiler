#include <stdio.h>
#include <stdlib.h>
#include "tac.h"

char *region[] = {"global", "loc", "class", "label", "const", "name", "none", "procname", "str"};

char *opcodes[] = {
	"ADD", "SUB", "MUL", "DIV", "NEG", "ASN", "ADDR",
	"LCONT", "SCONT", "GOTO", "BLT", "BLE", "BGT", "BGE",
	"BEQ", "BNE", "BIF", "BNIF", "PARM", "CALL", "RET",
};

char print_addr(struct addr a) {

	// printf("Region: %d\n", a.region);
	char *r = region[a.region - 2001];

	if (a.region == R_NONE) {
		return 0 ;
	}

	printf("%s:%d", r, a.u.offset);

	return 0;

}

void print_instr(struct instr *rv) {

	char *opcode_name = opcodes[rv->opcode - 3001];
	printf("%s\t", opcode_name);


	if (rv->opcode == O_CALL) {
		 printf("%s, %d, ", rv->name, rv->nparams);
		 print_addr(rv->dest);

	} else {
		print_addr(rv->dest);
		if (rv->src1.region != R_NONE) {printf(", ");}
		print_addr(rv->src1);

		if (rv->src2.region != R_NONE) {printf(", ");}
		print_addr(rv->src2);
	}


	printf("\n");

}

void tacprint(struct instr *head) {

	struct instr *temp = head;
	while (temp->next != NULL) {
		print_instr(temp);
		temp = temp->next;
	}

	print_instr(temp);

}


int main(int argc, char *argv[]) {

	struct addr empty_address = {R_NONE, 0};

	struct addr loc_i = {R_LOCAL, 0};
	struct addr const_5  = {R_CONST, 5};
	struct instr *n1 = gen(O_ASN, loc_i, const_5, empty_address);
	// print_instr(n1);

	struct addr loc_t1 = {R_LOCAL, 8};
	struct instr *n2 = gen(O_MUL, loc_t1, loc_i, loc_i);
	// print_instr(n2);

	n1 = append(n1, n2);

	struct addr loc_t2 = {R_LOCAL, 16};
	struct addr const_1  = {R_CONST, 1};
	struct instr *n3 = gen(O_ADD, loc_t2, loc_t1, const_1);
	// print_instr(n3);

	n2 = append(n2, n3);

	struct instr *n4 = gen(O_ASN, loc_i, loc_t2, empty_address);
	// print_instr(n4);

	n3 = append(n3, n4);

	struct instr *n5 = gen(O_PARM, loc_i, empty_address, empty_address);
	// print_instr(n5);

	n4 = append(n4, n5);

	struct addr loc_t3 = {R_LOCAL, 24};
	struct addr *tostr = malloc(sizeof(struct addr));
	tostr->region = R_PROCNAME;
	tostr->u.name = "tostr";

	struct instr *n6 = gen_method("tostr", 1, loc_t3);
	// print_instr(n6);

	n5 = append(n5, n6);

	struct addr str_t0 = {R_STRING, 0};
	struct instr *n7 = gen(O_PARM, str_t0, empty_address, empty_address);
	// print_instr(n7);

	n6 = append(n6, n7);

	struct instr *n8 = gen(O_PARM, loc_t3, empty_address, empty_address);
	// print_instr(n8);

	n7 = append(n7, n8);

	struct addr loc_t4 = {R_LOCAL, 32};
	struct addr *cat = malloc(sizeof(struct addr));
	tostr->region = R_PROCNAME;
	tostr->u.name = "cat";

	struct instr *n9 = gen_method("cat", 2, loc_t4);
	// // print_instr(n9);

	n8 = append(n8, n9);

	struct instr *n10 = gen(O_PARM, loc_t4, empty_address, empty_address);
	// // print_instr(n10);

	n9 = append(n9, n10);

	struct addr loc_t5 = {R_LOCAL, 40};
	struct addr *println = malloc(sizeof(struct addr));
	tostr->region = R_PROCNAME;
	tostr->u.name = "println";

	struct instr *n11 = gen_method("println", 1, loc_t5);
	// print_instr(n11);

	n10 = append(n10, n11);

	printf("\n\ntacprint() output: \n\n");
	tacprint(n1);

	return 0;
}
