/*
* glob.h - global variable for the project(HW3)
*
* Programmer - team2
*
* date - 
*
*/

#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1


typedef struct HTentry *HTptr;
typedef struct HTentry {
	int index;
	int type;
	HTptr next;
};


HTptr HT[HTsize];
char ST[STsize];

int nextid;      //���� identifier�� ���� index
int nextfree;    //ST���� ���� character�� ���Ե� ���� index
int hashcode;
int sameid;


enum errorTypes { wrong_st, wrong_funcdef, nosemi, nobrace, nobracket };
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

int cErrors; //error count
int cLine; //line number

int found;

