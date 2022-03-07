/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11770
  Name: Lighting Away
  Problem: https://onlinejudge.org/external/117/11770.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;

#define MAXN 10001

list<int> adj[MAXN];

bool seen[MAXN];
int order[MAXN], ocnt;
void topo(int u) {
    seen[u]=1;
    for (int v: adj[u])
        if (!seen[v])
            topo(v);

    if (ocnt>0)
        order[--ocnt] = u;
}


int main(){
    int T, n, m, u, v;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            seen[i]=0;
        }
        for (int i=0; i<m; i++) {
            cin>>u>>v;
            adj[u-1].push_back(v-1);
        }

        ocnt = n;
        for (int i=0; i<n; i++)
            if (!seen[i])
                topo(i);

        int result = 0;
        memset(seen, 0, n*sizeof(bool));
        for (int i=0; i<n; i++) {
            int u=order[i];
            if (!seen[u]) {
                result++;
                topo(u);
            }
        }

        printf("Case %d: %d\n", cse, result);
    }
}
