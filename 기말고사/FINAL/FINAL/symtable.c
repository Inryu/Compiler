/*
* symtable.c - identifier를 ST에 넣고, HT구함 (HW3)
*
* Programmer - team2
*
* 1871040이유정 / 1871026 신인류 / 1876136 박가현
*
* date -  6/05/2021
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "glob.h"
#include "tn.h"



/* PrintHStable -
* hash table을 형식에 맞추어 출력
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
				case 1: printf("integer scalar variable, line%d, %s)\n", here->cLine, here->scope); break;
					//void variable
				case 2: printf("void scalar variable, line%d, %s)\n", here->cLine, here->scope); break;
					//array(int) variable
				case 3: printf("array integer variable, line%d, %s)\n", here->cLine, here->scope); break;
					//void function
				case 4: printf("function, return type=void, line%d)\n", here->cLine); break;
					//not define
				case 5: printf("not defined identifier/function, line%d)\n", here->cLine); break;
					//float variable
				case 6: printf("float scalar variable, line%d, %s)\n", here->cLine, here->scope); break;
					//array(float) variable
				case 7: printf("array float variable, line%d, %s)\n", here->cLine, here->scope); break;
					//int function
				case 8: printf("function, return type=int, line%d)\n", here->cLine); break;
					//float function
				case 9:printf("function, return type=float, line%d)\n", here->cLine); break;
					//int scalar parameter
				case 10: printf("integer scalar parameter, line%d, %s)\n", here->cLine, here->scope); break;
					//float scalar parameter
				case 11: printf("float scalar parameter,line%d, %s)\n", here->cLine, here->scope); break;

					//char scalar variable
				case 12: printf("char scalar variable, line%d, %s)\n", here->cLine, here->scope); break;
					//string scalar variable
				case 13: printf("string scalar variable, line%d, %s)\n", here->cLine, here->scope); break;

				case 14: printf("function, return type=char, line%d)\n", here->cLine); break;
					//void function
				case 15: printf("function, return type=string, line%d)\n", here->cLine); break;
					//int scalar parameter
				case 16: printf("char scalar parameter, line%d, %s)\n", here->cLine, here->scope); break;
					//float scalar parameter
				case 17: printf("string scalar parameter, line%d, %s)\n", here->cLine, here->scope); break;

				default: printf("identifier about parse error, line%d)\n", here->cLine); break;
				}
				here = here->next;
			} while (here != NULL);
		}

	}
	printf("==================================================================================\n");


}


/*ComputeHS
* identifier의 hascode 계산 : 모든 characters의 아스키 값을 더한 후, HT사이즈로 나눈 나머지
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
* 각 identifer에 대해, hastable에 이미 있는지 확인
* 이미 있다면 found를 true로 초기화 / 없다면 false로 초기화
*/
void LookupHS(int nid, int hscode)
{
	HTptr here;
	int i, j;
	found = FALSE;

	//비어있지 않으면
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
* 새로운 identifier를 hash table에 넣는다.
* index와 next를 지정해주고, type은 0으로 초기화하며, 몇번째 줄에 존재하는지를 cLine에 저장한다.
* ht[hashcode]리스트가 비어있다면, next는 NULL로 채우고,
* 리스트가 비어있지않으면 next는 HT테이블을 이용하여 채운다.
*/
void ADDHT(int hscode)
{

	HTptr tmp;

	if (HT[hscode] == NULL) {
		tmp = (HTptr)malloc(sizeof(struct HTentry));
		tmp->type = 0;
		tmp->next = NULL;
		tmp->cLine = cLine;
		strcpy(tmp->scope, preyytext);
		//tmp->scope = preyytext;
		HT[hscode] = tmp;
		tmp->index = nextid;
	}
	else {
		tmp = (HTptr)malloc(sizeof(struct HTentry));
		tmp->type = 0;
		tmp->index = nextid;
		tmp->next = HT[hscode];
		tmp->cLine = cLine;
		strcpy(tmp->scope, preyytext);
		//tmp->scope = preyytext;
		HT[hscode] = tmp;
	}
	look_id = tmp;

}


/*
SymbolTable
*   identifier로 인식된 token을 한 글자씩 ST에 넣음. (yytext, yyleng이용)
*   해당 identifier의 hashcode값을 계산.
*   HT[hashcode]에 identifier가 이미 있는지 확인
*   이미 있으면, 현재 읽은 identifier를 ST에서 삭제
*   아직 없으면, HT[hashcode]의 index에 identifier의 ST에서의 첫 인덱스 값을 넣음
*   identifier에 대해 line number, Token-type(Identifier), token 순으로 출력
*/
int SymbolTable()
{

	nextid = nextfree;


	//ST overflow 발생 시
	if (nextfree == STsize) {
		reporterror(toverflow);
		PrintHStable();
		exit(1);
	}

	// yytext 한글자씩 ST에 넣음
	for (int i = 0; i < yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	// identifier를 다 넣은 후
	ST[nextfree++] = '\0';

	// HS계산, 각 identifer에 대해, hastable에 이미 있는지 확인
	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);


	if (!found) { // 아직 같은 identifier를 ST에 넣은 적 없을 때
		ADDHT(hashcode); // HT 삽입
	}
	else { // 이미 같은 identifier가 있을 때
		nextfree = nextid; //이번에 ST에 읽은 identifier를 다음에 덮어씀
	}


	/*ST출력
	printf("===ST===\n");
	for (int i = 0; i < nextfree; i++) {
	if (ST[i] == '\0') printf("\n");
	else printf("%c", ST[i]);
	}
	printf("\n\n\n");
	*/

}
