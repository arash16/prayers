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


int I[73000], X[73000], M[73000], n, p, q, T;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> T;
    for (int cse=1; cse <= T; ++cse) {
        cin >> n >> p >> q;
        n = n*n; ++p; ++q;

        memset(I, -1, sizeof(I));
        for (int i=0, t; i<p; ++i) {
            cin >> t;
            I[t] = i;
        }

        int L = 0;
        for (int j=0; j<q; ++j) {
            cin >> X[j];
            if (I[X[j]] == -1) continue;

            int lo = 1, hi = L;
            while (lo <= hi) {
                int mid = (lo + hi + 1) >> 1;
                if (I[X[M[mid]]] < I[X[j]])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            M[lo] = j;
            L = max(L, lo);
        }

        cout << "Case " << cse << ": " << L << '\n';
    }
}
