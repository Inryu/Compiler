int cErrors=0;

void yyerror(int s) {
	
	if (s != 1) {
		printf(s);
		cErrors++;
	}else{
      cErrors--;
   }
}
