/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10018
  Name: Reverse and Add
  Problem: https://onlinejudge.org/external/100/10018.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>

typedef unsigned long big;


double mpow(int n,int k)
{
  return k==0?1:pow(n,k);
}

char nlen(big n)
{
  return (char)(log10(n)+1);
}

char nth(big n,int k)
{
  return ((big)(n/mpow(10,k-1))) % 10;
}

big rev(big n)
{
  int i,l;
  big t;
  t=0;
  l=nlen(n);
  for(i=l;i;i--)
    t+=nth(n,i)*mpow(10,l-i);
  return t;
}

char ispd(big n)
{
  int i,l;
  l=nlen(n);
  for(i=1;i<=l/2;i++)
    if(nth(n,i)!=nth(n,l-i+1))
      return 0;
  return 1;
}

int main()
{
 int nt,count;
 big n;
 scanf("%d",&nt);
 while (nt--)
 {
   scanf("%lu",&n);
   count=0;
   while(!ispd(n))
   {
     count++;
     n+=rev(n);
   }
   printf("%d %lu\n",count,n);
 }
 return 0;
}
