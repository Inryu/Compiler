
/*
* glob.h - global variable for the project(HW3)
*
* Programmer - team2
*
* date - 2021/05/26
*
*/

/*
HT, ST ũ�� ����, �ĺ��� �ִ���� ����
*/

#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1
#define MaxIdentLen 12

/*
* ������ HTptr, HTentry ����ü
* HTentry�� ����Ű�� HTptr
*/
typedef struct HTentry *HTptr;

/*
* index: ST ������ ���
* type: case �����ϱ� ���� ����
* cLine: �ڵ� �� �� ��� ����
*/
typedef struct HTentry {
	int index;
	int type;
	int cLine;
	HTptr next;
};


HTptr HT[HTsize];
HTptr look_id;
HTptr look_tmp;


char ST[STsize];

/*
* nextid: ���� identifier�� ���� index
* nextfree: ST���� ���� character�� ���Ե� ���� index
*/
int nextid;
int nextfree;
int hashcode;
int sameid;
int yyleng;
char *yytext;

/*
* errorTypes
* wrong_funcdef: �߸��� function ����
* nosemi : semicolon ����
* nobrace : �߰�ȣ ������ ���
* nobracket: ���ȣ ������ ���
*
*/
enum errorTypes { wrong_funcdef, nosemi, nobrace, nobracket, tlong, toverflow };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

/*
* cErrors: ���� ���� ����
* cLine: �ڵ� �� �� ����
* found: symtable.c ���� ����ϴ� �˻��� flag
*/
int cErrors;
int cLine;
int found;