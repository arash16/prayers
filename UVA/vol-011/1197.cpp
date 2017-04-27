#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 30017

short gid[MAXN], gcn[MAXN], tmp[MAXN];
short find(short u) {
    if (gid[u]==u) return u;

    int i=0;
    for (; u!=gid[u]; u=gid[u])
        tmp[i++] = u;

    for (int j=0; j<i; ++j)
        gid[tmp[j]] = u;

    return u;
}
void join(int u, int v) {
    int ug = find(u), vg = find(v);
    if (ug != vg) {
        gcn[vg] += gcn[ug];
        gid[ug] = vg;
    }
}


int main(){
    int n, m, c, x, y;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; ++i) {
            gid[i] = i;
            gcn[i] = 1;
        }

        for (int i=0; i<m; ++i) {
            scanf("%d", &c);
            if (c > 0) {
                scanf("%d", &x);
                for (int j=1; j<c; ++j) {
                    scanf("%d", &y);
                    join(x, y);
                }
            }
        }

        printf("%d\n", gcn[find(0)]);
    }
}
