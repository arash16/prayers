/*
  >>~~ ACM PROBLEM ~~<<

  ID: 382
  Name: Perfection
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>
int main()
{
 int x,i,fsum;
 char output[10];

 printf("PERFECTION OUTPUT\n");
 while (scanf("%d",&x)!=EOF)
 {
   if(!x)break;

   fsum=1;
   for(i=2;i<sqrt(x);i++)
     fsum+=(x%i==0)?i+x/i:0;
   fsum+=(x/sqrt(x) == sqrt(x))?sqrt(x):0;
   if(x==1)fsum=0;

   printf("%5d  ",x);
   if(fsum==x)
     printf("PERFECT\n");
   else if(fsum<x)
     printf("DEFICIENT\n");
   else
     printf("ABUNDANT\n");
 }
   printf("END OF OUTPUT\n");
 return 0;
}
