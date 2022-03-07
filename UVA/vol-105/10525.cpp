/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10525
  Name: New to Bangladesh?
  Problem: https://onlinejudge.org/external/105/10525.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m, u, v,
        D[143][143], C[143][143];
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i) {
            D[i][i] = C[i][i] = 0;
            for (int j=0; j<i; ++j)
                D[i][j]=D[j][i]=C[i][j]=C[j][i] = INF;
        }

        for (int i=0, t,d; i<m; ++i) {
            cin >> u >> v >> t >> d;--u;--v;
            if (t < C[u][v] || (t==C[u][v] && d < D[u][v])) {
                D[u][v] = D[v][u] = d;
                C[u][v] = C[v][u] = t;
            }
        }

        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
            if (i!=k && D[i][k] != INF)
                for (int j=0; j<n; ++j)
                if (j!=k && D[k][j] !=INF) {
                    int d = D[i][k] + D[k][j],
                        t = C[i][k] + C[k][j];

                    if (t < C[i][j] || (t==C[i][j] && d < D[i][j])) {
                        D[i][j] = d;
                        C[i][j] = t;
                    }
                }

        cin >> m;
        while (m--) {
            cin >> u >> v; --u; --v;
            if (D[u][v] == INF) cout << "No Path.\n";
            else cout << "Distance and time to reach destination is " << D[u][v] << " & " << C[u][v] << ".\n";
        }
        if (T) cout << endl;
    }
}
