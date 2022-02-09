#include "defs.h"

void create_token(int category_value) {

  struct token *new_token = malloc(sizeof(struct token));
  yytoken = new_token;
  yytoken->category = category_value;
  yytoken->text = strdup(yytext);
  yytoken->lineno = yylineno;
  yytoken->filename = filename;
  yytoken->ival = 0;
  yytoken->dval = 0;
  yytoken->sval = NULL;
}

int handle_token(int category_value) { //need to handle cases where tokens arent required

  int integer_literal;
  char *string_literal;

  switch (category_value) {

    case NOT_IN_JZERO_RESERVED:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", filename, yylineno, yytext);
      exit(1);
      break;

    case INVALID_PUNCTUATION:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", filename, yylineno, yytext);
      exit(1);
      break;

    case INVALID_CHAR_LITERAL:
      printf("\n%s:%d: error: %s Invalid char literal\n\n", filename, yylineno, yytext);
      exit(1);
      break;

    case INTEGER_LITERAL:
      create_token(category_value);
      integer_literal = atoi(yytext); //Not permanent solution, need method to errorcheck
      yytoken->ival = integer_literal;
      break;

    case STRING_LITERAL:
      // Malloc new token struct for entry
      create_token(category_value);
      string_literal = yytext;
      yytoken->sval = string_literal; //need to de-escape strings here
      break;

    case FLOAT_LITERAL:
      create_token(category_value);
      yytoken->dval = atof(yytext); //Not permanent solution, need method to errorcheck
      break;

    default:
      create_token(category_value);
  }
  return category_value;
}
