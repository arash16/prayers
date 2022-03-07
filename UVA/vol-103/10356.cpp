/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10356
  Name: Rough Roads
  Problem: https://onlinejudge.org/external/103/10356.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


struct UD {
    int u, d, l;
    UD(int u, int d, int l=0):u(u),d(d),l(l){}
    bool operator < (const UD& o) const { return d > o.d; }
};
vector<UD> adj[10043];
int D[10043][2];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    int n, m, u, v, d;
    for (int cse=1; cin >> n >> m; ++cse) {
        cout << "Set #" << cse << endl;

        for (int i=0; i<n; ++i) {
            adj[i].clear();
            D[i][0]=D[i][1]=INF;
        }

        for (int i=0; i<m; ++i) {
            cin >> u >> v >> d;
            adj[u].push_back(UD(v, d));
            adj[v].push_back(UD(u, d));
        }

        priority_queue<UD> q;
        q.push(UD(0, D[0][0]=0));
        while (!q.empty()) {
            UD ud = q.top(); q.pop();
            if (ud.d != D[ud.u][ud.l&1]) continue;
            if (ud.u==n-1 && !(ud.l&1)) {
                cout << ud.d << endl;
                goto fin;
            }


            for (UD &vd: adj[ud.u]) {
                UD t(vd.u, ud.d + vd.d, ud.l+1);
                if (t.d < D[t.u][t.l&1]) {
                    D[t.u][t.l&1] = t.d;
                    q.push(t);
                }
            }
        }
        cout << "?\n";
        fin:;
    }
}
