/*
  >>~~ ACM PROBLEM ~~<<

  ID: 369
  Name: Combinations
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>
int main()
{
 char A[25];
 char P[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

 int i,j,n,m,t,s;
 long long res;

 while (scanf("%d%d",&n,&m)!=EOF)
 {
   s=0;
   memset(A,0,sizeof(A));
   if(n==0 && m==0)break;

   if(m>n/2){m=n-m;s=1;};

   for(i=n;i>n-m;i--)
   {
     t=i;
     for(j=0;j<25;j++)
       while(t%P[j]==0)
       {
         A[j]++;
         t/=P[j];
       }
   }

   for(i=m;i>0;i--)
   {
     t=i;
     for(j=0;j<25;j++)
       while(t%P[j]==0)
       {
         A[j]--;
         t/=P[j];
       }
   }

   res=1;
   for(i=0;i<25;i++)
    while((A[i]--)>0)
     res*=P[i];

   if(s)m=n-m;
   printf("%d things taken %d at a time is %d exactly.\n",n,m,res);
 }
 return 0;
}
