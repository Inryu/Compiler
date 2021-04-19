%{
/*
* scanner.l- lexical analyzer for Scanner(HW2)
*
* Programmer - team2
*
* date - 4/1/2021
*
* modification history
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
%}

%%

"//".* return (TONECMT);
“/*”([^*]|”*”+[^*/])*”*”+”/” return (TMULCMT);
[a-zA Z_][a zA Z0 9_]* return (TIDENT);
[+-]?[0-9]+ : return(TDECIMAL);
[+-]?[0-9]+\\.[0-9]+ : return(TFIXED);
"const" : return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"+" return(TPLUS);
"-" return(TMINUS);
"*" return(TSTAR);
"/" return(TSLASH);
"%" return(TMOD);
"=" return(TASSIGN);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSGIN);

//논리연산자 부터 시작
"!" return(TNOT);
"&&" return(TAND);
"||" return(TOR);
"==" return(TEQUAL);
"!=" return(TNOTEQU);
"<" return(TLESS);
">" return(TOVER);
"<=" return(TLESSE);
">=" return(TOVERE);
"++" return(TINC);
"--" return(TDEC);
"(" return(TOSBRA);
")" return(TCSBRA);
"," return(TCOMMA);
"{" return(TOMBRA);
"}" return(TCMBRA);
"[" return(TOLBRA);
"]" return(TCLBRA);
";" return(TSEMI);
" " return(TBLANK);
"\t" return(TTAB);
"\n" return(TNEWLINE);
.         return(yytext[0]); //이거 뭐임?
%%
int yywrap()
{
  printf("	End of Lex\n");
  return 1;
}