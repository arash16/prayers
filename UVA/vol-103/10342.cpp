/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10342
  Name: Always Late
  Problem: https://onlinejudge.org/external/103/10342.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

struct Edge {
    int u, w;
    Edge(int u, int w):u(u),w(w){}
    bool operator < (const Edge &o) const { return w > o.w; }
};

int D1[143][143], D2[143][143], n;
vector<Edge> adj[143];
void dijkstra(int src, int D1[], int D2[]) {
    for (int i=0; i<n; ++i)
        D1[i] = D2[i] = INF;

    priority_queue<Edge> q;
    q.push(Edge(src, D1[src]=0));
    while (!q.empty()) {
        Edge s = q.top(); q.pop();
        if (s.w > D2[s.u]) continue;

        for (Edge e: adj[s.u]) {
            Edge t(e.u, s.w + e.w);
            if (D2[t.u] > t.w && t.w != D1[t.u]) {
                D2[t.u] = t.w;
                if (t.w < D1[t.u])
                    swap(D1[t.u], D2[t.u]);

                q.push(t);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m, w;
    bool seen[143];
    for (int cse=1; cin >> n >> m; ++cse) {
        cout << "Set #" << cse << '\n';

        for (int i=0; i<n; ++i)
            adj[i].clear(),
            seen[i] = 0;

        for (int i=0, u, v; i<m; ++i) {
            cin >> u >> v >> w;
            adj[u].push_back(Edge(v, w));
            adj[v].push_back(Edge(u, w));
        }

        cin >> m;
        for (int u,v; m--; ) {
            cin >> u >> v;
            if (!seen[u])
                dijkstra(u, D1[u], D2[u]);

            if (D2[u][v] == INF) cout << "?\n";
            else cout << D2[u][v] << '\n';
        }
    }
}
