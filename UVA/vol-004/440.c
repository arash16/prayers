/*
  >>~~ ACM PROBLEM ~~<<

  ID: 440
  Name: Ugly Numbers
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int main(){
 int m,n,i,t,f;

 while (scanf("%d",&n)!=-1){
    if(!n)break;
    for(m=2;1;m++)
    {
       f=1;
       t=n-1;
       for(i=m;t>1;i+=m-1)
       {
           i=((i-1)%t)+1;
           if (i==1) f=0;
           t--;
       }
       if(f){printf("%d\n",m);break;}
    }
 }
 return 0;
}
