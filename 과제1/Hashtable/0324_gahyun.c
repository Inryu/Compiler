
//불법 특수문자로 시작하는 단어 아예 무시당함.. &the 이러면 그 단어는 에러처리조차안

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()?
#include <string.h>

#define FILE_NAME "../pretestdata1.txt"
#define STsize 1000 //size of string table
#define HTsize 100 // size of hash table

#define FALSE 0
#define TRUE 1

#define isLetter(x) ( (x>='a' && x<='z')||(x>='A'&& x<='Z')|| (x=='_'))
#define isDigit(x) (x>='0' && x<='9')



enum errorTypes {
    noerror, illsp, illid, overst,toolong
};
typedef enum errorTypes ERRORtypes;

char seperators[] = ".,;:?!\t\n ";

typedef struct HTentry *HTpointer; //HTentry구조체를 가리키는 포인터
typedef struct HTentry {
    int index; //index of identifier in ST
    HTpointer next; //pointer to next identifier
} HTentry;

/*
 * 자구에서 배울때는
 *
 * typedef struct HTentry{
 *      int index;
 *      HTentry * next; //자기자신 구조체를 가리키는 포인터
 * }
 * 로 배웠는데 여기서는 HTentry *을 HTpointer라는 걸로 typedef를 해버려서 위처럼 만든거임 */

//해시테이블과 심볼테이블
HTpointer HT[HTsize];
char ST[STsize];


int nextid = 0; //the current identifier
int nextfree = 0; //the next available index of ST
int hashcode; //hash code of identifier
int sameid; //fisrt index of identifier

int found; //for the previous ocurrence of a idntifier

ERRORtypes err;

FILE *fp; //to be a pointer to FILE
char input; //전역변수로

//Initialize함 - 입력받은 txt파일을 "one letter"씩 읽음
void initialize() {
    fp = fopen(FILE_NAME, "r");
    input = fgetc(fp);
}

//isSeperator - distinguish the seperator가
//한글자로 입력된 letter가 구분자인지 확인
int isSeperator(char c) {
    int i;
    int sep_len;

    //구분자를 저장한 char배열의 길이
    sep_len = strlen(seperators);
    //해당 길이 만큼 반복하여, 배열 내에 존재하는 경우
    for (i = 0; i < sep_len; i++) {
        if (c == seperators[i]){
            //printf("%c = %c same\n",c,seperators[i]);
            return 1;
        } // 구분자임
    }

    return 0; // 존재하지 않는 경우 구분자가 아님
}


void PrintHeading() {
    printf("\n\n");
    printf(" ------------  ------------\n");
    printf(" Index in ST    identifier \n");
    printf(" ------------  ------------ \n");
    printf("\n");

}

/* PrintHStable - Prints the hash table write out the hashcode and the list of identifiers
associated with each hashcode, but only for non-empty lists.
Print out the number of characters used up in ST. */

void PrintHStable() {
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
                //printf("      ");
            }
            printf(" ");
            //printf("\n");
        }

    }
    printf("\n\n\n < %5d characters are used in the string table > \n ", nextfree);
}

/* PrintError -Print out error messages
* overst: overflow in ST
* print the hashtable and abort by calling the function "abort()"
* illid: illegal identifier
* illsp: illegal seperator
 */

void PrintError(ERRORtypes err) {
    switch (err) {
        case overst: //오버플로우가 발생하면, 오류문구를 출력하고 지금까지의 해시테이블 출력 후 아예종료
            printf("...Error... OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
        case illsp: //허락되지 않은 구분자 사용
            printf("...Error...   %c is illegal seperator \n", input);
            break;
        case illid:
            printf("...Error...    ");
            //숫자고 문자인데도 오류인 경우 -> 여기지우면 오류
            while (input != EOF && (isLetter(input) || isDigit(input) || !(isSeperator(input)))) {
                printf("%c", input);
                input = fgetc(fp);
            }
            printf(" start with digit \n");
            break;
        case toolong:
            printf("...Error...    Too long identifier\n ");;

    }
}

/* Skip Seperators -
*       skip over strings of spaces, tabs, newlines, .,; : ? !
*       if illegal seperators, print out error message
 * */



void SkipSeperators() {
    // \ !(a||b) 는 !a && !b : 즉, a,b모두 아니어야함
    while (input != EOF && !(isLetter(input) || isDigit(input))) { //문자도 아니고 숫자도 아니고 마지막 글자도 아님

//        if (!isSeperator(input)) { //구분자도 아니면
//            err = illsp; //문자 X 숫자 X 구분자 X -> errType : 올바르지 못한 구분자
//            PrintError(err); //에러로 출력
//            input=fgetc(fp);
//        }
        if(isSeperator((input))) {
            input = fgetc(fp); //다음 글자를 읽어서 반복
        }else{
            err=illsp;
            PrintError(err);
            break;
        };
    }
    if(input==EOF){
        exit(1);
    }
    //문자 or 숫자이면, while loop 탈출
}

/* ReadIO-
* Read identifiers from the input file the string table ST  directly into ST(append it to the previous identifier).
* An identifier is a string of letter ans digits, starting with a letter.
* If first letter is digit, print out error message.
* */




//txt에 적힌 하나의 word를 ST로 옮기는 함수
void ReadID() {
    //printf("ReadID input: %c",input);

    //nextid : 문자가 시작하는 인덱스
    //nextfree : letter를 넣을 ST의 index 넣으면 ++되기 때문에 다넣으면 word바로 다음 빈칸을 가리킨다
    nextid = nextfree;
    //이 함수에 들어오는 input은
    // 1. 문자의 첫글자
    // 2. 숫자/문자
    // 두 조건을 만족 -> 문자/숫자가 아닌 것은 word의 첫자로 인정하지 않고 skip하므로
    //즉, 숫자로 시작하는 문자는 ST에도 들어가지않음...
    if (isDigit(input)) { //숫자인 경우 -> "숫자로 시작하는 문자"는 에러
        err = illid; // 에러 타입 지정
        PrintError(err);
    } else { // 문자인 경우 ( 즉, 단어의 첫글자이면서 문자로 시작하는 경우)
        //위의 if - else 문으로 word의 첫 글자가 "문자"라는 조건까지 만족
        //while문 (첫글자가 아니면 숫자도 가능하기때문에 word를 완성시키기 위해 구분자(불법 구분포함) 등장 이전까지 while)
        while (input != EOF && !isSeperator(input)) {

            //ST 테이블의 nextfree index에 글자를 삽입 ->  STsize를 초과해서 넣을 수는 없음
            if (nextfree == STsize) { //STsize를 초과해서 넣을 수는 없음
                err = overst; // 오버플로우 에러
                PrintError(err);
                //여기에 break필요없나?!->아 overflow면 PrintError에서 exit됨
            }
            //오버 플로우만 아니면, ST에 입력받은 input을 넣어줌
            ST[nextfree++] = input; //ST에 넣어줌.
            input = fgetc(fp);  //다음 letter를 읽어서 구분자(불법구분자 포함)이 나올때 까지 반복
            if (!(isDigit(input) || isLetter(input) || isSeperator(input)||input==EOF)) { //구분자도 아니면
                err = illsp;
                PrintError(err);
            }
        }
        if((nextfree-nextid)>12){
            err=toolong;
            PrintError(err);
        }
    }

}

/*ComputeHS - Compute the hash code of identifier by summing the ordinal values of its
characters and then taking the sum modulo the size of HT */
void ComputeHS(int nid, int nfree) { //nid : word의 첫 시작 index , nfree : word의 마지막 letter + 1 index(공백저장됨)
    int code, i;
    code = 0; //word 아스키코드의 합을 저장할 변수
    for (i = nid; i < nfree - 1; i++) {
        code += (int) ST[i]; //아스키 코드 합
        hashcode = code % HTsize; // 아스키코드합 mod 해시테이블사이즈 -> hashcode
    }
}

/*
LookupHS
For each indentifier, Look it up in the hashtable for previous occurrence of the identifier.
If find a match, set the found flag as true.
Other wise false.
If find a match, save the starting index of ST in same id
*/
void LookupHS(int nid, int hscode) {
    HTpointer here; //HTentry를 가리키는 포인터 선언
    int i, j;
    found = FALSE; //이미 HT에 들어간 문자열인 경우 TRUE 아니면 FALSE


    //새로운 word가 hashtable에 저장되고자 하는 index(위치)가 비어있지 않으면,
    if (HT[hscode] != NULL) {
        here = HT[hscode]; // HT[hscode] 인덱스위치에 존재하는 HTpointer로 만듬


        //일단 HT내에서 같은 인덱스를 가진다는건 같은 hscode 를 가지기 때문에 이미 들어간 단어가 존재할 수도
        while (here != NULL && found == FALSE) {
            found = TRUE; //이미 존재하는 단어라고 가정해버림
            i = here->index; //HT[hscode] 에서 index 부분에 적힌 정수 ( 해당 HT index상에 존재하는 word의 첫 글자)
            j = nid;//word의 시작부분의 index(지금들어갈 단어의 첫 인덱스 )
            sameid = i;

            //HT의 해당 hscode에 index상에 저장된 단어가 이미있는 단어인지 검사해보려고 돌림
            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {//이번에 들어온 단어가 이미 있는 단어라고 가정하고 한글자씩 같은지 비
                if (ST[i] != ST[j])
                    found = FALSE; //한자한자 검사하면서 다른단어가 나오면 FALSE로 만들기 -> false가 되면 while이 끝남                else {
                else {
                    i++;
                    j++;
                }
            }
            here = here->next; //연결리스트를 이용해 다음 연결리스트에 저장된 word와 겹치는지 검사하기위해 다음으로 넘김

        }
    }
}


/*
ADDHT
Add a new identifier to the hash table.
If list head ht[hashcode] is null, simply add a list element with
starting index of the identifier in ST.
IF list head is not a null, it adds a new idetifier to the head of the chain
*/
void ADDHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer) malloc(sizeof(ptr));
    ptr->index = nextid;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
}

/*

MAIN
    Read the identifier from the file directly into ST.
    Compute its hashcode.
    Look up the identifier in hashtable HT[hashcode]
    If matched, delete the identifier from ST and print ST-index
    of the matching identifier.
    If not matched, add a new element to the list, pointing to new identifier.
    Print the identifier, its index in ST, and whether it was entered or present.
    Print out the hashtable, and number of characters used up in ST

*/



int main() {
    int i;
    PrintHeading(); // header프린팅
    initialize(); //읽어들일 txt파일에서 "one letter"를 "input"변수에 넣음


    //input 변수에 들어간 글자가 마지막 글자가 아닌 동안 지속
    //즉, 파일을 끝까지 읽는동안 지속
    while (input != EOF) {

        err = noerror;//디폴트로 "noerror:에러가 아님"
        //word의 처음이 숫자/문자일 때 까지 반복함
        SkipSeperators(); //word의 처음이 구분자 -> skip , 잘못된 구분자 -> err출력

        //ReadID에 인자로 들어갈 수 있는 input은 문자/숫자 뿐
        ReadID(); //구분자(불법 구분자 포함)이 등장하기 전 까지 (start with 문자인)문자+숫자로 이루어진 word를 ST테이블에 저장

        // ST에 넣어둔 word를 HT에 배치하는 코드
        // illid error의 경우 ST에도 들어가지 못했으므로 실행해서는 안됨
        if (err != illid) {

            //nextfree는 값을 넣은 후에 ++되므로, ++된 이후에 한번도 overflow검사를 진행하지 않았기에 한번더 실시
            if (nextfree == STsize) {
                err = overst;
                PrintError(err); //overflow가 되면 그대로 종료임
            }


            //하나의 word를 입력하면 자동으로 공백을 저장해줌
            ST[nextfree++] = '\0'; //한 덩어리 끝
            if (err == noerror) {
                //nextid : word의 첫 시작 index , nextfree : word의 마지막 letter + 1 index(공백저장됨)
                ComputeHS(nextid, nextfree); //입력 word의 hashcode : hashtable상에 저장될 index 계산
                LookupHS(nextid, hashcode);
                if (!found) {//FALSE면, 존재하지 않으므로 넣었다고 표시
                    printf("%6d		", nextid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(entered)\n");
                    ADDHT(hashcode);
                } else {//TRUE면, -> 이미 존재하는 것 이라고 표시 (넣지않음)
                    printf("%6d		", sameid); //이미 있으므로 이미 존재하는 것의 index를 출력함
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(already existed)\n");
                    nextfree = nextid;
                }
            }
        }

    }
    PrintHStable();
}
