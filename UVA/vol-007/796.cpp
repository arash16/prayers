/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 796
  Name: Critical Links
  Problem: https://onlinejudge.org/external/7/796.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;


#define INF 1073741824
#define MAXN 1000
list<int> adj[MAXN];
int low[MAXN], depth[MAXN], parent[MAXN], visited[MAXN];

#define Pair pair<int, int>
vector<Pair > arts;

void findAPs(int u, int d) {
    visited[u] = 1;
    low[u] = depth[u] = d;

    for (int v: adj[u])
        if (!visited[v]) {
            parent[v] = u;
            findAPs(v, d+1);
            if (low[v] >= d+1)
                arts.push_back(Pair(min(u, v), max(u, v)));
            else
                low[u] = min(low[u], low[v]);
        }
        else if (v != parent[u])
            low[u] = min(low[u], depth[v]);
}

int main(){
    int n;
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            int u, v, m;
            scanf("%d (%d)", &u, &m);
            adj[u].clear();
            visited[u] = 0;
            for (int j=0; j<m; j++) {
                cin>>v;
                adj[u].push_back(v);
            }
        }

        arts.clear();
        for (int i=0; i<n; i++)
            if (!visited[i])
                findAPs(i, 0);


        sort(arts.begin(), arts.end());
        printf("%lu critical links\n", arts.size());
        for (auto &ap: arts)
            printf("%d - %d\n", ap.first, ap.second);
        putchar('\n');
    }
}
