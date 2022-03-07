/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10816
  Name: Travel in Desert
  Problem: https://onlinejudge.org/external/108/10816.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int u, r, d;
    Edge(int u, int r, int d):u(u),r(r),d(d){}
};

struct State {
    int u, d;
    State(int u, int d):u(u),d(d){}
    bool operator < (const State &o) const { return d > o.d; }
};


int D[143], R[143], P[143], PP[143], n, m, src, dst;
vector<Edge> adj[143];
int dijkstra1() {
    for (int i=1; i<=n; ++i)
        D[i] = (int)1e9;

    priority_queue<State> q;
    q.push(State(src, D[src]=0));
    while (!q.empty()) {
        State s = q.top(); q.pop();
        if (s.d != D[s.u]) continue;
        if (s.u == dst) return s.d;

        for (Edge e: adj[s.u]) {
            State t(e.u, max(s.d, e.r));
            if (D[e.u] > t.d) {
                D[e.u] = t.d;
                q.push(t);
            }
        }
    }
    return 0;
}

void dijkstra2(int mxd) {
    for (int i=1; i<=n; ++i)
        D[i] = (int)1e9;

    priority_queue<State> q;
    q.push(State(src, D[src]=0));
    while (!q.empty()) {
        State s = q.top(); q.pop();
        if (s.d != D[s.u]) continue;
        if (s.u == dst) {
            int sz = 0;
            for (int v=s.u; v!=src; v=P[v])
                PP[sz++] = v;
            cout << src;
            while (--sz >= 0)
                cout << ' ' << PP[sz];
            cout << '\n';

            cout << s.d/10.0 << ' ' << mxd/10.0 << '\n';
            return;
        }

        for (Edge e: adj[s.u]) if (e.r <= mxd) {
            State t(e.u, s.d + e.d);
            if (t.d < D[e.u]) {
                D[e.u] = t.d;
                P[e.u] = s.u;
                q.push(t);
            }
        }
    }
}

char BUF[1000000], ch;
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(1);

    while (cin >> n >> m >> src >> dst) {
        for (int i=1; i<=n; ++i)
            R[i] = D[i] = (int)1e9,
            adj[i].clear();

        for (int i=0, u,v,r1,r2,d1,d2; i<m; ++i) {
            cin >> u >> v >> r1>>ch>>r2 >> d1>>ch>>d2;
            adj[u].push_back(Edge(v, r1*10+r2, d1*10+d2));
            adj[v].push_back(Edge(u, r1*10+r2, d1*10+d2));
        }

        dijkstra2(dijkstra1());
    }
}
