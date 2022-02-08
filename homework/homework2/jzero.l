/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
            #include "defs.h"
            int rows = 0, words = 0, chars = 0;

%%
\n                           { rows++; }
^#.+                         { /* no-op, discard comment */ }
"/*"([^*]|"*"+[^/*])*"*"+"/" { /* no-op, discard multi-line comment */ }
[ \t\r\f]+                   { /* no-op, discard whitespace */ }


"boolean"             { return BOOLEAN; }
"break"               { return BREAK; }
"case"                { return CASE; }
"char"                { return CHAR; }
"class"               { return CLASS; }
"continue"            { return CONTINUE; }
"default"             { return DEFAULT; }
"double"              { return DOUBLE; }
"else"                { return ELSE; }
"float"               { return FLOAT; }
"for"                 { return FOR; }
"if"                  { return IF; }
"instanceof"          { return INSTANCEOF; }
"int"                 { return INT; }
"long"                { return LONG; }
"new"                 { return NEW; }
"public"              { return PUBLIC; }
"return"              { return RETURN; }
"static"              { return STATIC; }
"switch"              { return SWITCH; }
"void"                { return VOID; }
"while"               { return WHILE; }

([0-9]*"."[0-9]{1,7})        {return FLOAT_LITERAL; }
-?[0-9]+              { return INTEGER_LITERAL; }

"="                   { return EQUALS; }
"+"                   { return PLUS; }
"-"                   { return MINUS; }
"*"                   { return MULTIPLY; }
"/"                   { return DIVIDE; }
"%"                   { return MODULO; }
"++"                  { return INCREMENT; }
"--"                  { return DECREMENT; }
"=="                  { return IS_EQUAL_TO; }
"!="                  { return NOT_EQUAL_TO; }
">"                   { return GREATER_THAN; }
"<"                   { return LESS_THAN; }
">="                  { return GREATER_THAN_EQUAL; }
"<="                  { return LESS_THAN_EQUAL; }
"&&"                  { return LOGICAL_AND; }
"||"                  { return LOGICAL_OR; }
"!"                   { return LOGICAL_NOT; }
"["                   { return LEFT_BRACKET; }
"]"                   { return RIGHT_BRACKET; }
"."                   { return DOT; }
"(type)"              { return TYPE; }


\"([^\"]*|(\\.)*)\"   { return STRING_LITERAL; }
'.'                   { return CHAR_LITERAL; }
'\\n'                 { return CHAR_LITERAL; }
'\\t'                 { return CHAR_LITERAL; }
'\\\''                { return CHAR_LITERAL; }
'\\\"'                { return CHAR_LITERAL; }
\'\'                  { return INVALID_CHAR_LITERAL; }
"true"                { return BOOLEAN_LITERAL; }
"false"               { return BOOLEAN_LITERAL; }
'.+'                  { return INVALID_CHAR_LITERAL; }


"("                   { return LEFT_PARENTHESIS; }
")"                   { return RIGHT_PARENTHESIS; }
","                   { return COMMA; }
";"                   { return SEMICOLON; }
"{"                   { return LEFT_BRACE; }
"}"                   { return RIGHT_BRACE; }
":"                   { return COLON; }

"#"                   {return INVALID_PUNCTUATION; }
"$"                   {return INVALID_PUNCTUATION; }
"@"                   {return INVALID_PUNCTUATION; }
"\\"                   {return INVALID_PUNCTUATION; }
"`"                   {return INVALID_PUNCTUATION; }



"abstract"            { return NOT_IN_JZERO_RESERVED; }
"assert"              { return NOT_IN_JZERO_RESERVED; }
"byte"                { return NOT_IN_JZERO_RESERVED; }
"catch"               { return NOT_IN_JZERO_RESERVED; }
"const"               { return NOT_IN_JZERO_RESERVED; }
"do"                  { return NOT_IN_JZERO_RESERVED; }
"enum"                { return NOT_IN_JZERO_RESERVED; }
"exports"             { return NOT_IN_JZERO_RESERVED; }
"extends"             { return NOT_IN_JZERO_RESERVED; }
"final"               { return NOT_IN_JZERO_RESERVED; }
"finally"             { return NOT_IN_JZERO_RESERVED; }
"goto"                { return NOT_IN_JZERO_RESERVED; }
"implements"          { return NOT_IN_JZERO_RESERVED; }
"import"              { return NOT_IN_JZERO_RESERVED; }
"interface"           { return NOT_IN_JZERO_RESERVED; }
"module"              { return NOT_IN_JZERO_RESERVED; }
"native"              { return NOT_IN_JZERO_RESERVED; }
"package"             { return NOT_IN_JZERO_RESERVED; }
"protected"           { return NOT_IN_JZERO_RESERVED; }
"requires"            { return NOT_IN_JZERO_RESERVED; }
"short"               { return NOT_IN_JZERO_RESERVED; }
"strictfp"            { return NOT_IN_JZERO_RESERVED; }
"super"               { return NOT_IN_JZERO_RESERVED; }
"synchronized"        { return NOT_IN_JZERO_RESERVED; }
"this"                { return NOT_IN_JZERO_RESERVED; }
"throw"               { return NOT_IN_JZERO_RESERVED; }
"throws"              { return NOT_IN_JZERO_RESERVED; }
"transient"           { return NOT_IN_JZERO_RESERVED; }
"try"                 { return NOT_IN_JZERO_RESERVED; }
"var"                 { return NOT_IN_JZERO_RESERVED; }
"volatile"            { return NOT_IN_JZERO_RESERVED; }
"private"             { return NOT_IN_JZERO_RESERVED; }

[A-Za-z0-9]+          { words++; chars += strlen(yytext); return WORD; }
.                     { chars++; return UNRECOGNIZED_CHARACTER; }
%%
