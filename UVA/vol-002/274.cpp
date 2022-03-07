/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 274
  Name: Cat and Mouse
  Problem: https://onlinejudge.org/external/2/274.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int n, hc, hm;
void dfs(int u, vector<int> adj[], bool seen[]) {
    seen[u] = true;
    for (int v: adj[u])
        if (!seen[v])
            dfs(v, adj, seen);
}

vector<int> adjC[143], adjM[143], adjMr[143];
bool cseen[143], mseen[143], dseen[143];

bool dfsf(int u) {
    if (mseen[u] && u!=hm)
        return true;

    dseen[u] = true;
    for (int v: adjMr[u])
        if (!cseen[v] && !dseen[v] && dfsf(v))
            return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, u, v;
    cin >> T;
    while (T--) {
        cin >> n >> hc >> hm; --hc; --hm;
        for (int i=0; i<n; ++i) {
            adjC[i].clear();
            adjM[i].clear();
            adjMr[i].clear();
        }

        while (cin>>u>>v && u>0)
            adjC[u-1].push_back(v-1);

        while (cin.ignore(100,'\n') && cin.peek()!='\n')
            if (cin >> u >> v) {
                adjM[u-1].push_back(v-1);
                adjMr[v-1].push_back(u-1);
            }

        memset(cseen, 0, n);
        dfs(hc, adjC, cseen);

        memset(mseen, 0, n);
        dfs(hm, adjM, mseen);

        bool f1 = false;
        for (int i=0; !f1 && i<n; ++i)
            if (mseen[i] && cseen[i])
                f1 = true;

        bool f2 = false;
        if (!cseen[hm]) {
            memset(dseen, 0, n);
            f2 = dfsf(hm);
        }

        cout << (f1 ? "Y " : "N ") << (f2 ? "Y\n" : "N\n");
        if (T) cout << endl;
    }
}
