/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap

			int rows = 0, words = 0, chars = 0;

%%
\n		rows++;
[A-Za-z0-9]+	words++; chars += strlen(yytext);
.		chars++;
%%
