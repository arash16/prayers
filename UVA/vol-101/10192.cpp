/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10192
  Name: Vacation
  Problem: https://onlinejudge.org/external/101/10192.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 105
int dp[MAXN][MAXN];
int main(){
    int cse = 0;
    char s1[MAXN], s2[MAXN];
    while(cin.getline(s1, MAXN) && s1[0]!='#') {
        cin.getline(s2, MAXN);
        int l1 = strlen(s1),
            l2 = strlen(s2);

        for (int i=max(l1,l2); i>=0; i--)
            dp[i][0] = dp[0][i] = 0;

        for (int i=1; i<=l1; i++)
            for( int j=1; j<=l2; j++)
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);


        printf("Case #%d: you can visit at most %d cities.\n", ++cse, dp[l1][l2]);
    }
}
