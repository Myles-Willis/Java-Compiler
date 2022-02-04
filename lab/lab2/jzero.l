/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
            #define word 257
            int rows = 0, words = 0, chars = 0;

%%
\n        rows++;
[A-Za-z0-9]+    words++; chars += strlen(yytext); return word;
.        chars++;
"/*"([^*]|"*"+[^/*])*"*"+"/" { /* no-op, discard comment */ }
"//".*\r?\n                  { /* no-op, discard comment */ }
[ \t\r\f]+                   { /* no-op, discard whitespace */ }
%%

strlen(hello);
