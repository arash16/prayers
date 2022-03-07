/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 775
  Name: Hamiltonian Cycle
  Problem: https://onlinejudge.org/external/7/775.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int P[286], n;
vector<int> adj[286];
bool mat[286][286], chosed[286];
bool bt(int idx, int u, int ce1) {
    if (!ce1) return 0;
    P[idx] = u;
    if (idx == n-1) {
        for (int i=0; i<n; ++i)
            cout << P[i] << ' ';
        cout << "1\n";
        return 1;
    }

    chosed[u] = 1;
    for (int v: adj[u])
        if (!chosed[v])
            if (bt(idx+1, v, ce1-mat[u][1]))
                return 1;
    chosed[u] = 0;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int u, v;
    string str;
    while (cin >> n) {
        cin.ignore(100, '\n');
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        memset(mat, 0, sizeof(mat));
        while (cin.peek()!='%' && cin >> u >> v) {
            if (!mat[u][v]) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                mat[u][v] = mat[v][u] = 1;
            }
            cin.ignore(100, '\n');
        }
        cin.ignore(100, '\n');

        int ce1=0;
        for (int i=1; i<=n; ++i)
            ce1 += mat[i][1];

        memset(chosed, 0, sizeof(chosed));
        if (!bt(0, 1, ce1)) cout << "N\n";
    }
}
