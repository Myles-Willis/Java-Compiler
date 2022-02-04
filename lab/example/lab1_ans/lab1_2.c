#include <stdio.h>
FILE *yyin;
/* cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
   FILE *fp;
   void filecopy(FILE *, FILE *);

   if (argc == 1)
      filecopy(stdin, stdout);
   else
      while (--argc > 0)
         if ((fp = fopen(*++argv, "r")) == NULL) {
            printf("cat: can't open %s\n", *argv);
            return 1;
            }
         else {
            filecopy(fp, stdout);
            fclose(fp);
            }
   return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
   int c;
   yyin = ifp;
   int yylex();
   while ((c = yylex()) != EOF)
      putc(c, ofp);
}


int yylex()
{
    int i;
    i = getc(yyin);
    return i;
}