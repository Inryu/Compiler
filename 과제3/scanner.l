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

extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern ADDHT(int hscode);
extern PrintHStable();
extern yyerror(char *s);
int i;

%}



%%

 /*
 * Keyword(예약어)
 */
"const" {return(TCONST);}
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" {return(TVOID);}
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
"=" {return(TASSIGN);}
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
"(" {return(TOSBRA);}
")" { return(TCSBRA);}
"," {return(TCOMMA);}
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
    nextid = nextfree;

    if (nextfree == STsize) {
      reporterror(toverflow);
      PrintHStable();
      exit(1);
    }
        
    for (int i = 0; i < yyleng; i++) {
      ST[nextfree++] = yytext[i];
    }

    ST[nextfree++] = '\0';

    ComputeHS(nextid, nextfree);
    LookupHS(nextid, hashcode);

    if (!found) {    
      // printf("[%-2d] %-35s %-30s\n", cLine, "Identifier", yytext);
      
      ADDHT(hashcode);
    }
    else {
      // printf("[%-2d] %-35s %-30s\n", cLine, "Identifier", yytext);
      nextfree = nextid;
    }
    return (TIDENT);
  }
}

 /*
 * Constant (상수)
 */
[0-9]+  {return(TNUMBER);}
[0-9]+\.[0-9]+ return(TFLOAT);

 /*
 * illegal Symbol
 */
.   {yyerror("scanner error : illegal separator");}

%%

int yywrap(){
  return 1;
}


