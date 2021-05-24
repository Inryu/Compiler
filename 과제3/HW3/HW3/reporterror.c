/*
* reporterror.c - 에러 출력 (HW3)
*
* Programmer - team2
*
* date
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
#include "glob.h"
extern char *yytext;

//☆★☆★!!!!!!!!!!line 함수 보류=> parser.y에 선언되어있음☆★☆★
extern yylex();



/*
* yyerror() - 사용자 error 메세지 직접 출력 함수
*/
void yyerror(char *s) {
	//printf("-5d %-15s %-50s\n", cLine, "***Error***", s);
	printf("[%-2d] %-50s\n", cLine, s);

	cErrors++;
}


/* reporterror
* token type별로 에러를 나누고 해당 에러문 출력
1)TILLIDENT : 잘못된 identifier
2)TILLSYM : 올바르지 않은 symbol
3)TLONG : 13자 이상인 identifier
4)TOVERFLOW : ST overflow
*/
void reporterror(ERRORtypes err) {
	switch (err) { 
	case 0: //wrong_st
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Wrong statement");
		cErrors++;
		break;

	case 1: //wrong_funcdef
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Wrong function definition");
		cErrors++;
		break;

	case 2: //nosemi
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Missing semicolon");
		cErrors++;
		break;

	case 3: //nobrace (중괄호)
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Missing brace");
		cErrors++;
		break;
	case 4: //nobraket (대괄호)
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Missing bracket");
		cErrors++;
		break;
	case 5: //long 
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Long identifier");
		cErrors++;
		break;
	case 6:
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Overflow");
		cErrors++;
		break;


		//☆★☆★!!!!!!!!!!소괄호는?☆★☆★

	}
}