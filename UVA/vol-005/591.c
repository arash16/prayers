/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 591
  Name: Box of Bricks
  Problem: https://onlinejudge.org/external/5/591.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
int main()
{
 int n,i,k,sum,avg;
 char h[51];

 k=1;
 while (scanf("%d",&n)!=EOF)
 {
   if(n==0)break;

   sum=0;
   for(i=1;i<=n;i++)
   {
     scanf("%d",&h[i]);
     sum+=h[i];
   }
   avg=(int)(sum/n);
   sum=0;
   for(i=1;i<=n;i++)
     sum+=abs(h[i]-avg);
   printf("Set #%d\nThe minimum number of moves is %d.\n\n",k++,(int)(sum/2));
 }
 return 0;
}
