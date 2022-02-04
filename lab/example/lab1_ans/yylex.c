#include <stdio.h>

FILE *yyin;

int yylex()
{
    return getc(yyin);
}