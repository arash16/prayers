#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define MAXN 2001

list<int> adj[MAXN];
int pre[MAXN], low[MAXN], pcnt=0;
bool onstack[MAXN];

bool isc(int u) {
    pre[u] = low[u] = pcnt++;
    onstack[u]=1;

    for (int v: adj[u])
        if (pre[v] < 0) {
            if (!isc(v)) return 0;
            low[u] = min(low[u], low[v]);
        }
        else if (onstack[v])
            low[u] = min(low[u], pre[v]);

    return pre[u]!=low[u] || u==0;
}


int main(){
    int n, m, u, v, p;
    while (cin>>n>>m && (n||m)) {
        for (int i=0; i<n; i++) {
            adj[i].clear();
            onstack[i]=0;
            pre[i]=-1;
        }

        for (int i=0; i<m; i++) {
            cin>>u>>v>>p;
            adj[u-1].push_back(v-1);
            if (p==2)
                adj[v-1].push_back(u-1);
        }

        bool result = true;
        for (int i=0; result && i<n; i++)
            if (pre[i] < 0) {
                if (i > 0)
                     result = false;
                else result = isc(i);
            }

        puts(result ? "1" : "0");
    }
}
