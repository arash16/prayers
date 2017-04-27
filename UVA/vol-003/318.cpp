#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define INF 1073741824
#define MAXN 501

list<int> adj[MAXN];
int mat[MAXN][MAXN], d[MAXN];

int main(){
    int cse=1, n, m, u, v, w;
    while (cin >> n >> m && (n||m)) {
        for (int i=0; i<n; i++) {
            adj[i].clear();
            for (int j=0; j<n; j++)
                mat[i][j]=INF;
        }

        for (int i=0; i<m; i++) {
            cin>>u>>v>>w; u--; v--;
            if (mat[u][v] == INF) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                mat[u][v] = mat[v][u] = w;
            }
        }

        for (int v=1; v<n; v++)
            d[v] = mat[0][v];

        bool f = true;
        for (int i=1; f && i<n; i++) {
            f = false;
            for (int u=0; u<n; u++)
                for (int v: adj[u])
                    if (d[u] + mat[u][v] < d[v]) {
                        d[v] = d[u] + mat[u][v];
                        f = true;
                    }
        }

        int bi = 0, bj=-1;
        for (int i=1; i<n; i++)
            if (d[i] > d[bi])
                bi = i;

        int bd = d[bi] << 1;
        for (int u=0; u<n; u++)
            for (int v: adj[u]) {
                int dd = mat[u][v] + d[u] + d[v];
                if (dd > bd) {
                    bd = dd;
                    bi = u;
                    bj = v;
                }
            }

        printf("System #%d\nThe last domino falls after %.1f seconds, ", cse++, bd/2.0);
        if (bj < 0)
             printf("at key domino %d.\n\n", bi+1);
        else printf("between key dominoes %d and %d.\n\n", bi+1, bj+1);
    }
}
