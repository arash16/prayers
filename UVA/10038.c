/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10038
  Name: Jolly Jumpers
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>

int main()
{
 int n,i,t,t1;
 char nu[3001];
 while (scanf("%d%d",&n,&t)!=EOF)
 {
   memset(nu,0,sizeof(nu));
   for(i=1;i<=n-1;i++)
   {
     scanf("%d",&t1);
     nu[abs(t-t1)]=1;
     t=t1;
   }
   t=1;
   for(i=1;i<=n-1;i++)
     t+=nu[i];
   if(t==n)
     printf("Jolly\n");
   else
     printf("Not jolly\n");
 }
 return 0;
}
