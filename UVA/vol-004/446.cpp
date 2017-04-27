/*
  >>> ACM PROBLEM <<<

  ID: 446
  Name: Kibbles `n' Bits `n' Bits `n' Bits
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
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
