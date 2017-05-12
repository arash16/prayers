#include <bits/stdc++.h>
using namespace std;

vector<int> adj[414];
int S[414], D[414], Q[414], ccse;
void bfs(int n, int src, int ccse) {
    memset(D, -1, n*sizeof(int));
    D[Q[0] = src] = 0;

    int qsz = 1, qi = 0;
    while (qi < qsz) {
        int u = Q[qi++];
        for (int v: adj[u])
            if (S[v] != ccse) {
                S[v]  = ccse;
                D[v] = D[u] + 1;
                Q[qsz++] = v;
            }
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> m;

        for (int i=n+m; i>=0; --i)
            adj[i].clear();

        int N = n;
        for (int i=0, u,v; i<m; ++i) {
            cin >> u >> v;
            adj[u].push_back(N);
            adj[v].push_back(N);
            adj[N].push_back(u);
            adj[N].push_back(v);
            ++N;
        }

        int mn = 10000;
        for (int i=0; i<N; ++i) {
            bfs(N, i, ++ccse);
            int mx = 0;
            for (int j=0; j<n; ++j)
                mx = max(mx, D[j]);

            mn = min(mn, mx);
        }

        cout << "Case #" << cse << ":\n"
             << mn << "\n\n";
    }
}
