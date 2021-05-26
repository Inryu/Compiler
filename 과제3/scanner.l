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
extern SymmbolTable();
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
 *   identifier로 인식된 token을 한 글자씩 ST에 넣음. (yytext, yyleng이용)
 *   해당 identifier의 hashcode값을 계산.
 *   HT[hashcode]에 identifier가 이미 있는지 확인
 *   이미 있으면, 현재 읽은 identifier를 ST에서 삭제
 *   아직 없으면, HT[hashcode]의 index에 identifier의 ST에서의 첫 인덱스 값을 넣음
 */
 
[a-zA-Z_][a-zA-Z0-9_]* {

  if(yyleng>MaxIdentLen){ 
    reporterror(tlong);
    return(TLONG);
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
      ADDHT(hashcode);
    }
    else {
      nextfree = nextid;
    }
    return (TIDENT);
  }
}

 /*
 * Constant (상수) 
 */
[0-9]+  {return(TNUMBER);}
[0-9]+\.[0-9]+ return(TPOINT);

 /*
 * illegal Symbol
 */
.   {yyerror("scanner error : illegal separator");}

%%

int yywrap(){
  return 1;
}


