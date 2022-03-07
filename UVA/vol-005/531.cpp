/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 531
  Name: Compromise
  Problem: https://onlinejudge.org/external/5/531.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
int DP[104][104], P[104][104];
char words1[104][40],
    words2[104][40];

bool eq(int u, int v) {
    int i;
    for (i=0; words1[u][i]; i++)
        if (words1[u][i] != words2[v][i])
            return 0;
    return words1[u][i] == words2[v][i];
}


bool print(int i, int j) {
    if (!i || !j) return 1;

    if (!P[i][j]) {
        if (!print(i-1, j-1))
            cout << " ";
        cout << words1[i-1];

        return 0;
    }

    return P[i][j]==1
        ? print(i-1, j)
        : print(i, j-1);
}

int main(){
    while (cin>>words1[n=0]) {
        while (words1[n][0] != '#')
            cin>>words1[++n];

        cin>>words2[m=0];
        while (words2[m][0] != '#')
            cin>>words2[++m];

        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (eq(i-1, j-1)) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                    P[i][j] = 0;
                }
                else if (DP[i-1][j] >= DP[i][j-1]) {
                    DP[i][j] = DP[i-1][j];
                    P[i][j] = 1;
                }
                else {
                    DP[i][j] = DP[i][j-1];
                    P[i][j] = 2;
                }

        print(n, m);
        putchar('\n');
    }
}
