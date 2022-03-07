/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 673
  Name: Parentheses Balance
  Problem: https://onlinejudge.org/external/6/673.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

char str[130];
char check(int s,int e)
{
  int p,b,i;
  char cs,ce;
  if(e<s)return 1;
  cs=str[s];
  if(cs=='(')ce=')';
  else if(cs=='[')ce=']';
  else return 0;

  p=b=0;
  for(i=s;i<=e;i++)
  {
    if(str[i]=='(')p++;
    if(str[i]==')')p--;
    if(str[i]=='[')b++;
    if(str[i]==']')b--;
  }
  if(p || b)return 0;
  if(e==s+1)return 1;
  p=0;
  for(i=s;i<=e;i++)
  {
    if(str[i]==cs)p++;
    if(str[i]==ce)p--;
    if(!p)break;
  }
  if(check(s+1,i-1) && check(i+1,e))return 1;
  else return 0;
}

int main()
{
  int l,n;
  gets(str);
  sscanf(str,"%d",&n);
  while(gets(str)!=NULL)
  {
    for(l=0;str[l] && str[l]!='\n';)l++;
    if(check(0,l-1))
      printf("Yes\n");
    else
      printf("No\n");

    if(!--n)break;
  }
  return 0;
}
