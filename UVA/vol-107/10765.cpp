#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

#define MAXN 10001
list<int> adj[MAXN];
int low[MAXN], depth[MAXN], par[MAXN], pigv[MAXN], ord[MAXN];
bool comp(int i, int j) { return pigv[i] > pigv[j]; }

void dfs(int u, int d) {
    low[u] = depth[u] = d;
    int childs = 0,
        pigval = 0;

    for (int v: adj[u])
        if (par[v] < 0) {
            childs++;
            par[v] = u;
            dfs(v, d+1);
            if (low[v] >= depth[u])
                pigval++;
            else if (low[v] < low[u])
                low[u] = low[v];
        }
        else if (v != par[u])
            low[u] = min(low[u], depth[v]);

    pigv[u] = !d ? childs-1 : pigval;
}


int main(){
    int n, b, u, v;
    while (scanf("%d%d", &n, &b)==2 && (n||b)) {
        for (int i=0; i<n; i++) {
            ord[i] = i;
            par[i] = -1;
            pigv[i] = 0;
            adj[i].clear();
        }
        while (scanf("%d%d", &u, &v)==2 && (u>=0 && v>=0)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        for (int i=0; i<n; i++)
            if (par[i] == -1) {
                par[i] = i;
                dfs(i, 0);
                cnt++;
            }

        stable_sort(ord, ord+n, comp);
        for (int i=0; i<b; i++)
            printf("%d %d\n", ord[i], cnt+pigv[ord[i]]);
        putchar('\n');
    }
}
