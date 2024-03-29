/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10918
  Name: Tri Tiling
  Problem: https://onlinejudge.org/external/109/10918.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int f[31],g[31];
int main(){
    int i;

    f[0]=g[1]=1;
    for(i=2;i<31;i++){
        f[i]=f[i-2]+2*g[i-1];
        g[i]=g[i-2]+f[i-1];
    }

    int n;
    while(scanf("%d",&n)==1 && n!=-1)
        cout<<f[n]<<endl;
}