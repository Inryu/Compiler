#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()
#include <string.h>
#define FILE_NAME "d:\\testdata4.txt"
#define STsize 1000 // string table 사이즈
#define HTsize 100 // hash table 사이즈
#define FALSE 0
#define TRUE 1

#define isLetter(x) ( x>='a' && x<='z'||x>='A'&& x<='Z'||x=='_')
#define isDigit(x) (x>='0'&&x<='9')

typedef struct HTentry *HTpointer;
typedef struct HTentry {
    int index; //ST안에 있는 identifier의 인덱스
    HTpointer next; //다음 identifier를 가리키는 포인터

}HTentry;

enum errorTypes { noerror, illsp, illid, overst, toolong };
typedef enum errorTypes ERRORtypes;

char seperators[] = ".,;:?!\t\n ";

HTpointer HT[HTsize];
char ST[STsize];

int nextid = 0; //현재 identifier
int nextfree = 0; //the next available index of ST
int hashcode; //identifier의 hashcode
int sameid; //identifier의 첫번째 인덱스

int found; //for the previous ocurrence of a idntifier

ERRORtypes err;

FILE *fp; //파일 포인터
int input;

//Initialize - 파일 열기, 한 글자 읽기
void initialize() {
    fp = fopen(FILE_NAME, "r");
    input = fgetc(fp);
}

//isSeperator - 구분자인지 구별
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

/* PrintHStable - hash table 출력*/
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

/* PrintError - 에러 메세지 출력
* overst: ST 오버플로우
* illsp: illegal seperator
* illid: illegal identifier
* toolong : 12자 초과일 때
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

            //오류를 나게 한 illsp
            char tmp = input;

            //이전에 ST에 저장해둔 char출력 (illsp와 같은 identifier에 속함)
            for (int i = nextid; i < nextfree; i++)
                printf("%c", ST[i]);

            //illsp출력
            printf("%c", tmp);

            //이후 seperator가 나올 때 까지 char출력 (illsp와 같은 identifier에 속함)
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
*  다음 identifier를 읽을 때, 문자나 숫자가 나오기 전 나오는 seperator skip
*  illsp가 나왔을 시 오류출력
*/
void SkipSeperators() {

    while (input != EOF && !(isLetter(input) || isDigit(input))) { //문자도 아니고 숫자도 아니고 마지막 글자도 아님
        if (!isSeperator(input)) { //이때, 불법 구분자면
            err = illsp;  //에러출력
            nextid = nextfree;
            PrintError(err);
            err = noerror;

        }

        input = fgetc(fp);
    }

    if (input == EOF) {
        PrintHStable();

        /* string table 출력
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
seperator가 아닌 문자들을 읽어서 ST에 저장한다.
이때 첫글자가 숫자이면 오류 출력
읽으면서 illsp가 나오면 오류 출력
*/
int longcnt = 0;
void ReadID() {

    nextid = nextfree;
    if (isDigit(input)) { //첫글자고 숫자면
        err = illid;
        PrintError(err);
    }
    else {
        // ST 만들기 (한 문자 넣기)
        // 문자이거나 숫자일 때
        while (input != EOF && (isLetter(input) || isDigit(input) || !isSeperator(input))) {
            if (nextfree == STsize) {
                err = overst;
                PrintError(err);

            }

            //읽다가 불법구분자 나오면
            if (!isLetter(input) && !isDigit(input)) {
                err = illsp;
                PrintError(err);
                nextfree = nextid;
                longcnt = 0;
                break;
            }


            longcnt++;

            //아니면
            ST[nextfree++] = input; //ST에 넣어줌.
            input = fgetc(fp);

        }
    }


}

/*ComputeHS
* identifier의 hascode 계산 : 모든 characters의 아스키 값을 더한 후, HT사이즈로 나눈 나머지
*/
void ComputeHS(int nid, int nfree)
{
    int code, i;
    code = 0;
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i]; //아스키 코드 합
        hashcode = code % HTsize; //mod
    }
}

/*
LookupHS
각 identifer에 대해, hastable에 이미 있는지 확인
이미 있다면 found를 true로 초기화 / 없다면 false로 초기화
*/
void LookupHS(int nid, int hscode)
{
    HTpointer here;
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
ADDHT
새로운 identifier를 hash table에 넣는다.
ht[hashcode]리스트가 비어있다면, 해당 identifier의 ST에서 starting index를 값으로 넣어주고
리스트가 비어있지않으면 리스트 맨 앞에 해당 identifier의 ST에서 starting index를 값으로 넣어준다.
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
	파일에서 identifier 하나를 한글자씩 읽어 ST에 넣음.
	해당 identifier의 hashcode값을 계산.
	HT[hashcode]에 identifier가 이미 있는지 확인
		이미 있으면, 현재 읽은 identifier를 ST에서 삭제
		아직 없으면, HT[hashcode]의 index에 identifier의 ST에서의 첫 인덱스 값을 넣음
	identifier의 ST에서 인덱스, identifier, (entered) 또는  (already existed) 출력
	파일 다 읽은 후 hashtable과 ST에 들어있는 문자 수 출력
*/
int main()
{
    int i;
    PrintHeading(); // header프린팅
    initialize(); //파일 읽기


    //한 character씩 읽기
    while (input != EOF) {
        err = noerror;
        SkipSeperators();
        ReadID(); //하나의 identifier를 읽은 후


        //파일의 마지막 글자를 읽었을 때
        if (input == EOF) {
            ST[nextfree++] = '\0'; //한 identifier의 끝

            if (!found) { //아직 같은 identifier를 ht에 넣은 적 없을 때
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


        // 한 identifier 읽고 난 후 구분자후보
        if (input != EOF && err != illid && err != illsp) {

            //illsp이면
            if (!isSeperator(input)) {
                err = illsp;
                PrintError(err);
                nextfree = nextid;
            }

            if (nextfree == STsize) {
                err = overst;
                PrintError(err);
            }

            ST[nextfree++] = '\0'; //한 identifier 끝

            //12글자 넘으면
            if (longcnt > 12) {
                err = toolong;
                PrintError(err);
                nextfree = nextid;
            }

            longcnt = 0;

            if (err == noerror) {
                ComputeHS(nextid, nextfree);
                LookupHS(nextid, hashcode);

                if (!found) { // 아직 같은 identifier를 HT에 넣은 적 없을 때
                    printf("%6d		", nextid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(entered)\n");
                    ADDHT(hashcode);
                }
                else { // 이미 같은 identifier가 있을 때
                    printf("%6d		", sameid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(already existed)\n");
                    nextfree = nextid; //이번에 ST에 읽은 identifier를 다음에 덮어씀
                }
            }
        }
    }
    PrintHStable();


    /* ST출력
    printf("===ST===\n");
    for (int i = 0; i < nextfree; i++) {

        if (ST[i] == '\0') printf("\n");
        else printf("%c", ST[i]);
    }
    printf("\n\n\n");
    */

}