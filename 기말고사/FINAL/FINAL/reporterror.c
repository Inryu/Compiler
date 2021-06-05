/*
* reporterror.c - 에러 출력 (HW3)
*
* Programmer - team2
*
* date - 5/26/2021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
#include "glob.h"



extern char *yytext;
extern yylex();


/*
* yyerror() - 사용자 error 메세지 직접 출력 함수
*/
void yyerror(char *s) {
	if (s != "parse error") { //parser_tab.c에서 발생한 parse에러가 아닌경우
		printf("\t%-5d %-10s %-50s\n", cLine, yytext, s);//에러 메세지 출력
		cErrors++;//에러수 1 증가 
	}
}


/* reporterror
* token type별로 에러를 나누고, 에러 수를 1씩 증가시킨 후, 해당 에러문 출력
* 0)wrong_funcdef : 올바르지 않은 함수 선언
* 1)nosemi : semicolon을 사용하지 않은 경우
* 2)nobrace : 올바르지 않은 형식의 중괄요 사용(missing brace)
* 3)nobraket : 올바르지 않은 형식의 대괄호 사용
* 4)long : 12자를 초과하는 identifier
* 5)overflow : table의 size를 초과한 경우
*/
void reporterror(ERRORtypes err) {
	switch (err) {
	case 0: //wrong_funcdef
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Wrong function definition");
		cErrors++;
		break;

	case 1: //nosemi
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Missing semicolon");
		cErrors++;
		break;

	case 2: //nobrace (중괄호)
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Missing brace");
		cErrors++;
		break;
	case 3: //nobraket (대괄호)
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Missing bracket");
		cErrors++;
		break;
	case 4: //long 
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Long identifier");
		cErrors++;
		break;
	case 5: //overflow
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Overflow");
		cErrors++;
		break;
	case 6: //no comma
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Missing Comma");
		cErrors++;
		break;

	case 7: //wrong statement
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", "Wrong Statement");
		cErrors++;
		break;

	}
}