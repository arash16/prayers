/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11228
  Name: Transportation system.
  Problem: https://onlinejudge.org/external/112/11228.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int uds[1001];
int find(int u) {
    return u==uds[u] ? u : uds[u] = find(uds[u]);
}
void join(int u, int v) {
    uds[find(u)] = find(v);
}

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u),v(v),w(w){}
    bool operator < (const Edge& e) const {
        return w > e.w;
    }
};

int X[1001], Y[1001];
int dist2(int i, int j) {
    int xx = X[i] - X[j],
        yy = Y[i] - Y[j];
    return xx*xx + yy*yy;
}

int main(){
    int T, n, r;
    scanf("%d", &T);
    for (int cse=1; cse<=T; cse++) {
        scanf("%d%d", &n, &r); r*=r;

        priority_queue<Edge> q1, q2;
        for (int i=0; i<n; i++) {
            uds[i] = i;
            scanf("%d%d", X+i, Y+i);
            for (int j=0; j<i; j++) {
                int w = dist2(i, j);
                if (w <= r)
                     q1.push(Edge(j, i, w));
                else q2.push(Edge(j, i, w));
            }
        }

        int cnt = 0;
        double extc=0, exts=0;
        while (cnt<n-1 && !q1.empty()) {
            Edge e = q1.top(); q1.pop();
            if (find(e.u) != find(e.v)) {
                extc += sqrt(e.w);
                join(e.u, e.v);
                cnt++;
            }
        }

        int scnt = n-cnt;
        while (cnt < n-1) {
            Edge e = q2.top(); q2.pop();
            if (find(e.u) != find(e.v)) {
                exts += sqrt(e.w);
                join(e.u, e.v);
                cnt++;
            }
        }

        printf("Case #%d: %d %.0lf %.0lf\n", cse, scnt, extc, exts);
    }
}
