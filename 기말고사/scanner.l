%{
/*
* scanner.l- lexical analyzer for the MiniC(HW3)
*
* Programmer - team2
*
* date -  5/26/2021
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h" /* token name definition */
#include "glob.h" /* global variation */

extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern SymbolTable();
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
"float" return(TFLOAT);
"return" return(TRETURN);
"void" {return(TVOID);}
"while" return(TWHILE);
"char" return (TCHAR);
"string" return(TSTRING);



 /*
 * Constant (상수) 
 */
0(x|X)[0-9A-Fa-f]+|[1-9][0-9]* return(TNUMBER);
[0-9]+\.[0-9]+ return(TPOINT);


 /*
 * ILL Identifier
 */
[0-9]+[a-zA-Z_][a-zA-Z0-9_]* {
    yyerror("scanner error : start with digit identifier");
    return (TILLIDENT);
}

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
  Identifier (명칭)
 *   13자 이상일 경우, 에러 호출
 *   아닌 경우, SymbolTable 호출 (ST삽입, hashcode계산, HT삽입 수행)
 */
 
[a-zA-Z_][a-zA-Z0-9_]* {

    SymbolTable();
    return (TIDENT);
 
}


 /*
 * 문자상수
 */
"'"."'" {
  return(TCHARVAR);
} 

 /*
 * 문자열상수
 */

\"([^\042\134]|"\\"(.|[\n]))*\" return(TSTRINGVAR);


 /*
 * illegal Symbol
 */
.   {yyerror("scanner error : illegal separator");}

%%

int yywrap(){
  return 1;
}


