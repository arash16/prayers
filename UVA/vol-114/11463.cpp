#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


int D1[143], D2[143];
vector<int> adj[143];
void bfs(int n, int src, int D[]) {
    for (int i=0; i<n; ++i)
        D[i] = INF;

    queue<int> q;
    q.push(src); D[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u])
            if (D[v] == INF) {
                q.push(v);
                D[v] = D[u] + 1;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m, u, v;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int i=0; i<m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cin >> u >> v;
        bfs(n, u, D1);
        bfs(n, v, D2);

        int mxd = 0;
        for (int i=0; i<n; ++i)
            mxd = max(mxd, D1[i] + D2[i]);

        cout << "Case " << cse << ": " << mxd << endl;
    }
}
