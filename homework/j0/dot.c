#include "dot.h"

int print_graph2(struct tree* tree, FILE *dotFile, int parent_serialId) {


	if (tree == NULL) {
		return 0;
	}

	if (tree->nkids == 0) { //print leaf

		// fprintf(dotFile, "N%d [shape=box style=dotted label=<%s>]\n",tree->dotId, s);
		// fprintf(dotFile, "text = %s \\l lineno = %d \\l\"];\n",tree->leaf->text, tree->leaf->lineno);

		fprintf(dotFile, "N%d [shape=box style=dotted label=<%s<br/> text: %s <br/> line: %d>]\n"
		,tree->dotId, yyname(tree->leaf->category), tree->leaf->text, tree->leaf->lineno);

		return 0;

	}

	fprintf(dotFile, "N%d [shape=box label=\"%s\"];\n", tree->dotId,tree->symbolname);

	for(int i = 0; i < tree->nkids; i++) {
		if (tree->kids[i] != NULL) {
			fprintf(dotFile, "N%d -> N%d;\n", tree->dotId, tree->kids[i]->dotId);
			print_graph2(tree->kids[i], dotFile, tree->kids[i]->dotId);
		} else {
			fprintf(dotFile, "N%d -> N%d;\n", parent_serialId, dot_serialId);
			fprintf(dotFile, "N%d [label=\"%s\"];\n",dot_serialId, "Empty rule");
			dot_serialId++;
		}
	}

	return 0;

}

void print_graph(struct tree *tree) {

	FILE *f;
	char *dot_file_name = malloc(sizeof(char) * strlen(filename) + strlen(".dot\n"));
	strcpy(dot_file_name, filename);
	strcat(dot_file_name, ".dot");

	if ((f = fopen(dot_file_name, "w")) == NULL) {
		printf("Error: cannot create DOT graph file\n");
		return;
	}

	dot_serialId = 0;
	fprintf(f, "digraph {\n");
	print_graph2(tree, f, 0);
	fprintf(f,"}\n");
	fclose(f);
	free(dot_file_name);
}
