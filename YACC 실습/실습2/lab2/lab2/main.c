#include <stdio.h>
extern int yyparse();

void main()
{
	printf("start of parser\n");
	printf("==================\n");
	printf("team2\n");
	printf("1871026 신인류\n");
	printf("1871040 이유정\n");
	printf("1876136 박가현\n");
	printf("==================\n");
	yyparse();
	printf("end of parser\n");
}