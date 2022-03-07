/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10128
  Name: Queue
  Problem: https://onlinejudge.org/external/101/10128.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long DP[14][14][14];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    DP[1][1][1] = 1;
    for (int n=2; n<=13; ++n)
        for (int l=1; l<=n; ++l)
            for (int r=1; r<=n; ++r)
                DP[n][l][r] = (n-2)*DP[n-1][l][r] + DP[n-1][l-1][r] + DP[n-1][l][r-1];

    int T, n, l, r;
    cin >> T;
    while (T-- && cin >> n >> l >> r)
        cout << DP[n][l][r] << '\n';
}
