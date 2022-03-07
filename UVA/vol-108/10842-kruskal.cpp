/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10842
  Name: Traffic Flow
  Problem: https://onlinejudge.org/external/108/10842.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAXN 117
char gid[MAXN];
char find(char u) {
    return gid[u]==u ? u : gid[u]=find(gid[u]);
}
void join(char u, char v) { gid[find(u)] = find(v); }


struct Edge {
    short w;
    char u, v;
    Edge(char u, char v, short w):u(u),v(v),w(w){}
    bool operator < (const Edge &e) const { return w < e.w; }
};

int main(){
    int T, n, m, u, v, w;
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; ++i)
            gid[i] = i;

        priority_queue<Edge> q;
        for (int i=0; i<m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            q.push(Edge(u, v, w));
        }


        int mn = 2147383647;
        for (int i=1; i<n; ) {
            Edge e = q.top(); q.pop();
            if (find(e.u) != find(e.v)) {
                join(e.u, e.v);
                mn = e.w;
                ++i;
            }
        }
        printf("Case #%d: %d\n", cse, mn);
    }
}
