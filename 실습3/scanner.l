%{
/*
 * scanner.l- lexical analyzer for lab#3
 *
 * Programmer - team2
 *
 * date - 4/7/2021
 *
 * modification history
 * 
*/

#include <stdio.h>
#include <stdlib.h>
enum tnumber { TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESSE, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN
, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
%}

letter   [a-zA-Z_]
digit   [0-9]

%%
"const" return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"==" return(TEQUAL);
"!=" return(TNOTEQU);
"<=" return(TLESSE);
">=" return(TGREATE);
"&&" return(TAND);
"||" return(TOR);
"++" return(TINC);
"--" return(TDEC);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]* return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)? return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/" ;
"//".* ;
[ \t\n] ;
.         return(yytext[0]);

%%

void main()
{
   enum tnumber tn;  // token number
   printf("  Start of Lex\n");
   while  ((tn = yylex()) != TEOF) {
      switch (tn) {
         case TCONST  : printf("Const\n");  break;
         case TELSE    : printf("Else\n"); break;
         case TIF    : printf("If\n"); break;
         case TINT    : printf("Integer\n"); break;
         case TRETURN    : printf("Return\n"); break;
         case TVOID    : printf("Void\n"); break;
         case TWHILE    : printf("While\n"); break;
         case TEQUAL    : printf("Equal\n"); break;
         case TNOTEQU    : printf("Not Equal\n"); break;
         case TLESSE    : printf("Less than\n"); break;
         case TGREATE    : printf("Greater than\n"); break;
         case TAND    : printf("And\n"); break;
         case TOR    : printf("Or\n"); break;
         case TINC    : printf("Increase\n"); break;
         case TDEC    : printf("Decrease\n"); break;
         case TADDASSIGN    : printf("Add Assign\n"); break;
         case TMULASSIGN    : printf("Mul Assign\n"); break;
         case TDIVASSIGN    : printf("Div Assign\n"); break;
         case TMODASSIGN    : printf("Mod Assign\n"); break;
         case TIDENT    : printf("Identifier\n"); break;
         case TNUMBER    : printf("Number\n"); break;


      }
   }
}

int yywrap()
{
   printf("	End of Lex\n");
   return 1;
}