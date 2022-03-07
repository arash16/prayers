/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10092
  Name: The Problem with the Problem Setter
  Problem: https://onlinejudge.org/external/100/10092.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> adj[23];
int matchR[1024];
bool matchL[23][1024], seen[1024];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (!matchR[v] || bpm(matchR[v])) {
                if (matchR[v])
                    matchL[matchR[v]][v] = 0;
                matchL[matchR[v] = u][v] = 1;
                return true;
            }
        }
    return false;
}



char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int C[23], n, p;
    while (cin >> n >> p && (n||p)) {
        for (int i=1; i<=n; ++i) {
            memset(matchL[i], 0, p);
            adj[i].clear();
            cin >> C[i];
        }

        for (int i=0, sz,u; i<p; ++i) {
            matchR[i] = 0;
            cin >> sz;
            while (sz--) {
                cin >> u;
                adj[u].push_back(i);
            }
        }

        for (int i=1; i<=n; ++i)
            for (int j=0; j<C[i]; ++j) {
                memset(seen, 0, p);
                if (!bpm(i)) {
                    cout << "0\n";
                    goto fin;
                }
            }

        cout << "1\n";
        for (int i=1; i<=n; ++i) {
            bool f=1;
            for (int j=0; j<p; ++j)
                if (matchL[i][j]) {
                    if (f) f = 0;
                    else cout << ' ';
                    cout << j+1;
                }
            cout << '\n';
        }
        fin:;
    }
}
