/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 440
  Name: Eeny Meeny Moo
  Problem: https://onlinejudge.org/external/4/440.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
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
