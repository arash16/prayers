/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10616
  Name: Divisible Group Sums
  Problem: https://onlinejudge.org/external/106/10616.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

long long DP[205][11][21];
int d[205];

#define mod(a,b) ((a)%(b)<0?(a)%(b)+(b):(a)%(b))

int main(){
    int N,Q,D,M,cse=1,qi,cnt,s,i;

    while(scanf("%d%d",&N,&Q)==2 && (N||Q))
    {
        for(i=0;i<N;i++)
            cin>>d[i];

        for(i=0;i<=N;i++)
            for(s=0;s<21;s++)
                DP[i][0][s]=(s==0?1:0);

        printf("SET %d:\n",cse++);
        for(qi=1;qi<=Q;qi++){
            scanf("%d%d",&D,&M);

            for(cnt=1;cnt<=M;cnt++)
                for(s=0;s<D;s++)
                    DP[N][cnt][s]=0;

            for(i=N-1;i>=0;i--)
                for(cnt=1;cnt<=M;cnt++)
                    for(s=0;s<D;s++)
                        DP[i][cnt][s]=    DP[i+1][cnt-1][mod(s+d[i],D)]+
                                        DP[i+1][cnt][s];

            printf("QUERY %d: %lli\n",qi,DP[0][M][0]);
        }
    }
}