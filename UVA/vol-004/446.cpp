/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 446
  Name: Kibbles "n" Bits "n" Bits "n" Bits
  Problem: https://onlinejudge.org/external/4/446.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
using namespace std;

void printB(int x){
     int i,t=4096;
     for(i=12;i>=0;i--)cout<<((x&t)>>i),t=t>>1;
}
int main()
{
     int x,y,n;
     char c;
     cin>>n;
     while(n--)
     {
       scanf("%x %c %x",&x,&c,&y);
       printB(x);printf(" %c ",c);printB(y);printf(" = %d\n",c=='+'?x+y:x-y);
     }
  return 0;
}
