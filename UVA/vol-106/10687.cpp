/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10687
  Name: Monitoring the Amazon
  Problem: https://onlinejudge.org/external/106/10687.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define INF 1073741824
#define MAXN 1001

int X[MAXN], Y[MAXN], n;
int dist(int i, int j) {
    int xx = X[i] - X[j],
        yy = Y[i] - Y[j];

    return xx*xx + yy*yy;
}

bool iless(int i, int di, int j, int dj) {
    if (j < 0) return true;
    if (di != dj) return di < dj;
    if (X[i] != X[j]) return X[i] < X[j];
    return Y[i] < Y[j];
}

// --------------------------------------------------------


list<int> adj[MAXN];
bool seen[MAXN];
int dfs(int u) {
    seen[u] = true;
    int result = 1;
    for (int v: adj[u])
        if (!seen[v])
            result += dfs(v);

    return result;
}



int main(){
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            cin >> X[i] >> Y[i];
            adj[i].clear();
            seen[i]=0;
        }

        for (int i=0; i<n; i++) {
            int c1=-1, c2=1, d1=INF, d2=INF;
            for (int j=0; j<n; j++)
                if (i != j) {
                    int dd = dist(i, j);
                    if (iless(j, dd, c1, d1)) {
                        d2 = d1;
                        c2 = c1;
                        d1 = dd;
                        c1 = j;
                    }
                    else if (iless(j, dd, c2, d2)) {
                        d2 = dd;
                        c2 = j;
                    }
                }

            if (c1 != -1) {
                adj[i].push_back(c1);
                if (c2 != -1)
                    adj[i].push_back(c2);
            }
        }

        puts(dfs(0)==n
            ? "All stations are reachable."
            : "There are stations that are unreachable.");
    }
}
