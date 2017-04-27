#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;


#define MAXN 1001
int adj[MAXN][MAXN], deg[MAXN], d[MAXN];
int tr[MAXN][MAXN];

int main(){
    int n, m, u, v;
    while (cin>>n>>m && (n||m)) {
        for (int i=0; i<n; i++)
            deg[i] = 0;

        for (int i=0; i<m; i++) {
            cin >> u >> v;
            adj[u-1][deg[u-1]++] = v-1;
            adj[v-1][deg[v-1]++] = u-1;
        }

        bool p=true;
        int s=-1, t=-1;
        for (int i=0; p && i<n && t<0; i++)
            if (deg[i]<=1) {
                p=false;
            }
            else if (deg[i]%2) {
                if (s<0) s=i;
                else t=i;
            }


        if (!p) cout << "Poor Koorosh\n";
        else if (t==-1) cout<<"0\n";
        else {
            for (int i=0; i<n; i++)
                d[i]=-1;

            queue<int> Q;
            Q.push(s); d[s]=0;

            while (!Q.empty()) {
                u = Q.front(); Q.pop();
                if (u == t) break;

                for (int i=0; i<deg[u]; i++) {
                    v = adj[u][i];
                    if (deg[v] != 2 && d[v] == -1) {
                        d[v] = d[u] + 1;
                        Q.push(v);
                    }
                }
            }

            if (u == t)
                cout << d[t] << endl;
            else
                cout << "Poor Koorosh\n";
        }
    }
}
