/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%option yylineno

%{
#include "defs.h"
#include "j0gram.tab.h"
extern int handle_token(int category_value);
int rows = 0, words = 0, chars = 0;
%}

%%
\n                           {/*discard comment */}
"#".*\n                      { /* no-op, discard comment */ }
"//".*\r?\n					 {/* no-op, discard single line comment */}
"/*"([^*]|"*"+[^/*])*"*"+"/" { /*discard multi-line comment */ }
[ \t\r\f]+                   { /*discard whitespace */ }

"boolean"             { return handle_token(BOOL); }
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
"null"								{ return handle_token(NULLVAL);}
"String"							{ return handle_token(STRING); }


"="                   { return handle_token('='); }
"+"                   { return handle_token('+'); }
"-"                   { return handle_token('-'); }
"*"                   { return handle_token('*'); }
"/"                   { return handle_token('/'); }
"%"                   { return handle_token('%'); }
"++"                  { return handle_token(INCREMENT); }
"--"                  { return handle_token(DECREMENT); }
"=="                  { return handle_token(ISEQUALTO); }
"!="                  { return handle_token(NOTEQUALTO); }
">"                   { return handle_token('>'); }
"<"                   { return handle_token('<'); }
">="                  { return handle_token(GREATERTHANOREQUAL); }
"<="                  { return handle_token(LESSTHANOREQUAL); }
"&&"                  { return handle_token(LOGICALAND); }
"||"                  { return handle_token(LOGICALOR); }
"!"                   { return handle_token(LOGICALNOT); }
"["                   { return handle_token('['); }
"]"                   { return handle_token(']'); }
"."                   { return handle_token('.'); }
"(type)"              { return handle_token(TYPE); }


"("                   { return handle_token('('); }
")"                   { return handle_token(')'); }
","                   { return handle_token(','); }
";"                   { return handle_token(';'); }
"{"                   { return handle_token('{'); }
"}"                   { return handle_token('}'); }
":"                   { return handle_token(':'); }

"#"                   {return handle_token(INVALID_PUNCTUATION); }
"$"                   {return handle_token(INVALID_PUNCTUATION); }
"@"                   {return handle_token(INVALID_PUNCTUATION); }
"\\"                  {return handle_token(INVALID_PUNCTUATION); }
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

"-"?[0-9]+"."[0-9]*   {return handle_token(REALLIT); }
"-"?[0-9]*"."[0-9]+   {return handle_token(REALLIT); }
"-"?[0-9]+            { return handle_token(INTLIT); }
\"([^"\n]|("\\\""))*\" { return handle_token(STRINGLIT); }
"true"                { return handle_token(BOOLLIT); }
"false"               { return handle_token(BOOLLIT); }
'.'                   { return handle_token(CHARLIT); }
'\\n'                 { return handle_token(CHARLIT); }
'\\t'                 { return handle_token(CHARLIT); }
'\\''                 { return handle_token(CHARLIT); }
'\\\"'                { return handle_token(CHARLIT); }
'\\\\'                { return handle_token(CHARLIT); }
'\\.'                 { return handle_token(INVALID_CHARLIT_ESCAPE); }
"''"                  { return handle_token(EMPTY_CHARLIT); }
'[^']{2,}'			  { return handle_token(OPENENDED_CHARLIT); }

[A-Za-z_$][A-Za-z0-9_$]*          { return handle_token(IDENTIFIER); }
.                     { chars++; return handle_token(UNRECOGNIZED_CHARACTER); }
%%
