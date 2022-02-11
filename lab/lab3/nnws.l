%option noyywrap
%option nounput
%option noinput
%{
  #include "ns.tab.h"
%}
%%
[a-zA-Z]+ { return NAME; }
[0-9]+ { return NUMBER; }
[ \t\n]+ { }
. { fprintf(stderr, "bad char\n"); }
