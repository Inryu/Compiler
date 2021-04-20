#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

void reporterror(enum tnumber tn) {
	switch (tn) {
			case TILLIDENT:
				printf("%-20d %-20s %-20s %-30s", lineno, "**Error**", " ", str(yytext)+"Illegal IDENT");  
				break;

			case TILLCHAR:
				printf("%-20d %-20s %-20s %-30s", lineno, "**Error**", " ", str(yytext) + "Illegal Character");
				break;

			case TLONG:
				printf("%-20d %-20s %-20s %-30s", lineno, "**Error**", " ", str(yytext) + "Too Long IDENT");
				break;
}