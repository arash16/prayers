/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13214
  Name: The Robot's Grid
  Problem: https://onlinejudge.org/external/132/13214.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long DP[55][55] = {};
    for (int sum=2; sum<=50; ++sum) {
        DP[sum-1][1] = 1;
        for (int c=2; c<sum; ++c) {
            int r = sum - c;
            for (int i=1; i<=r; ++i)
                DP[r][c] += DP[c-1][i];
        }
    }

    int T, r, c;
    cin >> T;
    while (T-- && cin >> r >> c)
        cout << DP[r][c] << endl;
}
