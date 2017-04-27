#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

#define INF 1073741824
#define MAXN 760
short gid[MAXN];
short find(short u) {
    return gid[u]==u ? u : gid[u]=find(gid[u]);
}
void join(short u, short v) { gid[find(u)] = find(v); }


int X[MAXN], Y[MAXN];

struct Edge {
    int w;
    short u, v;
    Edge(){}
    Edge(short u, short v):u(u),v(v) {
        int xx = X[u]-X[v], yy = Y[u]-Y[v];
        w = xx*xx + yy*yy;
    }
    bool operator < (const Edge &e) const { return w > e.w; }
};

Edge closest[MAXN];
int main(){
    int T, n, m, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d%d", X+i, Y+i);
            closest[i].u = closest[i].v = -1;
            gid[i] = i;
        }

        int c = 0;
        scanf("%d", &m);
        for (int i=0; i<m; i++) {
            scanf("%d%d", &u, &v);
            if (find(u-1) != find(v-1)) {
                join(u-1, v-1);
                ++c;
            }
        }

        if (c == n-1) puts("No new highways need");
        else {
            priority_queue<Edge> q;
            for (int i=0; i<n; ++i) {
                int iid = find(i);
                for (int j=i+1; j<n; ++j) {
                    int jid = find(j);
                    if (iid != jid) {
                        Edge ne(i, j);
                        if (closest[jid].u!=i || ne.w < closest[jid].w)
                            closest[jid] = ne;
                    }
                }

                for (int j=0; j<n; j++)
                    if (closest[j].u == i)
                        q.push(closest[j]);
            }

            while (c < n-1) {
                Edge e = q.top(); q.pop();
                if (find(e.u) != find(e.v)) {
                    printf("%d %d\n", e.u+1, e.v+1);
                    join(e.u, e.v);
                    ++c;
                }
            }
        }
        if (T) putchar('\n');
    }
}
