/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11420
  Name: Chest of Drawers
  Problem: https://onlinejudge.org/external/114/11420.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    unsigned long long DP[66][66]={{1}};
    for (int n=1; n<66; ++n)
        for (int s=0; s<66; ++s) {
            DP[n][s] = s > 0 ? DP[n-1][s-1] : 1;
            for (int k=0; k<=n-2; ++k)
                DP[n][s] += DP[k][s];
        }

    for (int n, k; cin>>n>>k && (n>=0 && k>=0); )
        cout << DP[n][k] << "\n";
}
