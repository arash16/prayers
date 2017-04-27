#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <map>
using namespace std;

#define MAXX 1073741824

int did[202];
int find(int x) {
    if (did[x] == x) return x;
    return did[x] = find(did[x]);
}
void join(int u, int v) {
    did[find(u)] = find(v);
}

// -----------------------------------------------


int cnt;
map<string, int> ids;
int getId(char *w) {
    int res = ids[w];
    if (!res) res = ids[w] = ++cnt;
    return res;
}

int readId() {
    char w[100];
    cin>>w;
    return getId(w);
}

// ----------------------------------------------------

struct Edge {
    int u, v, d;
    Edge(int u, int v, int d): u(u), v(v), d(d) {}
    bool operator < (const Edge& e) const {
        return d < e.d;
    }
};


list<int> adj[202];
int dist[202][202];
int seen[202];
int dfs(int u, int v) {
    if (u == v) return 20000;
    if (seen[u]) return -1;
    seen[u] = 1;

    int mn = MAXX;
    for (int i: adj[u]) {
        int r = dfs(i, v);
        if (r>=0)
            mn = min(mn, min(r, dist[u][i]));
    }

    seen[u] = 0;
    return mn == MAXX ? -1 : mn;
}


int main(){
    int cse=1, u, v, d, n, m;
    char w[100];
    while (cin>>n>>m && (n||m)) {
        for (int i=0; i<=n; i++) {
            adj[i].clear();
            did[i]=i;
        }

        priority_queue<Edge> q;
        ids.clear();
        cnt=0;

        for (int i=0; i<m; i++) {
            u = readId();
            v = readId();
            cin >> d;
            q.push(Edge(u, v, d));
        }
        u = readId();
        v = readId();



        int nn = 0;
        while (nn < n-1 && !q.empty()) {
            Edge e = q.top(); q.pop();
            if (find(e.u) != find(e.v)) {
                nn++;
                join(e.u, e.v);
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
                dist[e.u][e.v] = dist[e.v][e.u] = e.d;
            }
        }

        printf("Scenario #%d\n%d tons\n\n", cse++, dfs(u, v));
    }
}
