/*
* reporterror.c - ���� ��� (HW3)
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
* yyerror() - ����� error �޼��� ���� ��� �Լ�
*/
void yyerror(char *s) {
	if (s != "parse error") { //parser_tab.c���� �߻��� parse������ �ƴѰ��
		printf("\t%-5d %-10s %-50s\n", cLine, yytext, s);//���� �޼��� ���
		cErrors++;//������ 1 ���� 
	}
}


/* reporterror
* token type���� ������ ������, ���� ���� 1�� ������Ų ��, �ش� ������ ���
* 0)wrong_funcdef : �ùٸ��� ���� �Լ� ����
* 1)nosemi : semicolon�� ������� ���� ���
* 2)nobrace : �ùٸ��� ���� ������ �߰��� ���(missing brace)
* 3)nobraket : �ùٸ��� ���� ������ ���ȣ ���
* 4)long : 12�ڸ� �ʰ��ϴ� identifier
* 5)overflow : table�� size�� �ʰ��� ���
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

	case 2: //nobrace (�߰�ȣ)
		printf("\t%-5d %-15s %-50s\n", cLine, "***Error***", " Missing brace");
		cErrors++;
		break;
	case 3: //nobraket (���ȣ)
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

	}
}