/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1198
  Name: The Geodetic Set Problem
  Problem: https://onlinejudge.org/external/11/1198.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


vector<int> P[43][43];
int D[43][43];
int cov[43], seen[43][43], cse;
void mark(int u, int v) {
    if (seen[u][v]==cse) return;
    cov[u] = cov[v] = seen[u][v] = cse;
    for (int p: P[u][v]) {
        mark(u, p);
        mark(p, v);
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    int n, m;
    cin >> n; cin.ignore(100, '\n');

    for (int u=0; u<n; ++u) {
        for (int v=0; v<n; ++v)
            D[u][v] = INF;
        D[u][u] = 0;
    }

    for (int u=0; u<n; ++u) {
        getline(cin, line);
        stringstream sin(line);

        for (int v; sin>>v; )
            if (D[u][--v]==INF) {
                D[u][v] = D[v][u] = 1;
                P[u][v].push_back(u);
                P[v][u].push_back(v);
            }
    }

    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
        if (i!=k && D[i][k] != INF)
            for (int j=0; j<n; ++j)
            if (j!=k && D[k][j] != INF) {
                int d = D[i][k] + D[k][j];
                if (d <= D[i][j]) {
                    if (d < D[i][j]) {
                        D[i][j] = d;
                        P[i][j].clear();
                    }
                    P[i][j].push_back(k);
                }
            }


    cin >> m; cin.ignore(100, '\n');
    for (cse=1; cse<=m; ++cse) {
        getline(cin, line);
        stringstream sin(line);
        vector<int> s;
        for (int v; sin>>v;)
            s.push_back(v-1);

        for (int i=0; i<s.size(); ++i)
            for (int j=0; j<=i; ++j)
                mark(s[i], s[j]);

        bool f = true;
        for (int i=0; f && i<n; ++i)
            f &= cov[i] == cse;

        cout << (f ? "yes\n" : "no\n");
    }
}
