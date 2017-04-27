#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

list<int> adj[400];

int color[400];
bool dfs(int u, int c) {
    if (color[u] != -1)
        return color[u] == c;
    color[u] = c;

    for (int v: adj[u])
        if (!dfs(v, 1-c))
            return false;

    return true;
}


int main(){
    int n, u, v;
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            adj[i].clear();
            color[i] = -1;
        }

        int cnt = 0;
        while (cin>>u>>v && (u||v)) {
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
            cnt++;
        }

        if (cnt%3==0 && dfs(0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
