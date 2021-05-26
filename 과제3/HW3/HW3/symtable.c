/*
* symtable.c - identifier�� ST�� �ְ�, HT���� (HW3)
*
* Programmer - team2
*
* date - 5/26/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "glob.h"
#include "tn.h"



/* PrintHStable -
* hash table�� ���Ŀ� ���߾� ���
*/
void PrintHStable()
{
	HTptr here;
	int i, j;

	printf("\n\t\t\t\t***HASH TABLE***\n");
	printf("==================================================================================\n");

	for (i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			here = HT[i];
			do {
				printf("\tHash Code%4d : (", i);
				for (j = here->index; ST[j] != '\0'; j++) printf("%c", ST[j]);
				printf(" : ");

				switch (here->type) {
					//int variable
				case 1: printf("integer scalar variable, line%d)\n", here->cLine); break;
					//void variable
				case 2: printf("void scalar variable, line%d)\n", here->cLine); break;
					//array(int) variable
				case 3: printf("array integer variable, line%d)\n", here->cLine); break;
					//void function
				case 4: printf("function, return type=void, line%d)\n", here->cLine); break;
					//not define
				case 5: printf("not defined identifier/function, line%d)\n", here->cLine); break;
					//float variable
				case 6: printf("float scalar variable, line%d)\n", here->cLine); break;
					//array(float) variable
				case 7: printf("array float variable, line%d)\n", here->cLine); break;
					//int function
				case 8: printf("function, return type=int, line%d)\n", here->cLine); break;
					//float function
				case 9:printf("function, return type=float, line%d)\n", here->cLine); break;
					//int scalar parameter
				case 10: printf("integer scalar parameter, line%d)\n", here->cLine); break;
					//float scalar parameter
				case 11: printf("float scalar parameter, line%d)\n", here->cLine); break;
				default: printf("identifier about parse error, line%d)\n", here->cLine); break;
				}
				here = here->next;
			} while (here != NULL);
		}



	}
	printf("==================================================================================\n");


}


/*ComputeHS
* identifier�� hascode ��� : ��� characters�� �ƽ�Ű ���� ���� ��, HT������� ���� ������
*/
void ComputeHS(int nid, int nfree)
{
	int i, func = 0;
	for (i = nid; i < nfree - 1; i++) {
		func += (int)ST[nid++];
	}
	hashcode = func%HTsize;
}

/*
* LookupHS
* �� identifer�� ����, hastable�� �̹� �ִ��� Ȯ��
* �̹� �ִٸ� found�� true�� �ʱ�ȭ / ���ٸ� false�� �ʱ�ȭ
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
* ADDHT
* ���ο� identifier�� hash table�� �ִ´�.
* index�� next�� �������ְ�, type�� 0���� �ʱ�ȭ�ϸ�, ���° �ٿ� �����ϴ����� cLine�� �����Ѵ�.
* ht[hashcode]����Ʈ�� ����ִٸ�, next�� NULL�� ä���,
* ����Ʈ�� ������������� next�� HT���̺��� �̿��Ͽ� ä���.
*/
void ADDHT(int hscode)
{
	HTptr tmp;

	if (HT[hscode] == NULL) {
		tmp = (HTptr)malloc(sizeof(struct HTentry));
		tmp->type = 0;
		tmp->next = NULL;
		tmp->cLine = cLine;
		HT[hscode] = tmp;
		tmp->index = nextid;
	}
	else {
		tmp = (HTptr)malloc(sizeof(struct HTentry));
		tmp->type = 0;
		tmp->index = nextid;
		tmp->next = HT[hscode];
		tmp->cLine = cLine;
		HT[hscode] = tmp;
	}
	look_id = tmp;

}


/*
MAIN
*   identifier�� �νĵ� token�� �� ���ھ� ST�� ����. (yytext, yyleng�̿�)
*   �ش� identifier�� hashcode���� ���.
*   HT[hashcode]�� identifier�� �̹� �ִ��� Ȯ��
*   �̹� ������, ���� ���� identifier�� ST���� ����
*   ���� ������, HT[hashcode]�� index�� identifier�� ST������ ù �ε��� ���� ����
*   identifier�� ���� line number, Token-type(Identifier), token ������ ���
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
				  // line number, Token-type(Identifier), token ������ ���
		printf("[%-2d] %-35s %-30s\n", cLine, "Identifier", yytext);
		ADDHT(hashcode); // HT ����
	}
	else { // �̹� ���� identifier�� ���� ��
		   // line number, Token-type(Identifier), �̹� �����ϴ� id, token ������ ���
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