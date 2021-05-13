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
//extern char *yytext;

//�١ڡ١�!!!!!!!!!!line �Լ� ����=> parser.y�� ����Ǿ������١ڡ١�
//extern line(int);
extern yylex();



/*
* yyerror() - ����� error �޼��� ���� ��� �Լ� 
*/
void yyerror(char *s) {
	printf("%s", s);
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
		printf("< Error > => Wrong Statement!\n");
		cErrors++;
		break;

	case 1: //wrong_funcdef
		printf("< Error > => Wrong function definition\n");
		cErrors++;
		break;

	case 2: //nosemi
		printf("< Error > => Missing semicolon\n");
		cErrors++;
		break;

	case 3: //nobrace (�߰�ȣ)
		printf("< Error > = > Missing brace\n");
		cErrors++;
		break;
	case 4: //nobraket (���ȣ)
		printf("< Error > => Missing bracket\n");
		cErrors++;
		break;


		//�١ڡ١�!!!!!!!!!!�Ұ�ȣ��?�١ڡ١�

	}
}