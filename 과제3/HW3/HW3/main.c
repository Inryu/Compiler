/*
* main.c - lexical analyzer for Scanner : main (HW3)
*
* Programmer - team2
*
* date -
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

extern int yyparse();
extern void PrintHStable();

void main() {

	look_id = (HTptr)malloc(sizeof(struct HTentry));
	look_tmp = (HTptr)malloc(sizeof(struct HTentry));

	printf("\n\n\t\t\t    ***MiniC parsing begins***\n");
	printf("==================================================================================\n");


	cLine = 1;
	nextid = 0;
	nextfree = 0;

	yyparse();


	printf("==================================================================================\n");
	printf("\n\t\t  ===> Parsing ends.");


	if (cErrors == 0) { 
		printf("\t no errors detected\n\n\n\n"); 


	}

	else printf("\t %d error(s) detected\n\n\n\n", cErrors);


	PrintHStable();
}