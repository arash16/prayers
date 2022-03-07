/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10278
  Name: Fire Station
  Problem: https://onlinejudge.org/external/102/10278.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

int M[555][555], D[555], E[555], n;
vector<int> adj[555];

struct UD {
    int u, d;
    UD(int u, int d):u(u),d(d){}
    bool operator < (const UD& o) const { return d > o.d; }
};


int dijkstra(priority_queue<UD> &q, int D[]) {
    while (!q.empty()) {
        UD ud = q.top(); q.pop();
        int u = ud.u;
        if (D[u] == ud.d)
        for (int v: adj[u])
            if (D[u]+M[u][v] < D[v]) {
                D[v] = D[u] + M[u][v];
                q.push(UD(v, D[v]));
            }
    }

    int mxd=0;
    for (int u=0; u<n; ++u)
        mxd = max(mxd, D[u]);

    return mxd;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int f, T; cin>>T;
    while (T--) {
        cin >> f >> n;
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            for (int j=0; j<n; ++j)
                M[i][j] = INF;
            D[i] = INF;
        }

        priority_queue<UD> q;
        for (int i=0, s; i<f; ++i) {
            cin >> s; --s;
            q.push(UD(s, D[s]=0));
        }

        for (int u, v, d; cin.ignore(1000, '\n') && cin.peek()!='\n'; )
            if (cin>>u>>v>>d) {
                if (M[--u][--v] == INF) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                M[u][v] = M[v][u] = min(M[u][v], d);
            }

        int mxd = dijkstra(q, D),
            mxu = 0;

        for (int u=0; u<n; ++u) if (D[u]) {
            memcpy(E, D, n*sizeof(int));
            priority_queue<UD> qq;
            qq.push(UD(u, E[u]=0));

            int dd = dijkstra(qq, E);
            if (dd < mxd) {
                mxd = dd;
                mxu = u;
            }
        }

        cout << mxu+1 << endl;
        if (T) cout << endl;
    }
}
