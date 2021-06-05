
/*
* glob.h - global variable for the project(HW3)
*
* Programmer - team2
*
* date -  5/26/2021
*
*/

/*
HT, ST 크기 정의, 식별자 최대길이 정의
*/

#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1
#define MaxIdentLen 12

/*
* 포인터 HTptr, HTentry 구조체
* HTentry를 가리키는 HTptr
*/
typedef struct HTentry *HTptr;

/*
* index: ST 읽을때 사용
* type: case 구분하기 위한 변수
* cLine: 코드 줄 수 담는 변수
*/
typedef struct HTentry {
	int index;
	int type;
	int cLine;
	char *scope;
	HTptr next;
};


HTptr HT[HTsize];
HTptr look_id;
HTptr look_tmp;

char *preyytext;
char *funcname;


char ST[STsize];

/*
* nextid: 현재 identifier의 시작 index
* nextfree: ST에서 다음 character가 삽입될 곳의 index
*/
int nextid;
int nextfree;
int hashcode;
int sameid;
int yyleng;
char *yytext;

/*
* errorTypes
* wrong_funcdef: 잘못된 function 정의
* nosemi : semicolon 빠짐
* nobrace : 중괄호 생략된 경우
* nobracket: 대괄호 생략된 경우
*
*/
enum errorTypes { wrong_funcdef, nosemi, nobrace, nobracket, tlong, toverflow,nocomma , wrong_st};
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

/*
* cErrors: 에러 개수 세기
* cLine: 코드 줄 수 세기
* found: symtable.c 에서 사용하는 검색용 flag
*/
int cErrors;
int cLine;
int found;