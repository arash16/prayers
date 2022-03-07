/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 927
  Name: Integer Sequences from Addition of Terms
  Problem: https://onlinejudge.org/external/9/927.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, d, k, C[43];
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<=n; ++i)
            cin >> C[i];

        cin >> d >> k;
        int p = ceil((sqrt(1 + 8.0*k/d) - 1) / 2.0);

        long long r = C[n];
        for (int i=n-1; i>=0; --i)
            r = r*p + C[i];

        cout << r << endl;
    }
}
