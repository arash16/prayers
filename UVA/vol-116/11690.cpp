#include <stdio.h>
#include <iostream>
using namespace std;


int gid[100001], owes[100001];
int find(int u) {
    return u==gid[u] ? u : gid[u]=find(gid[u]);
}

void join(int u, int v) {
    u=find(u); v=find(v);
    if (u != v) {
        owes[v] += owes[u];
        gid[u] = v;
    }
}


int main(){
    int T, n, m, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++) {
            scanf("%d", owes + i);
            gid[i] = i;
        }

        for (int i=0; i<m; i++) {
            scanf("%d%d", &u, &v);
            join(u, v);
        }


        bool impo = 0;
        for (int i=0; !impo && i<n; i++)
            if (i==gid[i] && owes[i])
                impo = 1;

        puts(!impo ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
