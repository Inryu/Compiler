const int max=100;
void main(){

 int i,j,k;
 float inryu=163.7;
 int a[5];
 float a2[10];
 int rem, prime; // rem : remainder
   i=2;
   while(i<=max){
      prime=1;
      k=i/2;
      j=2;
      while(j<=k){
         rem=i%j;
         if(rem==0) prime=0;
         ++j;
      }
      if(prime==1) write(i);
      ++i;
   }
}