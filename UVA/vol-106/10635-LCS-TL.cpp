/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10635
  Name: Prince and Princess
  Problem: https://onlinejudge.org/external/106/10635.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int X[73000], Y[73000], n, p, q, T,
    SX[73000], SY[73000];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> T;
    for (int cse=1; cse <= T; ++cse) {
        cin >> n >> p >> q;
        n = n*n; ++p; ++q;
        for (int i=0; i<p; ++i) {
            cin >> X[i];
            SX[X[i]] = cse;
        }

        int sj = 0;
        for (int j=0; j<q; ++j) {
            cin >> Y[sj];
            SY[Y[sj]] = cse;
            if (SX[Y[sj]] == cse) ++sj;
        }
        q = sj;

        int DP1[73000] = {}, DP2[73000] = {};
        for (int i=0; i<p; ++i)
            if (SY[X[i]] == cse) {
                for (int j=0; j<q; ++j)
                    if (X[i] == Y[j])
                        DP2[j+1] = DP1[j] + 1;
                    else
                        DP2[j+1] = max(DP2[j], DP1[j+1]);

                swap(DP1, DP2);
            }

        cout << "Case " << cse << ": " << DP1[q] << '\n';
    }
}
