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


	printf("=============================================================================== \n");
	printf("\t\t***MiniC parsing begins***\n\n");


	cLine = 1;
	nextid = 0;
	nextfree = 0;

	yyparse();

	printf("\n\t\t***Parsing ends.***\n");
	printf("=============================================================================== \n");


	if (cErrors == 0) { 
		printf("\n\t no errors detected\n"); 
		PrintHStable();

	}

	else printf("\n\t %d error(s) detected\n", cErrors);
}