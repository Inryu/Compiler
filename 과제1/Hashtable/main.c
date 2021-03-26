#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()?
#include <string.h>
#define FILE_NAME "../testdata-kh-error.txt"
#define STsize 1000 //size of string table
#define HTsize 100 // size of hash table

#define FALSE 0
#define TRUE 1

#define isLetter(x) ( x>='a' && x<='z'||x>='A'&& x<='Z'||x=='_')
#define isDigit(x) (x>='0'&&x<='9')


typedef struct HTentry *HTpointer;
typedef struct HTentry{
    int index; //index of identifier in ST
    HTpointer next; //pointer to next identifier

}HTentry;

enum errorTypes{noerror, illsp, illid, overst,toolong};
typedef enum errorTypes ERRORtypes;

char seperators[]=".,;:?!\t\n ";

HTpointer HT[HTsize];
char ST[STsize];

int nextid=0; //the current identifier
int nextfree=0; //the next available index of ST
int hashcode ; //hash code of identifier
int sameid; //fisrt index of identifier

int found; //for the previous ocurrence of a idntifier

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

    for(i=0;i<sep_len;i++){
        if(c==seperators[i]) {
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
            printf("\n  Hash Code %3d : ", i);
        }
        for(here =HT[i]; here!=NULL; here=here->next){
            j=here->index;
            while(ST[j]!='\0' && j<STsize){
                printf("%c",ST[j++]);
//                printf("      ");

            }

            printf(" ");
//            printf("\n");
        }
    }
    printf("\n\n\n < %5d characters are used in the string table > \n ",nextfree);

}

/* PrintError -Print out error messages
* overst: overflow in ST
* print the hashtable and abort by calling the function "abort()"
* illid: illegal identifier
* illsp: illegal seperator
 */

void PrintError(ERRORtypes err){
    switch(err){
        case overst:
            printf("...Error... OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
        case illsp:
            printf("...Error...    ");

            char tmp=input;

            for( int i = nextid; i< nextfree; i++ )
                printf("%c", ST[i]);

            printf("%c",tmp);

            input=fgetc(fp);

            while(input != EOF && (isLetter(input)|| isDigit(input))||!isSeperator(input)){
                printf("%c",input);
                input=fgetc(fp);
            }

            printf("%15c is not allowed \n", tmp);
            break;
        case illid:
            printf("...Error...    ");
            for( int i = nextid; i< nextfree -1; i++ )
                printf("%c", ST[i]);
            while(input != EOF && (isLetter(input)|| isDigit(input))){
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



//맨 앞글자가 seperator인지?
void SkipSeperators(){

    while(input !=EOF && !(isLetter(input)|| isDigit(input))){ //문자도 아니고 숫자도 아니고 마지막 글자도 아님
        if(!isSeperator(input)){ //이때, 불법 구분자면
            err=illsp;
            nextid=nextfree;
            PrintError(err);
            err=noerror;

        }

        input = fgetc(fp); // 또 읽음
    }

    if(input==EOF){
        PrintHStable();
        for(int i=0;i<nextfree;i++){

            if(ST[i]=='\0') printf("/");
            else printf("%c",ST[i]);
        }
        exit(1);
    }

}
/* ReadIO-
* Read identifiers from the input file the string table ST  directly into ST(append it to the previous identifier).
* An identifier is a string of letter ans digits, starting with a letter.
* If first letter is digit, print out error message.*/


int longcnt=0;
void ReadID(){

    nextid=nextfree;
    if(isDigit(input)){ //첫글자고 숫자면
        err=illid;
        PrintError(err);
    }
    else{
        // ST 만들기 (한 문자 넣기)
        // 문자이거나 숫자일 때
        while(input!=EOF &&(isLetter(input) ||isDigit(input)||!isSeperator(input))){
            if(nextfree ==STsize){ //텍스트 파일이 1000자를 넘어가냐!?
                err=overst;
                PrintError(err);

            }

            //읽다가 불법구분자 나오면
            if(!isLetter(input)&&!isDigit(input)){
                err=illsp;
                PrintError(err);
                nextfree=nextid;
                longcnt=0;
                break;
            }


            longcnt++;

            //아니면
            ST[nextfree++]=input; //ST에 넣어줌.
            input=fgetc(fp);


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


    //비어있지 않으면
    if( HT[hscode] != NULL){
        here = HT[hscode];
        while(here != NULL && found == FALSE){
            found = TRUE;
            i = here->index;
            j = nid;
            sameid = i;
            while(ST[i] != '\0' && ST[j] != '\0' && found == TRUE ) {
                if(ST[i] != ST[j]) found = FALSE;
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

    ptr = (HTpointer *)malloc(sizeof(ptr));
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
    PrintHeading(); // header프린팅
    initialize(); //파일


    //한 글자.
    while(input != EOF){
        err = noerror;
        SkipSeperators();
        ReadID(); //한 덩어리 읽어


        if(input==EOF){
            ST[nextfree++] = '\0'; //한 덩어리 끝

            if (!found) { // 아직 같은 symbol넣은 적 없을 때
                printf("%6d		", nextid);
                for (i = nextid; i < nextfree - 1; i++)
                    printf("%c", ST[i]);
                printf("		(entered)\n");
                ADDHT(hashcode);
            } else { //
                printf("%6d		", sameid);
                for (i = nextid; i < nextfree - 1; i++)
                    printf("%c", ST[i]);
                printf("		(already existed)\n");
                nextfree = nextid;
            }

        }
        // 한 symbol 읽고 난 후 구분자후보..!
        if(input!=EOF&& err != illid &&err!=illsp) {

            //불법구분자다?
            if(!isSeperator(input)){
                err=illsp;
                PrintError(err);
                nextfree = nextid;
                printf("🌟🌟🌟🌟\n");

            }

            if(nextfree == STsize) {
                err = overst;
                PrintError(err);
            }

            ST[nextfree++] = '\0'; //한 덩어리 끝

            //12글자 넘으면
            if(longcnt>12){
                err=toolong;
                PrintError(err);
                nextfree=nextid;
            }

            longcnt=0;

            if(err==noerror) {
                ComputeHS(nextid, nextfree);
                LookupHS(nextid, hashcode);

                if (!found) { // 아직 같은 symbol넣은 적 없을 때
                    printf("%6d		", nextid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(entered)\n");
                    ADDHT(hashcode);
                } else { //
                    printf("%6d		", sameid);
                    for (i = nextid; i < nextfree - 1; i++)
                        printf("%c", ST[i]);
                    printf("		(already existed)\n");
                    nextfree = nextid;
                }
            }
        }
    }
    PrintHStable();

    for(int i=0;i<200;i++){
        printf(" %c ",ST[i]);
    }




}