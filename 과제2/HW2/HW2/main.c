/*
* main.c - lexical analyzer for Scanner : main (HW2)
*
* Programmer - team2
*
* date - 4/27/2021
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern char *yytext;
extern int linenum;
extern int cErrors;
extern int yyleng;


/* printtoken
* token type���� line number, Token-type, ST-index(identifier�� ���), token ������ ���
*/
void printtoken(enum tnumber tn) {

	switch (tn) {

	//�ּ���

	//1. �� �� �ּ�
	case TONECMT:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "One line comment", " ", yytext);
		break;
	//2. ������ �ּ�
	case TMULCMT:
		printf("%-20d %-35s %-20s", linenum, "Multiple line comment", " ");
		for (int i = 0; i < yyleng; i++) {
			printf("%c", yytext[i]);
			if (yytext[i] == '\n')
			{
				printf("%-77s","");
				linenum++;
			}
		}
		printf("\n");
		break;

	//���
	//1. ����(10����)
	case TDECIMAL:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Decimal number", " ", yytext);
		break;
	//2. �Ǽ�
	case TFIXED:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Fixed number", " ", yytext);
		break;

	// Keyword �����
	case TCONST:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TELSE:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TIF:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TINT: printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TRETURN:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TVOID:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	case TWHILE: printf("%-20d %-35s %-20s %-30s\n", linenum, "Keyword", " ", yytext);
		break;

	//Operator
	//1. ��Ģ������
	case TPLUS:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Plus", " ", yytext);
		break;

	case TMINUS:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Minus", " ", yytext);
		break;

	case TSTAR:  printf("%-20d %-35s %-20s %-30s\n", linenum, "Multiplication", " ", yytext);
		break;

	case TSLASH:printf("%-20d %-35s %-20s %-30s\n", linenum, "Division", " ", yytext);
		break;

	case TMOD: printf("%-20d %-35s %-20s %-30s\n", linenum, "Modulo", " ", yytext);
		break;

	//2. ���� ������
	case TASSIGN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Assign", " ", yytext);
		break;
	case TADDASSIGN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Add assign", " ", yytext);
		break;
	case TSUBASSIGN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Sub assign", " ", yytext);
		break;
	case TMULASSIGN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Mul assign", " ", yytext);
		break;
	case TDIVASSIGN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Div assign", " ", yytext);
		break;
	case TMODASSGIN:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Mod than", " ", yytext);
		break;

	//3. ��������
	case TNOT:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Not", " ", yytext);
		break;
	case TAND:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "And", " ", yytext);
		break;
	case TOR:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Or", " ", yytext);
		break;
	
	//4. ���迬����
	case TEQUAL:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Equal", " ", yytext);
		break;
	case TNOTEQU:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Not equal", " ", yytext);
		break;
	case TLESS:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Less", " ", yytext);
		break;
	case TOVER:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Over", " ", yytext);
		break;
	case TLESSE:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Less or Equal", " ", yytext);
		break;
	case TOVERE:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Over or Equal", " ", yytext);
		break;


	//5. ����������
	case TINC:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Increase one", " ", yytext);
		break;
	case TDEC:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Decrease one", " ", yytext);
		break;

	//Special Symbols
	case TOSBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Open small bracket", " ", yytext);
			break;
	case TCSBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Close small bracket", " ", yytext);
			break;
	case TCOMMA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Comma", " ", yytext);
			break;
	case TOMBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Open middle bracket", " ", yytext);
			break;
	case TCMBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Close middle bracket", " ", yytext);
			break;
	case TOLBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Open large bracket", " ", yytext);
			break;
	case TCLBRA:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Close large bracket", " ", yytext);
			break;
	case TSEMI:
		printf("%-20d %-35s %-20s %-30s\n", linenum, "Semicolon", " ", yytext);
		break;
	}
}

/* main
* ��� ��� �� printtoken�� ȣ���Ͽ� ������ ��ū�� ����� ������ (identifier�� error�� �ִ� ��� ����) , ���� ���� ���
*/
void main()
{
	enum tnumber tn;  // token type

	//print header
	printf("=========================================================================================================\n");
	printf("%-20s %-35s %-20s %-30s\n", "Line number", "Token type", "ST-index", "Token");
	printf("=========================================================================================================\n");


	//print token
	while ((tn = yylex()) != TEOF) {
		printtoken(tn);
	}

	//print number of error
	if (cErrors == 0) {
		printf("=========================================================================================================\n");
		printf("No errors detected\n");
		printf("=========================================================================================================\n");

	}
	else {
		printf("=========================================================================================================\n");
		printf("%d errors detected\n", cErrors);
		printf("=========================================================================================================\n");

	}


}

