/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%option yylineno

%{
#include "defs.h"
extern int handle_token(int category_value);
int rows = 0, words = 0, chars = 0;
%}

%%
\n                           { rows++; }
^#.+                         { /* no-op, discard comment */ }
"/*"([^*]|"*"+[^/*])*"*"+"/" { /* no-op, discard multi-line comment */ }
[ \t\r\f]+                   { /* no-op, discard whitespace */ }


"boolean"             { return handle_token(BOOLEAN); }
"break"               { return handle_token(BREAK); }
"case"                { return handle_token(CASE); }
"char"                { return handle_token(CHAR); }
"class"               { return handle_token(CLASS); }
"continue"            { return handle_token(CONTINUE); }
"default"             { return handle_token(DEFAULT); }
"double"              { return handle_token(DOUBLE); }
"else"                { return handle_token(ELSE); }
"float"               { return handle_token(FLOAT); }
"for"                 { return handle_token(FOR); }
"if"                  { return handle_token(IF); }
"instanceof"          { return handle_token(INSTANCEOF); }
"int"                 { return handle_token(INT); }
"long"                { return handle_token(LONG); }
"new"                 { return handle_token(NEW); }
"public"              { return handle_token(PUBLIC); }
"return"              { return handle_token(RETURN); }
"static"              { return handle_token(STATIC); }
"switch"              { return handle_token(SWITCH); }
"void"                { return handle_token(VOID); }
"while"               { return handle_token(WHILE); }

([0-9]*"."[0-9]{1,7})        {return handle_token(FLOAT_LITERAL); }
-?[0-9]+              { return handle_token(INTEGER_LITERAL); }

"="                   { return handle_token(EQUALS); }
"+"                   { return handle_token(PLUS); }
"-"                   { return handle_token(MINUS); }
"*"                   { return handle_token(MULTIPLY); }
"/"                   { return handle_token(DIVIDE); }
"%"                   { return handle_token(MODULO); }
"++"                  { return handle_token(INCREMENT); }
"--"                  { return handle_token(DECREMENT); }
"=="                  { return handle_token(IS_EQUAL_TO); }
"!="                  { return handle_token(NOT_EQUAL_TO); }
">"                   { return handle_token(GREATER_THAN); }
"<"                   { return handle_token(LESS_THAN); }
">="                  { return handle_token(GREATER_THAN_EQUAL); }
"<="                  { return handle_token(LESS_THAN_EQUAL); }
"&&"                  { return handle_token(LOGICAL_AND); }
"||"                  { return handle_token(LOGICAL_OR); }
"!"                   { return handle_token(LOGICAL_NOT); }
"["                   { return handle_token(LEFT_BRACKET); }
"]"                   { return handle_token(RIGHT_BRACKET); }
"."                   { return handle_token(DOT); }
"(type)"              { return handle_token(TYPE); }


\"([^\"]*|(\\.)*)\"   { return handle_token(STRING_LITERAL); }
'.'                   { return handle_token(CHAR_LITERAL); }
'\\n'                 { return handle_token(CHAR_LITERAL); }
'\\t'                 { return handle_token(CHAR_LITERAL); }
'\\\''                { return handle_token(CHAR_LITERAL); }
'\\\"'                { return handle_token(CHAR_LITERAL); }
\'\'                  { return handle_token(INVALID_CHAR_LITERAL); }
"true"                { return handle_token(BOOLEAN_LITERAL); }
"false"               { return handle_token(BOOLEAN_LITERAL); }
'.+'                  { return handle_token(INVALID_CHAR_LITERAL); }


"("                   { return handle_token(LEFT_PARENTHESIS); }
")"                   { return handle_token(RIGHT_PARENTHESIS); }
","                   { return handle_token(COMMA); }
";"                   { return handle_token(SEMICOLON); }
"{"                   { return handle_token(LEFT_BRACE); }
"}"                   { return handle_token(RIGHT_BRACE); }
":"                   { return handle_token(COLON); }

"#"                   {return handle_token(INVALID_PUNCTUATION); }
"$"                   {return handle_token(INVALID_PUNCTUATION); }
"@"                   {return handle_token(INVALID_PUNCTUATION); }
"\\"                   {return handle_token(INVALID_PUNCTUATION); }
"`"                   {return handle_token(INVALID_PUNCTUATION); }



"abstract"            { return handle_token(NOT_IN_JZERO_RESERVED); }
"assert"              { return handle_token(NOT_IN_JZERO_RESERVED); }
"byte"                { return handle_token(NOT_IN_JZERO_RESERVED); }
"catch"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"const"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"do"                  { return handle_token(NOT_IN_JZERO_RESERVED); }
"enum"                { return handle_token(NOT_IN_JZERO_RESERVED); }
"exports"             { return handle_token(NOT_IN_JZERO_RESERVED); }
"extends"             { return handle_token(NOT_IN_JZERO_RESERVED); }
"final"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"finally"             { return handle_token(NOT_IN_JZERO_RESERVED); }
"goto"                { return handle_token(NOT_IN_JZERO_RESERVED); }
"implements"          { return handle_token(NOT_IN_JZERO_RESERVED); }
"import"              { return handle_token(NOT_IN_JZERO_RESERVED); }
"interface"           { return handle_token(NOT_IN_JZERO_RESERVED); }
"module"              { return handle_token(NOT_IN_JZERO_RESERVED); }
"native"              { return handle_token(NOT_IN_JZERO_RESERVED); }
"package"             { return handle_token(NOT_IN_JZERO_RESERVED); }
"protected"           { return handle_token(NOT_IN_JZERO_RESERVED); }
"requires"            { return handle_token(NOT_IN_JZERO_RESERVED); }
"short"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"strictfp"            { return handle_token(NOT_IN_JZERO_RESERVED); }
"super"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"synchronized"        { return handle_token(NOT_IN_JZERO_RESERVED); }
"this"                { return handle_token(NOT_IN_JZERO_RESERVED); }
"throw"               { return handle_token(NOT_IN_JZERO_RESERVED); }
"throws"              { return handle_token(NOT_IN_JZERO_RESERVED); }
"transient"           { return handle_token(NOT_IN_JZERO_RESERVED); }
"try"                 { return handle_token(NOT_IN_JZERO_RESERVED); }
"var"                 { return handle_token(NOT_IN_JZERO_RESERVED); }
"volatile"            { return handle_token(NOT_IN_JZERO_RESERVED); }
"private"             { return handle_token(NOT_IN_JZERO_RESERVED); }

[A-Za-z0-9]+          { words++; chars += strlen(yytext); return handle_token(WORD); }
.                     { chars++; return handle_token(UNRECOGNIZED_CHARACTER); }
%%
