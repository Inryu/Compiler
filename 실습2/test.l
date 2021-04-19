%{
/*
 * test.l - lexical analyzer for lab#1
 *
 * Programmer - Byoungju Choi
 *
 * date - 3/31/2016
 *
 * modification history
 * 
*/

#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TIDEN, TNUM, TASSIGN, TADD, TSEMI, TDOT, TBEGIN, TEND, TERROR, TINT};
%}

letter   [a-zA-Z_]
digit   [0-9]

%%
"{" return(TBEGIN);
"}" return(TEND);
int return(TINT);
%%

void main()
{
   enum tnumber tn;  // token number
   printf("  Start of Lex\n");
   while  ((tn = yylex()) != TEOF) {
      switch (tn) {
         case TBEGIN  : printf("begin\n");  break;
         case TEND    : printf("end\n"); break;
         case TINT    : printf("integer\n"); break;

      }
   }
}

int yywrap()
{
   printf("	End of Lex\n");
   return 1;
}