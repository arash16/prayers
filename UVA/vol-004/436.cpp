/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 436
  Name: Arbitrage (II)
  Problem: https://onlinejudge.org/external/4/436.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s1, s2;
    double M[34][34], d;
    for (int cse=1, n,m; cin >> n && n; ++cse) {
        unordered_map<string, int> ids;
        for (int i=0; i<n; ++i) {
            cin >> s1;
            ids[s1] = i;
            M[i][i] = 1;
            for (int j=0; j<i; ++j)
                M[i][j] = M[j][i] = 0;
        }

        cin >> m;
        while (m--) {
            cin >> s1 >> d >> s2;
            int u = ids[s1],
                v = ids[s2];

            M[u][v] = d;
        }

        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
            if (M[i][k]>0)
                for (int j=0; j<n; ++j)
                if (M[k][j]>0)
                    M[i][j] = max(M[i][j], M[i][k] * M[k][j]);

        bool f = false;
        for (int k=0; !f && k<n; ++k)
            if (M[k][k] > 1 + 1e-5)
                f = true;

        cout << "Case " << cse << ": " << (f ? "Yes\n" : "No\n");
    }
}
