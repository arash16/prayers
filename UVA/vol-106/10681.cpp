/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10681
  Name: Teobaldo's Trip
  Problem: https://onlinejudge.org/external/106/10681.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, d;
vector<int> adj[143];
bool seen[143][286];
bool dfs(int u, int depth) {
    seen[u][depth] = true;
    if (depth == d)
        return u == e-1;

    for (int v: adj[u])
        if (!seen[v][depth+1])
            if (dfs(v, depth+1))
                return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> m && (n||m)) {
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int u, v; m--; ) {
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        cin >> s >> e >> d;
        for (int i=0; i<n; ++i)
            for (int j=0; j<=d; ++j)
                seen[i][j] = 0;

        cout << (dfs(s-1, 0) ? "Yes, Teobaldo can travel.\n" : "No, Teobaldo can not travel.\n");
    }
}
