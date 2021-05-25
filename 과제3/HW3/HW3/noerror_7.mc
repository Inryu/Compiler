int main(){
	int i,j;

	while(i<10){
		if(i == 8){
			printError();
		}
		j += i;
		i = i+2;
	}

	return 0;
}

int Error=0;
void printError(){
	printf(Error);
}