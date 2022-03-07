/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 424
  Name: Integer Inquiry
  Problem: https://onlinejudge.org/external/4/424.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>

void sum(char n1[],char n2[])
{
  int i;
  for(i=110;i>=0;i--)
  {
    n1[i]+=n2[i];
    n1[i-1]+=floor(n1[i]/10);
    n1[i]=n1[i]%10;
  }
}

char readlong(char num[])
{
  char l,i;
  char str[111];
  memset(str,0,sizeof(str));

  gets(str);

  if(str[0]=='0' && !str[1])
    return 0;

  for(l=0;str[l];)l++;
  for(i=110;i>110-l;i--)
  {
    num[i]=str[i-111+l]-48;
  }
  return 1;
}

void printlong(char num[])
{
  int i=0;
  while(!num[i] && i!=110)i++;
  while(i<111)
    printf("%d",num[i++]);
    printf("\n");
}

int main()
{

 char n2[111],n1[111];
 int i,j,o;

 memset(n1,0,sizeof(n1));
 memset(n2,0,sizeof(n2));
 readlong(n1);
 while(readlong(n2)>0)
 {
   sum(n1,n2);
   memset(n2,0,sizeof(n2));
 }
 printlong(n1);

 return 0;
}
