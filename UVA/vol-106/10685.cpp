/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10685
  Name: Nature
  Problem: https://onlinejudge.org/external/106/10685.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int gid[6000], gcn[6000];
int find(int u) {
    return u==gid[u] ? u : gid[u]=find(gid[u]);
}
int join(int u, int v) {
    u=find(u); v=find(v);
    if (u != v) {
        gid[u] = v;
        gcn[v] += gcn[u];
    }
    return gcn[v];
}

int main() {
    int n, m;
    char w1[100], w2[100];
    while (scanf("%d %d", &n, &m)==2 && (n||m)) {
        map<string, int> ids;
        for (int i=0; i<n; i++) {
            scanf("%s", w1);
            ids[w1] = i;
            gid[i] = i;
            gcn[i] = 1;
        }

        int mxc=1;
        for (int i=0; i<m; i++) {
            scanf("%s %s", w1, w2);
            int u=ids[w1], v=ids[w2];
            mxc = max(mxc, join(u, v));
        }
        printf("%d\n", mxc);
    }
}
