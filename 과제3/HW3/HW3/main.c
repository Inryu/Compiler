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


	printf("\n\t[Error Report : Error Information]");
	printf("\n == == == == == == == == == == == == == == == == == == == = \n");


	cLine = 1;
	yyparse();

	if (cErrors == 0) printf("\n\t no errors detected\n");
	else printf("\n\y %d error(s) detected\n", cErrors);
	printf(" == == == == == == == == == == == == == == == == == == == = \n");
	PrintHStable();
}