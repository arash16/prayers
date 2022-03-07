/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10308
  Name: Roads in the North
  Problem: https://onlinejudge.org/external/103/10308.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int u, d;
    Edge(int u, int d):u(u),d(d){}
};
vector<Edge> adj[10043];

int seen[10043], cse;
Edge dfs(int u) {
    seen[u] = cse;

    Edge r(u, 0);
    for (Edge &e: adj[u])
        if (seen[e.u] != cse) {
            Edge rr = dfs(e.u);
            if ((rr.d += e.d) > r.d)
                r = rr;
        }
    return r;
}

int main() {
    for (cse=1; ; ++cse) {
        int n = 0;
        for (int u,v,d; cin.peek()!='\n' && cin >> u >> v >> d; cin.ignore(100,'\n')) {
            int nn = max(n, max(u--, v--));
            for (; n <= nn; ++n)
                adj[n].clear();

            adj[u].push_back(Edge(v, d));
            adj[v].push_back(Edge(u, d));
        }
        if (!n) break;

        int u = dfs(0).u; ++cse;
        cout << dfs(u).d << endl;

        cin.ignore(100,'\n');
    }
}
