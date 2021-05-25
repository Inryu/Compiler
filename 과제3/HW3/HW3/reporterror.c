/*
* reporterror.c - ���� ��� (HW3)
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

//�١ڡ١�!!!!!!!!!!line �Լ� ����=> parser.y�� ����Ǿ������١ڡ١�
extern yylex();


/*
* yyerror() - ����� error �޼��� ���� ��� �Լ�
*/
void yyerror(char *s) {
	//printf("-5d %-15s %-50s\n", cLine, "***Error***", s);
	printf("[%-2d] %-50s\n", cLine, s);

	cErrors++;
}


/* reporterror
* token type���� ������ ������ �ش� ������ ���
1)TILLIDENT : �߸��� identifier
2)TILLSYM : �ùٸ��� ���� symbol
3)TLONG : 13�� �̻��� identifier
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

	case 3: //nobrace (�߰�ȣ)
		printf("%-5d %-15s %-50s\n", cLine, "***Error***", " Missing brace");
		cErrors++;
		break;
	case 4: //nobraket (���ȣ)
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


		//�١ڡ١�!!!!!!!!!!�Ұ�ȣ��?�١ڡ١�

	}
}