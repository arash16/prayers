/*
  >>~~ ACM PROBLEM ~~<<

  ID: 256
  Name: Quirksome Squares
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/
#include <math.h>
int main()
{
  int digits,n,p;
  long s,d;
  char fs[20];
  while(scanf("%d",&digits)!=-1)
  {
   p=ceil(pow(10,digits/2));
   for(n=0;n<p;n++)
   {
     s=n*n;
     d=(int)(s/p) + (s%p);
     if(d == n)
     {
       sprintf(fs,"%%0%dd\n",digits);
       printf(fs,s);
     }
   }
  }
  return 0;
}
