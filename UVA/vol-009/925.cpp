#include <bits/stdc++.h>
using namespace std;

bool seen[143];
bool R[143][143];
string names[143];
vector<int> adj[143];
bool dfs(int u, int dst) {
    if (u == dst)
        return true;

    seen[u] = 1;
    for (int v: adj[u])
        if (!seen[v] && !R[u][v] && dfs(v, dst))
            return true;

    return false;
}

bool comp(int u, int v) { return names[u] < names[v]; }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s;
    int T, n, m, c;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> names[i];
        sort(names, names+n);

        unordered_map<string, int> ids;
        for (int i=0; i<n; ++i) {
            ids[names[i]] = i;
            memset(R[i], 0, n);
            adj[i].clear();
        }

        cin >> m;
        while (m--) {
            cin >> s >> c;
            int u = ids[s];
            while (c--) {
                cin >> s;
                adj[u].push_back(ids[s]);
            }
        }

        for (int u=0; u<n; ++u) {
            for (int v: adj[u]) {
                R[u][v] = 1;
                memset(seen, 0, n);
                if (!dfs(u, v))
                    R[u][v] = 0;
            }

            int sz = 0;
            for (int i=0; i<adj[u].size(); ++i) {
                int v = adj[u][i];
                if (!R[u][v])
                    adj[u][sz++] = v;
            }
            adj[u].resize(sz);
            sort(adj[u].begin(), adj[u].end(), comp);
        }

        for (int u=0; u<n; ++u)
            if (adj[u].size()) {
                cout << names[u] << ' ' << adj[u].size();
                for (int v: adj[u])
                    cout << ' ' << names[v];
                cout << endl;
            }
    }
}
