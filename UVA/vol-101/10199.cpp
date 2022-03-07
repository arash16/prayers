/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10199
  Name: Tourist Guide
  Problem: https://onlinejudge.org/external/101/10199.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

#define MAXL 50
#define MAXN 101

string names[MAXN];
map<string, int> ids;
bool comp(int u, int v) { return names[u] < names[v]; }

list<int> adj[MAXN];
int parent[MAXN], depth[MAXN], low[MAXN];

vector<int> arts;
void dfs(int u, int d) {
    low[u] = depth[u] = d;
    bool isArt = false;
    int childs = 0;

    for (int v: adj[u])
        if (depth[v] == -1) {
            parent[v] = u;
            dfs(v, d+1);
            childs++;
            if (low[v] >= d)
                isArt = true;
            else if (low[v] < low[u])
                low[u] = low[v];
        }
        else if (v != parent[u])
            low[u] = min(low[u], depth[v]);

    if ((d==0 && childs>1) || (d!=0 && isArt))
        arts.push_back(u);
}


int main(){
    int cse=1, n, m;
    char w1[MAXL], w2[MAXL];
    while (cin>>n && n) {
        ids.clear();
        for (int i=0; i<n; i++) {
            cin>>w1;
            ids[w1] = i;
            names[i] = w1;
            depth[i] = -1;
            adj[i].clear();
        }

        cin>>m;
        for (int i=0; i<m; i++) {
            cin>>w1>>w2;
            int u=ids[w1], v=ids[w2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        arts.clear();
        for (int i=0; i<n; i++)
            if (depth[i] == -1)
                dfs(i, 0);

        sort(arts.begin(), arts.end(), comp);

        if (cse > 1) putchar('\n');
        printf("City map #%d: %lu camera(s) found\n", cse++, arts.size());
        for (int u: arts)
            cout << names[u] << endl;
    }
}
