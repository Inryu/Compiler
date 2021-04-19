
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern char *yytext;

void main()
{
	enum tnumber tn;  // token number
	printf("  Start of Lex\n");
	while ((tn = yylex()) != TEOF) {
		switch (tn) {
		case TCONST: printf("Const\n");  break;
		case TELSE: printf("Else\n"); break;
		case TIF: printf("If\n"); break;
		case TINT: printf("Integer\n"); break;
		case TRETURN: printf("Return\n"); break;
		case TVOID: printf("Void\n"); break;
		case TWHILE: printf("While\n"); break;
		case TEQUAL: printf("Equal\n"); break;
		case TNOTEQU: printf("Not Equal\n"); break;
		case TLESSE: printf("Less than\n"); break;
		case TGREATE: printf("Greater than\n"); break;
		case TAND: printf("And\n"); break;
		case TOR: printf("Or\n"); break;
		case TINC: printf("Increase\n"); break;
		case TDEC: printf("Decrease\n"); break;
		case TADDASSIGN: printf("Add Assign\n"); break;
		case TMULASSIGN: printf("Mul Assign\n"); break;
		case TDIVASSIGN: printf("Div Assign\n"); break;
		case TMODASSIGN: printf("Mod Assign\n"); break;
		case TIDENT: printf("Identifier\n"); break;
		case TNUMBER: printf("Number\n"); break;


		}
	}
}