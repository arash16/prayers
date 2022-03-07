/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 677
  Name: All Walks of length "n" from the first node
  Problem: https://onlinejudge.org/external/6/677.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

list<int> adj[20];
int path[20], l, n, x;
bool inside[20], somePrinted;
void dfs(int u, int d) {
    if (d == l) {
        printf("(1");
        for (int i=0; i<l; i++)
            printf(",%d", path[i]+1);
        puts(")"); somePrinted = 1;
        return;
    }
    inside[u] = 1;
    for (int v: adj[u])
        if (!inside[v]) {
            path[d] = v;
            dfs(v, d+1);
        }
    inside[u] = 0;
}

int main(){
    while (scanf("%d%d", &n, &l)==2) {
        for (int i=0; i<n; i++) {
            adj[i].clear();
            for (int j=0; j<n; j++) {
                scanf("%d", &x);
                if (x) adj[i].push_back(j);
            }
        }

        somePrinted = 0; dfs(0, 0);
        if (!somePrinted)
            printf("no walk of length %d\n", l);

        if (scanf("%d", &n)==1 && n==-9999)
            putchar('\n');
    }
}
