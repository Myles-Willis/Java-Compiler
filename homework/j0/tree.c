#include "tree.h"
#include "token.h"

struct tree *allocate_tree() {

	struct tree *tree = malloc(sizeof (struct tree));
	memset(tree, 0, sizeof(struct tree));

	return tree;

}

struct tree *create_leaf(int category_value, char* yytext, int lineno, char* filename){

	struct tree *tree = allocate_tree();
	struct token *leaf_token = allocate_token();

	tree->prodrule = TOKEN; //What is the prodrule?
	tree->leaf = leaf_token;

	leaf_token->category = category_value;
	leaf_token->text = strdup(yytext);
	leaf_token->lineno = yylineno;
	leaf_token->filename = filename;
	leaf_token->ival = 0;
	leaf_token->dval = 0;
	leaf_token->sval = NULL;

	return tree;

}

struct tree *create_branch(prodrule prodrule, char *symbolname, int nkids, ...){

	struct tree *branch = allocate_tree();

	va_list kids;
	va_start(kids, nkids);

	branch->prodrule = prodrule;
	branch->nkids = nkids;
	branch->symbolname = symbolname;

	for(int i = 0; i < nkids; i++) {
		branch->kids[i] = va_arg(kids, struct tree *);
	}

	va_end(kids);

	return branch;

}

void print_node(struct tree* tree) {

  if (tree->leaf->category == INTLIT) {
    printf("%d\t\t%-16s%d\t\t%s\t\t%d\n", tree->leaf->category, tree->leaf->text, tree->leaf->lineno, tree->leaf->filename, tree->leaf->ival);
  } else if (tree->leaf->category == STRINGLIT) {
    printf("%d\t\t%-16s%d\t\t%s\t\t%s\n", tree->leaf->category, tree->leaf->text, tree->leaf->lineno, tree->leaf->filename, tree->leaf->sval);
  } else if (tree->leaf->category == REALLIT){
    printf("%d\t\t%-16s%d\t\t%s\t\t%f\n", tree->leaf->category, tree->leaf->text, tree->leaf->lineno, tree->leaf->filename, tree->leaf->dval);
  } else {
    printf("%d\t\t%-16s%d\t\t%s\n", tree->leaf->category, tree->leaf->text, tree->leaf->lineno, tree->leaf->filename);
  }

}
