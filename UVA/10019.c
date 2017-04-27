/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10019
  Name: Funny Encryption Method
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/


int count1(int x){
   int i,b=0,k;
   k=1;
   for(i=0;i<16;i++){
     b+=(x&k)>i;
     k*=2;
   }
   return b;
}

int main(){
 int n,m,k,i;
 int b1,b2;
 char buff[11]="0x";
 buff[10]=0;
 scanf("%d",&n);
 while (n--){
    scanf("%d",&m);
    
    b1=count1(m);
    
    sprintf(buff+2,"%d",m);
    sscanf(buff,"%x",&b2);
    b2=count1(b2);
    
    printf("%d %d\n",b1,b2);
 }
 return 0;
}
