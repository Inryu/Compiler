/*
* symtable.c - identifier�� ST�� �ְ�, HT���� (HW3)
*
* Programmer - team2
*
* date - 4/27/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()
#include "glob.h"
#include "tn.h"



/* PrintHStable - hash table ���*/
void PrintHStable()
{
	HTptr here;
	int i, j;

	printf("\n\t [[  HASH TABLE  ]] \n\n");
	printf("==================================================\n");

	for (i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			here = HT[i];
			do {
				printf("\tHash Code%4d : (", i);
				for (j = here->index; ST[j] != "\0"; j++) printf("%c", ST[j]);
				printf(" : ");
				switch (here->type) {
				case 1: printf("integer scalar variable)\n"); break;
				case 2: printf("void scalar variable)\n"); break;
				case 3: printf("array integer variable)\n"); break;
				case 4: printf("function)\n"); break;
				case 5: printf("not defined identifier/function)\n"); break;
				default: printf("identifier about parse error)\n"); break;
				}
				here = here->next;
			} while (here != NULL);
		}

	}
	printf("==================================================\n");
	//printf("\t < %5d characters are used in the string table > \n ", nextfree);

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
	HTptr here;
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
	HTptr ptr;

	ptr = (HTptr *)malloc(sizeof(ptr));
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}


/*
MAIN
*   identifier�� �νĵ� token�� �� ���ھ� ST�� ����. (yytext, yyleng�̿�)
*   �ش� identifier�� hashcode���� ���.
*   HT[hashcode]�� identifier�� �̹� �ִ��� Ȯ��
*   �̹� ������, ���� ���� identifier�� ST���� ����
*   ���� ������, HT[hashcode]�� index�� identifier�� ST������ ù �ε��� ���� ����
*   identifier�� ���� line number, Token-type, ST-index(identifier�� ���), token ������ ���
*/
int SymmbolTable()
{

	nextid = nextfree;


	//ST overflow �߻� ��
	if (nextfree == STsize) {
		reporterror(toverflow);
	}

	// yytext �ѱ��ھ� ST�� ����
	for (int i = 0; i < yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	// identifier�� �� ���� ��
	ST[nextfree++] = '\0';

	// HS���, �� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);


	if (!found) { // ���� ���� identifier�� ST�� ���� �� ���� ��
				  // line number, Token-type, ST-index(identifier�� ���), token ������ ���
		printf("%-20d %-35s %-20d %-30s\n", cLine, "Identifier", nextid, yytext);
		ADDHT(hashcode); // HT ����
	}
	else { // �̹� ���� identifier�� ���� ��

		   // line number, Token-type, ST-index(identifier�� ���), token ������ ���
		printf("%-20d %-35s %-20d %-30s\n", cLine, "Identifier", sameid, yytext);
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