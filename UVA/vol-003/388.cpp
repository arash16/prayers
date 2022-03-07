/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 388
  Name: Galactic Import
  Problem: https://onlinejudge.org/external/3/388.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, dist[27]={};
    while (scanf("%d", &n)==1) {
        vector<int> adj[27];
        int mat[27][27]={}, vals[27];

        for (int i=0; i<n; ++i) {
            int x1, x2;
            char ch, str[100];
            scanf(" %c %d.%d %s", &ch, &x1, &x2, str);
            int u = ch-64;
            vals[u] = x1*100+x2;
            for (int i=0; str[i]; ++i) {
                int v=str[i]=='*'?0:str[i]-64;
                if (!mat[u][v]) {
                    mat[u][v]=1;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        memset(dist+1, -1, 26*sizeof(int));
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u])
                if (dist[v]<0) {
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
        }

        int best=-1, bi;
        for (int i=1; i<27; ++i)
            if (dist[i] > 0) {
                double price=pow(0.95, dist[i]-1) * vals[i];
                if (price > best) {
                    best = price;
                    bi = i;
                }
            }

        printf("Import from %c\n", bi+64);
    }
}
