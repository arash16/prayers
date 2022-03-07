/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 534
  Name: Frogger
  Problem: https://onlinejudge.org/external/5/534.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAXN 202
int X[MAXN], Y[MAXN];

struct Edge {
    int u, v;
    double dist;
    Edge(int u, int v): u(u), v(v) {
        double x = X[u] - X[v];
        double y = Y[u] - Y[v];
        dist = sqrt(x*x + y*y);
    }

    bool operator < (const Edge &e) const {
        return dist > e.dist;
    }
};

// ---------------------------------------------------------

int ids[MAXN];
int find(int u) {
    if (ids[u] == u) return u;
    return ids[u] = find(ids[u]);
}

void join(int u, int v) {
    ids[find(u)] = find(v);
}

// ---------------------------------------------------------


vector<int> adj[MAXN];
double mp[MAXN][MAXN];
int seen[MAXN];

double dfs(int v, int w) {
    if (v==w) return 0;
    if (seen[v]) return -1;
    seen[v] = 1;

    double mx = -1;
    for (int i: adj[v]) {
        double r = dfs(i, w);
        if (r >= 0)
            mx = max(mx, max(r, mp[v][i]));
    }

    seen[v] = 0;
    return mx;
}

// ---------------------------------------------------------

int main(){
    int cse=1, n;
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            cin>>X[i]>>Y[i];
            adj[i].clear();
            ids[i] = i;
        }

        priority_queue<Edge> eds;

        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                eds.push(Edge(i, j));

        int cnt = 0;
        while (cnt < n-1) {
            Edge e = eds.top(); eds.pop();
            if (find(e.u) != find(e.v)) {
                join(e.u, e.v);
                cnt++;

                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
                mp[e.u][e.v] = mp[e.v][e.u] = e.dist;
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", cse++, dfs(0, 1));
    }
}
