/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 694
  Name: The Collatz Sequence
  Problem: https://onlinejudge.org/external/6/694.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
     unsigned long int a,b,l,n=0,count,i=0;
     while (cin>>a>>l && (a!=-1 && l!=-1))
     {
           i++;
           count=1;b=a;
           while(a!=1){
             if(a%16==0)a/=16,count+=4;
             else if(a%8==0)a/=8,count+=3;
             else if(a%4==0)a/=4,count+=2;
             while(a%2==0)a/=2,count++;
             if(a>1)a=3*a+1;
             if(a>l)break;
             if(a>1)count++;
           }
           printf("Case %lu: A = %lu, limit = %lu, number of terms = %lu\n",i,b,l,count);
     }
  return 0;
}
