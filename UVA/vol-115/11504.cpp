/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11504
  Name: Dominos
  Problem: https://onlinejudge.org/external/115/11504.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
using namespace std;

#define MAXN 100001

int idcnt;
map<int, int> ids;
int readId() {
    int x; cin>>x;
    auto it = ids.find(x);
    if (it == ids.end())
        return ids[x] = idcnt++;
    return it->second;
}


list<int> adj[MAXN];
bool seen[MAXN];
int order[MAXN], ocnt=0;
void topo(int u) {
    seen[u] = true;
    for (int v: adj[u])
        if (!seen[v])
            topo(v);

    order[ocnt++] = u;
}

void dfs(int u) {
    seen[u] = true;
    for (int v: adj[u])
        if (!seen[v])
            dfs(v);
}

int main(){
    int T, n, m, u, v;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            seen[i]=0;
        }

        idcnt=0;
        ids.clear();
        for (int i=0; i<m; i++) {
            int u = readId(),
                v = readId();
            adj[u].push_back(v);
        }

        ocnt=0;
        for (int i=0; i<n; i++)
            if (!seen[i])
                topo(i);

        int result = 0;
        memset(seen, 0, sizeof(bool)*n);
        for (int i=ocnt-1; i>=0; i--) {
            int u = order[i];
            if (!seen[u]) {
                result++;
                dfs(u);
            }
        }

        cout << result << endl;
    }
}
