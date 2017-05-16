#include <bits/stdc++.h>
using namespace std;

int gid[55000];
int find(int u) { return gid[u]<0 ? u : gid[u]=find(gid[u]); }
bool join(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        if (gid[v] < gid[u])
            swap(u, v);

        gid[u] += gid[v];
        gid[v] = u;
        return 1;
    }
    return 0;
}

struct Edge {
    int u, v, w;
    bool operator < (const Edge &o) const { return w < o.w; }
}
E[100143];

#define ff first
#define ss second
typedef pair<int, int> Pair;
vector<Pair> adj[55000];


int par[55000], parw[55000];
void dfs(int u) {
    int upar = par[u];
    for (Pair v: adj[u])
        if (v.ff != upar) {
            parw[v.ff] = v.ss;
            par[v.ff] = u;
            dfs(v.ff);
        }
}

int seen[55000], mxx[55000], cse;
int LCA(int u, int v) {
    int mx = mxx[u] = 0;
    while (u) {
        seen[u] = cse;
        mx = mxx[par[u]] = max(mx, parw[u]);
        u = par[u];
    }

    mx = 0;
    while (v) {
        if (seen[v] == cse)
            return max(mx, mxx[v]);

        mx = max(mx, parw[v]);
        v = par[v];
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    bool frst = 1;
    while (cin >> n >> m) {
        if (frst) frst = 0;
        else cout << '\n';

        for (int i=0; i<=n; ++i) {
            adj[i].clear();
            gid[i] = -1;
        }

        for (int i=0; i<m; ++i)
            cin >> E[i].u >> E[i].v >> E[i].w;
        sort(E, E+m);

        for (int i=0; i<m; ++i)
            if (join(E[i].u, E[i].v)) {
                adj[E[i].u].push_back(Pair(E[i].v, E[i].w));
                adj[E[i].v].push_back(Pair(E[i].u, E[i].w));
            }

        par[1] = 0;
        dfs(1);

        cin >> m;
        while (m--) {
            int u, v; ++cse;
            cin >> u >> v;
            cout << LCA(u, v) << '\n';
        }
    }
}
