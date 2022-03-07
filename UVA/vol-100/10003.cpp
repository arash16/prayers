/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10003
  Name: Cutting Sticks
  Problem: https://onlinejudge.org/external/100/10003.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

short int c[55],DP[55][55];
int main(){
    int ll;
    register int l,i,e,k,n,m;

    while(scanf("%d",&ll)==1 && ll){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",c+i);
        c[n+1]=ll;

        for(l=2; l<=n+1; l++)
            for(i=0; i<=n+1-l; i++){
                e=i+l;
                short int &m=DP[i][e]=32767;
                for(k=i+1; k<e; k++)
                    m=min(m,(short)(DP[i][k]+DP[k][e]+c[e]-c[i]));
            }

        printf("The minimum cutting is %d.\n",DP[0][n+1]);
    }
}