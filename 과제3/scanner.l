%{
/*
* scanner.l- lexical analyzer for the MiniC(HW3)
*
* Programmer - team2
*
* date - 
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h" /* token name definition */
#include "glob.h" /* global variation */


extern yyerror(char *s);
int i;

%}



%%

 /*
 * Keyword(예약어)
 */
"const" {yyerror("tconst"); return(TCONST);}
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" {yyerror("tvoid"); return(TVOID);}
"while" return(TWHILE);

 /*
 * ILL Identifier
 */
[0-9]+[a-zA-Z_][a-zA-Z0-9_]* {yyerror("scanner error : start with digit identifier");}

 /*
 * 주석문
 */
\/\/.* ;
\/\*([^*]|\*+[^*/])*\*+\/ {
   for(i=0;i<yyleng;i++){
      if(yytext[i]=='\n') cLine++;
   }

}



 /*
 * Operator (연산자)
 */
"+" return(TPLUS);
"-" return(TMINUS);
"*" return(TSTAR);
"/" return(TSLASH);
"%" return(TMOD);
"=" {yyerror("tassign");return(TASSIGN);}
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);
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


 /*
 * Special Symbols
 */
"(" {yyerror("OPEN small bra"); return(TOSBRA);}
")" {yyerror("CLOSE small bra"); return(TCSBRA);}
"," {yyerror("comma");return(TCOMMA);}
"{" return(TOMBRA);
"}" return(TCMBRA);
"[" return(TOLBRA);
"]" return(TCLBRA);
";" {return(TSEMI);}



 /*
 * White spaces
 */
[ \t] ;
[\n] {
  cLine++;
}

 /*
 * Identifier (명칭)
  */
[a-zA-Z_][a-zA-Z0-9_]* {

  if(yyleng>MaxIdentLen){ 
    reporterror(tlong);
  }

  else{
    SymmbolTable();
    return (TIDENT);
  }
}

 /*
 * Constant (상수)
 */
[0-9]+  {yyerror("tnumber"); return(TNUMBER);}
[0-9]+\.[0-9]+ return(TFLOAT);

 /*
 * illegal Symbol
 */
.   {yyerror("scanner error : illegal separator");}

%%

int yywrap(){
  return 1;
}


