#include "defs.h"
#include "j0gram.tab.h"

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

  create_token(category_value);

  switch (category_value) {

    case NOT_IN_JZERO_RESERVED:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", filename, yylineno, yytext);
      exit(1);
      break;

    case INVALID_PUNCTUATION:
      printf("\n%s:%d: error: '%s' is not supported in jzero\n\n", filename, yylineno, yytext);
      exit(1);
      break;

    case INVALIDCHARLIT: {
      printf("\n%s:%d: error: %s Invalid char literal\n\n", filename, yylineno, yytext);
      exit(1);
      break; }

    case INTLIT: {
      long number =  strtol(yytoken->text, NULL, 10);
      //Validate number with min and max allowed INT in Java
      if (number > 2147483647 || number < -2147483648) {
        yytoken->category = INTLIT_RANGE_INVALID;
        return yytoken->category;
      }
      yytoken->ival = number;
      break; }

    case STRINGLIT: {
      char *str_buffer = malloc((strlen(yytext) + 1) * sizeof(char));
      char has_escape = 0;
      int char_position = 0;

      for (char *current_char = (yytext + 1); *current_char != '\0'; current_char++) {
        if (has_escape) {
          //handle case depending on escape type
          switch (*current_char) {
            case 'n':
              str_buffer[char_position] = '\n';
              break;
            case 't':
              str_buffer[char_position] = '\t';
              break;
            case '\'':
              str_buffer[char_position] = '\'';
              break;
            case '\"':
              str_buffer[char_position] = '\"';
              break;
            case '\\':
              str_buffer[char_position] = '\\';
              break;
            default:
              yytoken->category = INVALID_ESCAPE_IN_STRING;
              free(str_buffer);
              return yytoken->category;
          }
          //reset has_escape and advance character location
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
      yytoken->sval = strdup(str_buffer); //need to de-escape strings here
      free(str_buffer);
      break; }

    case REALLIT: {
      // clear errno to catch potential strtof() error
      errno = 0;
      float float_value = strtof(yytoken->text, NULL);
      // detect range error from errno.h
      if (float_value == ERANGE) {
        yytoken->category = REALLIT_RANGE_INVALID;
        return yytoken->category;
      }
      yytoken->dval = float_value;
      break; }
  }
  return yytoken->category;
}
