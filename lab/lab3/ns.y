%{
    #include <stdio.h>
    extern int yylex();
    extern int yyerror(char*s);
%}
%token NAME NUMBER
%%
sequence : pair sequence | ;
pair : NAME NUMBER ;
