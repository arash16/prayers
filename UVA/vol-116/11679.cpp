/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11679
  Name: Sub-prime
  Problem: https://onlinejudge.org/external/116/11679.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int R[23], n, m;
    while (cin >> n >> m && (n||m)) {
        for (int i=1; i<=n; ++i)
            cin >> R[i];

        for (int i=0, u,v,d; i<m; ++i) {
            cin >> u >> v >> d;
            R[u] -= d;
            R[v] += d;
        }

        bool possible = 1;
        for (int i=1; possible && i<=n; ++i)
            possible &= R[i] >= 0;

        cout << (possible ? "S\n" : "N\n");
    }
}
