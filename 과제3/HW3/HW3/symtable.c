/*
* symtable.c - identifier�� ST�� �ְ�, HT���� (HW2)
*
* Programmer - team2
*
* date - 4/27/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()
#include "tn.h"
extern int linenum;
extern int yyleng;
extern char *yytext;
extern reporterror(enum tnumber tn);


#define STsize 1000 // string table ������
#define HTsize 100 // hash table ������
#define FALSE 0
#define TRUE 1

typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index; //ST�ȿ� �ִ� identifier�� �ε���
	HTpointer next; //���� identifier�� ����Ű�� ������

}HTentry;


HTpointer HT[HTsize];
char ST[STsize];

int nextid = 0; //���� identifier
int nextfree = 0; //the next available index of ST
int hashcode; //identifier�� hashcode
int sameid; //identifier�� ù��° �ε���
int found; //for the previous ocurrence of a idntifier
int input;



/* PrintHStable - hash table ���*/
void PrintHStable()
{
	int i, j;
	HTpointer here;

	printf("\n\n\n\n\n [[  HASH TABLE  ]] \n\n");

	for (i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			printf("\n  Hash Code %3d : ", i);
		}
		for (here = HT[i]; here != NULL; here = here->next) {
			j = here->index;
			while (ST[j] != '\0' && j < STsize) {
				printf("%c", ST[j++]);
				//                printf("      ");

			}

			printf(" ");
			//            printf("\n");
		}
	}
	printf("\n\n\n < %5d characters are used in the string table > \n ", nextfree);

}


/*ComputeHS
* identifier�� hascode ��� : ��� characters�� �ƽ�Ű ���� ���� ��, HT������� ���� ������
*/
void ComputeHS(int nid, int nfree)
{
	int code, i;
	code = 0;
	for (i = nid; i < nfree - 1; i++) {
		code += (int)ST[i]; //�ƽ�Ű �ڵ� ��
		hashcode = code % HTsize; //mod
	}
}

/*
LookupHS
�� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
�̹� �ִٸ� found�� true�� �ʱ�ȭ / ���ٸ� false�� �ʱ�ȭ
*/
void LookupHS(int nid, int hscode)
{
	HTpointer here;
	int i, j;
	found = FALSE;

	//������� ������
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j]) found = FALSE;
				else {
					i++;
					j++;
				}
			}
			here = here->next;

		}
	}
}


/*
ADDHT
���ο� identifier�� hash table�� �ִ´�.
ht[hashcode]����Ʈ�� ����ִٸ�, �ش� identifier�� ST���� starting index�� ������ �־��ְ�
����Ʈ�� ������������� ����Ʈ �� �տ� �ش� identifier�� ST���� starting index�� ������ �־��ش�.
*/
void ADDHT(int hscode)
{
	HTpointer ptr;

	ptr = (HTpointer *)malloc(sizeof(ptr));
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}


/*
MAIN
*	identifier�� �νĵ� token�� �� ���ھ� ST�� ����. (yytext, yyleng�̿�)
*	�ش� identifier�� hashcode���� ���.
*	HT[hashcode]�� identifier�� �̹� �ִ��� Ȯ��
*	�̹� ������, ���� ���� identifier�� ST���� ����
*	���� ������, HT[hashcode]�� index�� identifier�� ST������ ù �ε��� ���� ����
*	identifier�� ���� line number, Token-type, ST-index(identifier�� ���), token ������ ���
*/
int SymmbolTable()
{

	nextid = nextfree;


	//ST overflow �߻� ��
	if (nextfree == STsize) {
		reporterror(TOVERFLOW);
	}

	// yytext �ѱ��ھ� ST�� ����
	for (int i = 0; i < yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	// identifier�� �� ���� ��
	ST[nextfree++]= '\0';

	// HS���, �� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);
	

	if (!found) { // ���� ���� identifier�� ST�� ���� �� ���� ��
		// line number, Token-type, ST-index(identifier�� ���), token ������ ���
		printf("%-20d %-35s %-20d %-30s\n", linenum, "Identifier", nextid, yytext);
		ADDHT(hashcode); // HT ����
	}
	else { // �̹� ���� identifier�� ���� ��

		// line number, Token-type, ST-index(identifier�� ���), token ������ ���
		printf("%-20d %-35s %-20d %-30s\n", linenum, "Identifier", sameid, yytext);
		nextfree = nextid; //�̹��� ST�� ���� identifier�� ������ ���
	}


	/*ST���
	printf("===ST===\n");
	for (int i = 0; i < nextfree; i++) {
	if (ST[i] == '\0') printf("\n");
	else printf("%c", ST[i]);
	}
	printf("\n\n\n");
	*/

	}


