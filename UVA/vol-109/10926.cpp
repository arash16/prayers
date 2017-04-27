#include <bits/stdc++.h>
using namespace std;


vector<int> adj[143];
int n; bool seen[143];
int dfs(int u) {
    seen[u] = true;
    int result = 0;
    for (int v: adj[u])
        if (!seen[v])
            result += dfs(v) + 1;
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n && n) {
        for (int i=0, sz; i<n; ++i) {
            cin >> sz;
            adj[i].resize(sz);
            for (int j=0; j<sz; ++j) {
                cin >> adj[i][j];
                --adj[i][j];
            }
        }

        int mx=-1, mxi;
        for (int i=0; i<n; ++i) {
            memset(seen, 0, n);
            int c = dfs(i);
            if (mx < c) {
                mx = c;
                mxi = i;
            }
        }
        cout << mxi+1 << "\n";
    }
}
