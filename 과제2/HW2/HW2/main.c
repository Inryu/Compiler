#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern yylex();
extern char *yytext;

void printttoken(enum tnumber tn) {

	//line number 출력


	switch (tn) {

	//주석문
	case TONECMT: 		
		printf("%-20d %-20s %-20s %-30s", lineno, "comment", " ", str(yytext));
		break;
	case TMULCMT: printf("Multiple Line Comment\n"); break;
	case TIDENT: printf("Ident\n"); break;

	//상수
	case TDECIMAL: printf("Number\n"); break;
	case TFIXED: printf("Real Number\n"); break;
	//예약어
	case TCONST: printf("Const\n"); break;
	case TELSE: printf("Else\n"); break;
	case TIF: printf("If\n"); break;
	case TINT: printf("Integer\n"); break;
	case TRETURN: printf("Return\n"); break;
	case TVOID: printf("Void\n"); break;
	case TWHILE: printf("While\n"); break;

		//사칙연산자
	case TPLUS: printf("Plus\n"); break;
	case TMINUS: printf("Minus\n"); break;
	case TSTAR: printf("Multiplication\n"); break;
	case TSLASH: printf("divider\n"); break;
	case TMOD: printf("Mod\n"); break;

		//배정 연산자
	case TASSIGN: printf("assign\n"); break;
	case TADDASSIGN: printf("add assign\n"); break;
	case TSUBASSIGN: printf("sub assign\n"); break;
	case TMULASSIGN: printf("mul assign\n"); break;
	case TDIVASSIGN: printf("div assign\n"); break;
	case TMODASSGIN: printf("mod than\n"); break;

	//논리연산자
	case TNOT: printf("Not Equal\n"); break;
	case TAND: printf("And\n"); break;
	case TOR: printf("Or\n"); break;

		//관계연산자
	case TEQUAL: printf("Equal\n"); break;
	case TNOTEQU: printf("Not Equal\n"); break;
	case TLESS: printf("Less\n"); break;
	case TOVER: printf("Over\n"); break;
	case TLESSE: printf("Less or Equal\n"); break;  //나중에 레포트에만 명시하기
	case TOVERE: printf("Over or Equal\n"); break;

		//증감연산자
	case TINC: printf("Increase 1\n"); break;
	case TDEC: printf("Decrease 1\n"); break;

		//Special Symbols
	case TOSBRA: printf("Open Small Bracket\n"); break;
	case TCSBRA: printf("Close Small Bracket\n"); break;
	case TCOMMA: printf("Comma\n"); break;
	case TOMBRA: printf("Open Middle Bracket\n"); break;
	case TCMBRA: printf("Close Middle Bracket\n"); break;
	case TOLBRA: printf("Open Large Bracket\n"); break;
	case TCLBRA: printf("Close Large Bracket\n"); break;
	case TSEMI: printf("Semicolon\n"); break;

		//White Spaces
	case TBLANK: printf("Blank\n"); break;
	case TTAB: printf("Tab\n"); break;
	case TNEWLINE: printf("New Line\n"); break;
	}
}


void main()
{
	enum tnumber tn;  // token number
	
	//print header
	printf("%-20s %-20s %-20s %-30s", "Line number", "Token type", "ST-index", "Token");
	
	//print ttoken
	while ((tn = yylex()) != TEOF) {
		printttoken(tn);
	}

	//print error


}