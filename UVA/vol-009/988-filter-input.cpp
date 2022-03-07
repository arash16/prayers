/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 988
  Name: Many Paths, One Destination
  Problem: https://onlinejudge.org/external/9/988.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[143];
    unsigned long long C[143];
    int n;
    bool frst = 1;
    while (cin >> n) {
        for (int i=0, sz; i<n; ++i) {
            C[i] = 0;
            cin >> sz;
            adj[i].resize(sz);
            for (int j=0; j<sz; ++j)
                cin >> adj[i][j];

            if (!sz) adj[i].push_back(n);
        }

        C[0] = 1; C[n] = 0;
        for (int i=0; i<n; ++i)
            for (int v: adj[i])
                C[v] += C[i];

        if (C[n] <= (1<<30)) {
            cout << n << "\n";
            for (int i=0; i<n; ++i)
                if (adj[i][0]==n) cout << "0\n";
                else {
                    cout << adj[i].size();
                    for (int v: adj[i])
                        cout << ' ' << v;
                    cout << "\n";
                }
            cout << "\n";
        }
    }
}
