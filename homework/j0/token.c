#include "token.h"
#include "type.h"

struct token *allocate_token() {

	struct token *token = malloc(sizeof (struct token));
	memset(token, 0, sizeof(struct token));

	return token;

}

int handle_token(int category_value) { //need to handle cases where tokens arent required

	switch (category_value) {

		case NOT_IN_JZERO_RESERVED:

			print_error("not supported in jzero");
			exit(1);
			break;

		case INVALID_PUNCTUATION:

 			print_error("is invalid jzero punctuation");
	  		exit(1);
	  		break;

		case INVALID_CHARLIT_ESCAPE:

 			print_error("has invalid char literal escape");
			exit(1);
			break;

	    case INVALIDCHARLIT:

 			print_error("is invalid char literal");
			exit(1);
			break;

		case EMPTY_CHARLIT:

 			print_error("is empty char literal");
			exit(1);
			break;

		case OPENENDED_CHARLIT:

 			print_error("is open-ended char literal");
			exit(1);
			break;

		case UNRECOGNIZED_CHARACTER:

			print_error("is unrecognized character");
			exit(1);
			break;

	}

	yylval.treeptr = create_leaf(category_value, yytext, yylineno, filename);

	//Switch after potential error checking
	switch (category_value) {

		case INTLIT: {

			long number =  strtol(yylval.treeptr->leaf->text, NULL, 10);

	      	//Validate number with min and max allowed INT in Java
			if (number > 2147483647 || number < -2147483648) {
				print_error("has invalid int literal range");
				exit(1);
			}

		  	yylval.treeptr->leaf->ival = number;
			yylval.treeptr->leaf->type = alctype(INT_TYPE);

			break; }

	    case STRINGLIT: {

			char *str_buffer = malloc((strlen(yytext) + 1) * sizeof(char));
			char has_escape = 0;
			int char_position = 0;

			for (char *current_char = (yytext + 1); *current_char != '\0';
			 current_char++) {

				 if (has_escape) {

				  //handle case depending on escape type

				 	switch (*current_char) {

					    case 'n': str_buffer[char_position] = '\n'; break;
					    case 't': str_buffer[char_position] = '\t'; break;
					    case '\'': str_buffer[char_position] = '\''; break;
					    case '\"': str_buffer[char_position] = '\"'; break;
					    case '\\': str_buffer[char_position] = '\\'; break;

					    default:
						  print_error("has invalid escape in String");
					      free(str_buffer);
						  exit(1);
				 	}

				  	//Reset has_escape and advance character location
					has_escape = 0;
					char_position++;

				} else if(*current_char == '\\') {

				  // has escape  = true
				  has_escape = 1;
				  //continue to next char after escape
				  continue;

				} else {
				  str_buffer[char_position] = *current_char;
				  char_position++;
				}
			}

			str_buffer[char_position - 1] = '\0';
			yylval.treeptr->leaf->sval = strdup(str_buffer);
			yylval.treeptr->leaf->type = alctype(STRING_TYPE);
			free(str_buffer);

			break; }


		case CHARLIT: {

			if (strlen(yytext) == 3) {
				yylval.treeptr->leaf->ival = yytext[1];
			} else {

				char escape_type = yytext[2];

				switch (escape_type) {

					case '\'': yylval.treeptr->leaf->ival = '\''; break;
					case '\"': yylval.treeptr->leaf->ival = '\"'; break;
					case 't': yylval.treeptr->leaf->ival = '\t'; break;
					case 'n': yylval.treeptr->leaf->ival = '\n'; break;
					case '\\': yylval.treeptr->leaf->ival = '\\'; break;
					case '0': yylval.treeptr->leaf->ival = '\0'; break;

				}
			}
			yylval.treeptr->leaf->type = alctype(CHAR_TYPE);
			break; }

	    case REALLIT: {

	      // clear errno to catch potential strtof() error
	      errno = 0;
	      float float_value = strtof(yylval.treeptr->leaf->text, NULL);

	      // detect range error from errno.h
	      if (errno == ERANGE) {
			print_error("has invalid Real literal range");
			exit(1);
	      }

	      yylval.treeptr->leaf->dval = float_value;
		  yylval.treeptr->leaf->type = alctype(FLOAT_TYPE);

	      break; }

		  case BOOLLIT: {

			yylval.treeptr->leaf->type = alctype(BOOL_TYPE);

			break; }

		//   case '=':
		//   case '+':
		//   case '-':
		//   case '*':
		//   case '/':
		//   case '%': {
		// 	  printf("OPERATOR HIT\n");
	  //
		//   break;}
	  }

	  return yylval.treeptr->leaf->category;
}
