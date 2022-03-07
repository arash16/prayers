/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1172
  Name: The Bridges of Kolsberg
  Problem: https://onlinejudge.org/external/11/1172.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int DPs[1024][1024], DPc[1024][1024],
    A[1024], B[1024], X[1024], Y[1024], n, m;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string str, id;
    while (T--) {
        int icnt = 0;
        map<string, int> ids;

        for (int i=0; i<2; ++i) {
            int *Z = i ? Y : X,
                *C = i ? B : A,
                &sz = i ? m : n;
            cin >> sz;
            for (int j=1; j<=sz; ++j) {
                cin >> str >> id >> C[j];
                auto it = ids.emplace(id, icnt);
                if (it.second) ++icnt;
                Z[j] = it.first->second;
            }
        }

        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j) {
                int &ds = DPs[i][j],
                    &dc = DPc[i][j];

                if (X[i] == Y[j]) {
                    int dps = DPs[i-1][j-1] + A[i] + B[j];
                    if (dps > DPs[i-1][j] && dps > DPs[i][j-1]) {
                        ds = dps,
                        dc = DPc[i-1][j-1] + 1;
                        continue;
                    }
                }

                if (DPs[i-1][j] > DPs[i][j-1])
                    ds = DPs[i-1][j],
                    dc = DPc[i-1][j];

                else
                    ds = DPs[i][j-1],
                    dc = DPc[i][j-1];
            }

        cout << DPs[n][m] << ' ' << DPc[n][m] << '\n';
    }
}
