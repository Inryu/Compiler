/*
* main.c - lexical analyzer for Scanner : main (HW3)
*
* Programmer - team2
*
* 1871040이유정 / 1871026 신인류 / 1876136 박가현
*
* date -  6/05/2021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern int yyparse();
extern void PrintHStable();

void main() {

	look_id = (HTptr)malloc(sizeof(struct HTentry));
	look_tmp = (HTptr)malloc(sizeof(struct HTentry));
	printf("***TEAM 02***\n");
	printf("1871040 이유정\n");
	printf("1871026 신인류\n");
	printf("1876136 박가현\n");


	printf("\n\n\t\t\t    ***MiniC parsing begins***\n");
	printf("==================================================================================\n");

	/* cLine, nextid, nextfree 초기화 */
	cLine = 1;
	nextid = 0;
	nextfree = 0;

	/* 파싱 및 에러 타입 출력 */
	yyparse();


	printf("==================================================================================\n");
	printf("\n\t\t  ===> Parsing ends.");


	if (cErrors == 0) {
		printf("\t no errors detected\n\n\n\n");


	}

	else printf("\t %d error(s) detected\n\n\n\n", cErrors);

	/* HS테이블 출력*/
	PrintHStable();
}