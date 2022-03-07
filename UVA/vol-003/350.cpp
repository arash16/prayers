/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 350
  Name: Pseudo-Random Numbers
  Problem: https://onlinejudge.org/external/3/350.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
using namespace std;

int calc(int z,int i,int m,int l){
  return (z*l+i)%m;}
int main()
{
     int z,i,l,m,count,casen=1,first;
     bool repeated[10000]={0};
     while (cin>>z>>i>>m>>l && (z+i+m+l))
     {
           memset(repeated,0,sizeof(repeated));
           count=0;
           first=l;
           do repeated[l]=1,l=calc(z,i,m,l),count++; while(!repeated[l]);
           cout<<"Case "<<casen++<<": "<<((l==first)?count:count-1)<<endl;
     }
  return 0;
}
