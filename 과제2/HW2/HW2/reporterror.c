/*
* reporterror.c - ���� ��� (HW2)
*
* Programmer - team2
*
* date - 4/27/2021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
extern int linenum;
extern char *yytext;
extern int cErrors; //���� ����

/* reporterror
* token type���� ������ ������ �ش� ������ ���
 1)TILLIDENT : �߸��� identifier
 2)TILLSYM : �ùٸ��� ���� symbol
 3)TLONG : 13�� �̻��� identifier
 4)TOVERFLOW : ST overflow
*/
void reporterror(enum tnumber tn) {
	switch (tn) {
	case TILLIDENT:
		printf("%-20d %-35s %-20s %s is Illegal IDENT\n", linenum, "***Error***", " ",yytext);
		cErrors++;
		break;

	case TILLSYM:
		printf("%-20d %-35s %-20s %-1s %-30s\n", linenum, "***Error***", " ", yytext, " is Illegal Symbol");
		cErrors++;
		break;

	case TLONG:
		printf("%-20d %-35s %-20s %-30s %-30s\n", linenum, "***Error***", " ", yytext ,"Too Long IDENT");
		cErrors++;
		break;

	case TOVERFLOW:
		printf("***Error***   OVERFLOW     ");
		exit(0);
		break;
	}
}