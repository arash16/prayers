#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

struct State {
    int u, d;
    State(int u, int d):u(u),d(d){}
    bool operator < (const State& e) const { return d>e.d; }
};

int W[343][343], D[343];
vector<int> adj[343];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, c, k;
    for (int cse=1; cin>>n>>m>>c>>k && (n||m||c||k); ++cse) {
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            D[i] = INF;
        }

        for (int i=0, u,v,d; i<m; ++i) {
            cin >> u >> v >> d;
            W[u][v] = W[v][u] = d;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        D[c-1] = 0;
        for (int i=c-2; i>=0; --i)
            D[i] = D[i+1] + W[i][i+1];
        D[c-1] = INF;

        priority_queue<State> q;
        q.push(State(k, D[k]=0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (s.d != D[s.u]) continue;
            if (s.u == c-1) break;

            for (int v: adj[s.u]) {
                int dd = s.d + W[s.u][v];
                if (v < c - 1) {
                    dd += D[v];
                    v = c - 1;
                }
                if (dd < D[v])
                    q.push(State(v, D[v]=dd));
            }
        }
        cout << D[c-1] << endl;
    }
}
