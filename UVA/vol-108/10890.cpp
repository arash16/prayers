/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10890
  Name: Maze
  Problem: https://onlinejudge.org/external/108/10890.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int adj[43][43], X[43], Y[43], n, t, s, best;
bool visited[43];
void bt(int li, int cnt, int len) {
    int h = abs(X[li]-n+1) + abs(Y[li]-n+1);
    if (len + h >= best) return;
    if (cnt == s) { best = len + h; return; }

    for (int i=0; i<t; ++i) {
        int k = adj[li][i];
        if (!visited[k]) {
            visited[k] = 1;
            bt(k, cnt+1, len + abs(X[li]-X[k]) + abs(Y[li]-Y[k]));
            visited[k] = 0;
        }
    }
}

int cuc;
bool comp(int i, int j) {
    return abs(X[cuc]-X[i])+abs(Y[cuc]-Y[i]) < abs(X[cuc]-X[j])+abs(Y[cuc]-Y[j]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n >> t >> s && (n||t||s); ++cse) {
        for (int i=1; i<=t; ++i)
            cin >> X[i] >> Y[i];

        for (cuc=0; cuc<=t; ++cuc) {
            for (int j=0; j<t; ++j)
                adj[cuc][j] = j+1;
            sort(adj[cuc], adj[cuc]+t, comp);
        }

        best = (int)1e9;
        bt(0, 0, 0);
        cout << "Case " << cse << ": " << best << '\n';
    }
}
