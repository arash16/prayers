/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10874
  Name: Segments
  Problem: https://onlinejudge.org/external/108/10874.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 268435456
using namespace std;

int calc(int l, int r, int p, bool f) {
    return f ?
        (p<=l ? r-p : p-l + r-l):
        (p>=r ? p-l : r-p + r-l);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int DP[20043][2], P[20043][2], n;
        DP[0][0] = INF;
    while (cin >> n && n) {
        for (int i=0; i<n; ++i) {
            cin >> P[i][0] >> P[i][1];
        }

        P[n][0] = P[n][1] = n;
        DP[0][1] = P[0][1]-1;

        for (int i=1; i<=n; ++i)
            for (int j=0; j<2; ++j)
                DP[i][j] = min(
                    DP[i-1][0] + calc(P[i][0], P[i][1], P[i-1][0], j),
                    DP[i-1][1] + calc(P[i][0], P[i][1], P[i-1][1], j)
                );
        cout << DP[n][0]+n-1 << endl;
    }
}
