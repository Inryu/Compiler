int main()
{
    int i = 0;
    while (i < 100)    // i iteration
    {
        printf(Hello);

        if(i%2==0){
	    printBye();
        }


        i++;           // i increase 1
    }

    return 0;
}

void printBye(){
     printf(By);
}