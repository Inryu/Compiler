#include <stdio.h>
extern int yyparse();

void main()
{
	printf("start of parser\n");
	printf("==================\n");
	printf("team2\n");
	printf("1871026 ���η�\n");
	printf("1871040 ������\n");
	printf("1876136 �ڰ���\n");
	printf("==================\n");
	yyparse();
	printf("end of parser\n");
}