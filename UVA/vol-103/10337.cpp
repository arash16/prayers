/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10337
  Name: Flight Planner
  Problem: https://onlinejudge.org/external/103/10337.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 1073741824
int X[1002][12], DP[1002][12];
int min(int a, int b, int c) {
    return a<b && a<c ? a : b<c ? b : c;
}

int main(){
    int T, n;
    scanf("%d", &T);
    for (int i=0; i<1002; i++)
        DP[i][0]=DP[i][11]=INF;
    for (int j=1; j<11; j++)
        DP[0][j] = INF;

    while (T--) {
        scanf("%d", &n); n/=100;
        for (int j=9; j>=0; j--)
            for (int i=0; i<n; i++)
                scanf("%d", X[i]+j);

        DP[0][1] = 30-X[0][0];
        for (int i=1; i<n; i++)
            for (int j=1; j<11; j++)
                DP[i][j] = min(
                    DP[i-1][j-1] + 20,
                    DP[i-1][j  ] + 30,
                    DP[i-1][j+1] + 60
                ) - X[i][j-1];

        printf("%d\n\n", min(DP[n-1][1], DP[n-1][2]+30 ));
    }
}
