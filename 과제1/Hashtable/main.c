#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()?
#include <string.h>
#define FILE_NAME "../testdata3.txt"
#define STsize 1000 //size of string table
#define HTsize 100 // size of hash table

#define FALSE 0
#define TRUE 1

#define isLetter(x) ( x>='a' && x<='z'||x>='A'&& x<='Z'||x=='_')
#define isDigit(x) (x>='0'&&x<='9')

enum errorTypes{noerror, illsp, startnum,illid, overst,toolong};
typedef enum errorTypes ERRORtypes;
char seperators[]=".,;:?!\t\n ";


typedef struct HTentry *HTpointer;
typedef struct HTentry{
    int index; //index of identifier in ST
    HTpointer next; //pointer to next identifier
}HTentry;

HTpointer HT[HTsize];

char ST[STsize];

int nextid=0; //the current identifier
int nextfree=0; //the next available index of ST
int hashcode ; //hash code of identifier
int sameid; //fisrt index of identifier
int found; //for the previous ocurrence of a identifier

ERRORtypes err;

FILE *fp; //to be a pointer to FILE
int input;

//Initialize - open input file
void initialize(){
    fp=fopen(FILE_NAME, "r");
    input=fgetc(fp);
}

//isSeperator - distinguish the seperator
int isSeperator(char c){
    int i;
    int sep_len;

    sep_len=strlen(seperators);

    //input c가 seperator에 속하는지 확인
    for(i=0;i<sep_len;i++){
        if(c==seperators[i]) return 1;
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

/* PrintHStable - Prints the hash table write out the hashcode and the list of identifiers
associated with each hashcode, but only for non-empty lists.
Print out the number of characters used up in ST. */

void PrintHStable()
{
    int i,j;
    HTpointer here;

    printf("\n\n\n\n\n [[  HASH TABLE  ]] \n\n");

    for(i=0; i< HTsize; i++){
        if( HT[i] != NULL){
            printf("  Hash Code %3d : ", i);
        }
        for(here =HT[i]; here!=NULL; here=here->next){
            j=here->index;
            while(ST[j]!='\0' && j<STsize){
                printf("%c",ST[j++]);
                printf("      ");

            }
            printf("\n");
        }
        printf("\n\n\n < %5d characters are used in the string table > \n ",nextfree);
    }
}

/* PrintError -Print out error messages
* overst: overflow in ST
* print the hashtable and abort by calling the function "abort()"
* illid: illegal identifier
* illsp: illegal seperator
 */

void PrintError(ERRORtypes err){
    switch(err){

        //letter, digit이 아닌 게 있으면
        case illid:
            printf("...Error...    ");
            for( int i = nextid; i< nextfree -1; i++ )
                printf("%c", ST[i]);
            while(input != EOF){
                if(isSeperator(input)){
                    break;
                }
                printf("%c",input);
                input=fgetc(fp);
            }
            printf("illgal identifier \n", input);
            break;
        case overst:
            printf("...Error... OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
        case illsp:
            printf("...Error...    ");
            for( int i = nextid; i< nextfree -1; i++ )
                printf("%c", ST[i]);

            printf("%15c Is not allowed \n", input);
            break;
        case startnum :
            printf("...Error...    ");

            //숫자로 시작된 단어.. seperator 나올 때 까지 출력
            for( int i = nextid; i< nextfree -1; i++ )
                printf("%c", ST[i]);

            while(input != EOF){
                if(isSeperator(input)){
                    break;
                }
                printf("%c",input);
                input=fgetc(fp);
            }
            printf(" start with digit \n");
            break;
        case toolong:
            printf("...Error...   ");
            for( int i = nextid; i< nextfree -1; i++ )
                printf("%c", ST[i]);
            printf("    too long identifier \n");
            break;
    }
}
/* Skip Seperators -
*       skip over strings of spaces, tabs, newlines, .,; : ? !
*       if illegal seperators, print out error message
 * */

//seperator가 될 만한 것들이 나오면
void SkipSeperators(){

    while(input !=EOF && !(isLetter(input)|| isDigit(input))){
        if(!isSeperator(input)){ //불법구분자면
            err=illsp;
            PrintError(err);
        }
        input=fgetc(fp); // 또 읽음
    }

//    while(input !=EOF){
//        if(isSeperator(input)) input=fgetc(fp); // 또 읽음
//
//        if(isLetter(input)||isDigit(input)){
//            break;
//        }
//        if(!isSeperator(input)){
//            err=illsp;
//            PrintError(err);
//        }
//    }
}
/* ReadIO-
* Read identifiers from the input file the string table ST  directly into ST(append it to the previous identifier).
* An identifier is a string of letter ans digits, starting with a letter.
* If first letter is digit, print out error message.*/


int longcnt=0;

void ReadID(){
    nextid=nextfree;

    if(isDigit(input)){ //첫글자에 숫자면
        err=startnum;
        PrintError(err);
    }
    else{
        // 하나의 identifier을 읽어서 ST에 저장
        while(input!=EOF){//seperator가 나올 때 까지 돈다.

            //불법구분자이거나, letter, digit이 아닐 때 에러 셋
            if(!isSeperator(input)){
                err=illsp;
                PrintError(illsp);
            }
            if(!isLetter(input)||!isDigit(input)){
                err=illid;
                PrintError(illid);
            }

            //구분자가 나오면 종료
            if(isSeperator(input)) break;

            longcnt++; // 제대로 된 거 때마다 cnt 증가

            if(nextfree ==STsize){ //텍스트 파일이 1000자를 넘어가냐!?
                err=overst; //🌟nextfree, STsize 인덱스 확인해보기
                PrintError(err);
            }
            else {    //아니면
                ST[nextfree++] = input; //ST에 넣어주고
                input = fgetc(fp);  // 계속해서 읽음 //seperator로 추정되는 것 또는 파일 끝까지 다 읽었을 때 while문 종료
            }
        }
    }

}
/*ComputeHS - Compute the hash code of identifier by summing the ordinal values of its
characters and then taking the sum modulo the size of HT */
void ComputeHS(int nid,int nfree)
{
    int code,i;
    code =0;
    for(i = nid; i < nfree-1; i++){
        code += (int)ST[i]; //아스키 코드 합
        hashcode = code % HTsize; //mod
    }
}
/*
LookupHS
For each indentifier, Look it up in the hashtable for previous occurrence of the identifier.
If find a match, set the found flag as true.
Other wise false.
If find a match, save the starting index of ST in same id
*/
void LookupHS(int nid, int hscode)
{
    HTpointer here;
    int i, j;
    found = FALSE;


    //연결리스트가 생성 되어있으면
    if( HT[hscode] != NULL){
        //첫번째 리스트를 봄.
        here = HT[hscode];

        //HT[hscode]의 모든 연결리스트에, 동일한 symbol이 있는지 확인
        while(here != NULL && found == FALSE){
            found = TRUE; // true : 같은 거 존재한다고 가정
            i = here->index; // 포인터로 살펴보고 있는 애의 index
            j = nid; //지금 넣을 애의 index
            sameid = i;

            //ST[현재 살펴보고있는 애의 index]=symbol의 첫 인덱스, ST[지금 넣을 애의 index]가 비어있지 않고(symbol의 끝까지)
            //둘이 같지 않으면 바로 종료,
            while(ST[i] != '\0' && ST[j] != '\0' && found == TRUE ) {
                if(ST[i] != ST[j]) found = FALSE; //하나라도 둘이 같지 않으면 found : false 같은 것이 존재하지 않음

                //모든 심볼을 살펴볼 거니깐.
                else{
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
Add a new identifier to the hash table.
If list head ht[hashcode] is null, simply add a list element with
starting index of the identifier in ST.
IF list head is not a null, it adds a new idetifier to the head of the chain
*/


void ADDHT(int hscode)
{
    HTpointer ptr;
    //이게 맞아..?
    // ptr = (HTpointer *)malloc(sizeof(HTpointer));

    ptr = (HTpointer *)malloc(sizeof(HTpointer));

    // 맨 앞에 삽입
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



int main()
{
    int i;
    PrintHeading(); // header 프린팅
    initialize(); // input 파일 열기

    //한 글자.
    while(input != EOF){
        err = noerror;
        SkipSeperators();
        ReadID(); //한 덩어리 읽어

        // 한 문자 다 읽었을 때
        // 한 덩어리 읽고 난 후 구분자후보..!
        if(input != EOF && err !=startnum ) { //첫글자가 숫자가 아니였으면.

            if(!isSeperator(input)){ //다음이 ill공백이면..
                err=illsp;
                PrintError(err);
                ST[nextfree++]=input; //그래도 넣음
            }

            if(nextfree == STsize) {
                err = overst;
                PrintError(err);
            }

            ST[nextfree++] = '\0'; //한 덩어리 끝

            //12글자 넘으면
            if(longcnt>=12){
                err=toolong;
                PrintError(err);
            }

            longcnt=0; //초기화

            if(err==noerror) {
                ComputeHS(nextid, nextfree);
                LookupHS(nextid, hashcode);


                if (!found) { //같은것이 존재하지 않음
                    printf("%6d		", nextid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(entered)\n");

                    //새로 추가
                    ADDHT(hashcode);

                } else { //같은 것이 존재함.
                    printf("%6d		", sameid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(already existed)\n");

                    //추가하지 않고,
                    nextfree = nextid; //🌟이것은 무엇..?
                }
            }
        }
    }
    PrintHStable();
}