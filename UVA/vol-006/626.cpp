/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 626
  Name: Ecosystem
  Problem: https://onlinejudge.org/external/6/626.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[143];
    int coi[143][143], n;
    while (cin >> n) {
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            for (int j=0; j<n; ++j) {
                cin >> coi[i][j];
                if (i == j) coi[i][j] = 0;
                if (coi[i][j])
                    adj[i].push_back(j);
            }
        }

        int cnt = 0;
        for (int i=0; i<n; ++i)
            for (int j: adj[i])
                for (int k: adj[j])
                    if ((j > i ? k > j : k < j) && coi[k][i]) {
                        cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                        ++cnt;
                    }
        cout << "total:" << cnt << "\n\n";
    }
}
