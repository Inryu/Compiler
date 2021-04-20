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
#include "glob.h"
extern reporterror(enum tnumber tn);
%}

%%

[a-zA Z_][a zA Z0 9_]* {

  if(yyleng>MaxIdentLen){
    reporterror(TLONG);
  }

  else{
    SymmbolTable();
    return (TIDENT);
  }
}
 
 //줄바꿈
 // 1) //
 // 2)/* */
 // 3) /*
 
 (줄바꿈) */
 
[0-9][a-zA-Z_0-9]+ { return (TILLIDENT)}
\/\/.* return (TONECMT); // 주석 1)

 /*
 \/*.*\*\/ {return (TSTARCMT)}; // 주석 2)
 */

“/*”([^*]|”*”+[^*/])*”*”+”/” return (TMULCMT); // 주석 2), 3) => main에서 줄 바꿈 처리





“/*”([^*]|”*”+[^*/])*”*”+”/” return (TMULCMT);
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
[\t] return(TTAB);
[\n] {
  lineno++;
  return(TNEWLINE);
}
.    return(TILLCHAR);

 //illegal char
 // ill IDENT


%%
int yywrap()
{
  printf("	End of Lex\n");
  return 1;
}