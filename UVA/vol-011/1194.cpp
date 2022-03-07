/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1194
  Name: Machine Schedule
  Problem: https://onlinejudge.org/external/11/1194.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> adj[143];
int matchL[143], matchR[143];
bool seen[143];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (matchR[v]==-1 || bpm(matchR[v])) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
    return false;
}

// http://www.immorlica.com/combOpt/lec1.pdf
void konig(int u) {
    matchL[u] = -1;
    for (int v: adj[u])
        if (!seen[v] && matchR[v]>=0) {
            seen[v] = 1;
            konig(matchR[v]);
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int l, r, n;
    while (cin >> l >> r >> n) {
        for (int i=0; i<=l; ++i)
            adj[i].clear();

        adj[0].push_back(0);
        for (int i=0, t,u,v; i<n; ++i) {
            cin >> t >> u >> v;
            if (u || v)
            adj[u].push_back(v);
        }

        int cnt = 0;
        memset(matchL, -1, l*sizeof(int));
        memset(matchR, -1, r*sizeof(int));
        for (int i=0; i<l; ++i) {
            memset(seen, 0, r);
            if (bpm(i)) ++cnt;
        }

        memset(seen, 0, r);
        for (int i=0; i<l; ++i)
            if (matchL[i]<0)
                konig(i);

        if (matchL[0]>=0) --cnt;
        if (seen[0]) --cnt;
        cout << cnt << '\n';
    }
}
