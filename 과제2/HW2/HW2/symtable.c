#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()
#include <string.h>
#define FILE_NAME "d:\\testdata4.txt"
#define STsize 1000 // string table ������
#define HTsize 100 // hash table ������
#define FALSE 0
#define TRUE 1

#define isLetter(x) ( x>='a' && x<='z'||x>='A'&& x<='Z'||x=='_')
#define isDigit(x) (x>='0'&&x<='9')

typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index; //ST�ȿ� �ִ� identifier�� �ε���
	HTpointer next; //���� identifier�� ����Ű�� ������

}HTentry;

enum errorTypes { noerror, illsp, illid, overst, toolong };
typedef enum errorTypes ERRORtypes;

char seperators[] = ".,;:?!\t\n ";

HTpointer HT[HTsize];
char ST[STsize];

int nextid = 0; //���� identifier
int nextfree = 0; //the next available index of ST
int hashcode; //identifier�� hashcode
int sameid; //identifier�� ù��° �ε���

int found; //for the previous ocurrence of a idntifier

ERRORtypes err;

FILE *fp; //���� ������
int input;

//Initialize - ���� ����, �� ���� �б�
void initialize() {
	fp = fopen(FILE_NAME, "r");
	input = fgetc(fp);
}

//isSeperator - ���������� ����
int isSeperator(char c) {
	int i;
	int sep_len;

	sep_len = strlen(seperators);

	for (i = 0; i < sep_len; i++) {
		if (c == seperators[i]) {
			return 1;
		}
	}

	return 0;
}


void PrintHeading()
{
	printf("\n\n");
	printf(" ----------------   ------------\n");
	printf(" Index in ST     identifier \n");
	printf(" ------------  ------------ \n");
	printf("\n");

}

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

/* PrintError - ���� �޼��� ���
* overst: ST �����÷ο�
* illsp: illegal seperator
* illid: illegal identifier
* toolong : 12�� �ʰ��� ��
*/
void PrintError(ERRORtypes err) {
	switch (err) {
	case overst:
		printf("...Error... OVERFLOW ");
		PrintHStable();
		exit(0);
		break;
	case illsp:
		printf("...Error...    ");

		//������ ���� �� illsp
		char tmp = input;

		//������ ST�� �����ص� char��� (illsp�� ���� identifier�� ����)
		for (int i = nextid; i < nextfree; i++)
			printf("%c", ST[i]);

		//illsp���
		printf("%c", tmp);

		//���� seperator�� ���� �� ���� char��� (illsp�� ���� identifier�� ����)
		input = fgetc(fp);

		while (input != EOF && (isLetter(input) || isDigit(input)) || !isSeperator(input)) {
			printf("%c", input);
			input = fgetc(fp);
		}

		printf("%15c is not allowed \n", tmp);
		break;
	case illid:
		printf("...Error...    ");
		for (int i = nextid; i < nextfree - 1; i++)
			printf("%c", ST[i]);
		while (input != EOF && (isLetter(input) || isDigit(input))) {
			printf("%c", input);
			input = fgetc(fp);
		}
		printf("		start with digit \n");
		break;
	case toolong:
		printf("...Error...   ");
		for (int i = nextid; i < nextfree - 1; i++)
			printf("%c", ST[i]);
		printf("    too long identifier \n");
		break;
	}
}

/* SkipSeperators
*  ���� identifier�� ���� ��, ���ڳ� ���ڰ� ������ �� ������ seperator skip
*  illsp�� ������ �� �������
*/
void SkipSeperators() {

	while (input != EOF && !(isLetter(input) || isDigit(input))) { //���ڵ� �ƴϰ� ���ڵ� �ƴϰ� ������ ���ڵ� �ƴ�
		if (!isSeperator(input)) { //�̶�, �ҹ� �����ڸ�
			err = illsp;  //�������
			nextid = nextfree;
			PrintError(err);
			err = noerror;

		}

		input = fgetc(fp);
	}

	if (input == EOF) {
		PrintHStable();

		/* string table ���
		printf("===ST===\n");
		for (int i = 0; i < nextfree; i++) {
		if (ST[i] == '\0') printf("\n");
		else printf("%c", ST[i]);
		}
		printf("\n\n\n");
		*/

		exit(1);
	}

}

/*ReadID
seperator�� �ƴ� ���ڵ��� �о ST�� �����Ѵ�.
�̶� ù���ڰ� �����̸� ���� ���
�����鼭 illsp�� ������ ���� ���
*/
int longcnt = 0;
void ReadID() {

	nextid = nextfree;
	if (isDigit(input)) { //ù���ڰ� ���ڸ�
		err = illid;
		PrintError(err);
	}
	else {
		// ST ����� (�� ���� �ֱ�)
		// �����̰ų� ������ ��
		while (input != EOF && (isLetter(input) || isDigit(input) || !isSeperator(input))) {
			if (nextfree == STsize) {
				err = overst;
				PrintError(err);

			}

			//�дٰ� �ҹ������� ������
			if (!isLetter(input) && !isDigit(input)) {
				err = illsp;
				PrintError(err);
				nextfree = nextid;
				longcnt = 0;
				break;
			}


			longcnt++;

			//�ƴϸ�
			ST[nextfree++] = input; //ST�� �־���.
			input = fgetc(fp);

		}
	}


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
���Ͽ��� identifier �ϳ��� �ѱ��ھ� �о� ST�� ����.
�ش� identifier�� hashcode���� ���.
HT[hashcode]�� identifier�� �̹� �ִ��� Ȯ��
�̹� ������, ���� ���� identifier�� ST���� ����
���� ������, HT[hashcode]�� index�� identifier�� ST������ ù �ε��� ���� ����
identifier�� ST���� �ε���, identifier, (entered) �Ǵ�  (already existed) ���
���� �� ���� �� hashtable�� ST�� ����ִ� ���� �� ���
*/
int main()
{
	int i;
	PrintHeading(); // header������
	initialize(); //���� �б�


				  //�� character�� �б�
	while (input != EOF) {
		err = noerror;
		SkipSeperators();
		ReadID(); //�ϳ��� identifier�� ���� ��


				  //������ ������ ���ڸ� �о��� ��
		if (input == EOF) {
			ST[nextfree++] = '\0'; //�� identifier�� ��

			if (!found) { //���� ���� identifier�� ht�� ���� �� ���� ��
				printf("%6d		", nextid);
				for (i = nextid; i < nextfree - 1; i++)
					printf("%c", ST[i]);
				printf("		(entered)\n");
				ADDHT(hashcode);
			}
			else { //
				printf("%6d		", sameid);
				for (i = nextid; i < nextfree - 1; i++)
					printf("%c", ST[i]);
				printf("		(already existed)\n");
				nextfree = nextid;
			}

		}


		// �� identifier �а� �� �� �������ĺ�
		if (input != EOF && err != illid && err != illsp) {

			//illsp�̸�
			if (!isSeperator(input)) {
				err = illsp;
				PrintError(err);
				nextfree = nextid;
			}

			if (nextfree == STsize) {
				err = overst;
				PrintError(err);
			}

			ST[nextfree++] = '\0'; //�� identifier ��

								   //12���� ������
			if (longcnt > 12) {
				err = toolong;
				PrintError(err);
				nextfree = nextid;
			}

			longcnt = 0;

			if (err == noerror) {
				ComputeHS(nextid, nextfree);
				LookupHS(nextid, hashcode);

				if (!found) { // ���� ���� identifier�� HT�� ���� �� ���� ��
					printf("%6d		", nextid);
					for (i = nextid; i < nextfree - 1; i++)
						printf("%c", ST[i]);
					printf("		(entered)\n");
					ADDHT(hashcode);
				}
				else { // �̹� ���� identifier�� ���� ��
					printf("%6d		", sameid);
					for (i = nextid; i < nextfree - 1; i++)
						printf("%c", ST[i]);
					printf("		(already existed)\n");
					nextfree = nextid; //�̹��� ST�� ���� identifier�� ������ ���
				}
			}
		}
	}
	PrintHStable();


	/* ST���
	printf("===ST===\n");
	for (int i = 0; i < nextfree; i++) {
	if (ST[i] == '\0') printf("\n");
	else printf("%c", ST[i]);
	}
	printf("\n\n\n");
	*/

}