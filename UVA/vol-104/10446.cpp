/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10446
  Name: The Marriage Interview :-)
  Problem: https://onlinejudge.org/external/104/10446.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    unsigned long long DP[61][61];
    for (int n=0; n<61; ++n)
        for (int b=0; b<61; ++b) {
            DP[n][b] = 1;
            if (n>1)
            for (int i=1; i<=b; ++i)
                DP[n][b] += i<n ? DP[n-i][b] : 1;
        }

    int n, k;
    for (int cse=1; cin >> n >> k && (n<61); ++cse)
        cout << "Case " << cse << ": " << (n<0 ? 1 : DP[n][k]) << "\n";
}
