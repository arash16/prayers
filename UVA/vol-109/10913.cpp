/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10913
  Name: Walking on a Grid
  Problem: https://onlinejudge.org/external/109/10913.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

int dif[]={1, -1},
    mxj[]={1,  0};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int DP[143][143][7], X[143][143], n, m;
    bool V[143][143][7];
    for (int k=0; k<7; ++k)
        V[0][1][k] = 1;

    for (int cse=1; cin >> n >> m && (n||m); ++cse) {
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                cin >> X[i][j];

        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j) {
                for (int k=0; k<=m; ++k)
                    DP[i][j][k] = -INF,
                    V[i][j][k] = 0;

                for (int d=0; d<2; ++d) {
                    int sum=0, neg=0;
                    for (int jj=j; (mxj[d] ? jj<=n : jj>=0) && neg<=m; jj+=dif[d]) {
                        sum += X[i][jj];
                        if (X[i][jj] < 0) ++neg;
                        for (int k=neg; k<=m; ++k)
                            if (V[i-1][jj][k-neg]) {
                                V[i][j][k] = 1;
                                DP[i][j][k] = max(DP[i][j][k], sum + DP[i-1][jj][k-neg]);
                            }
                    }
                }
            }

        bool flag = 0;
        int mx = -INF;
        for (int k=0; k<=m; ++k)
            if (V[n][n][k]) {
                mx = max(mx, DP[n][n][k]);
                flag = true;
            }

        cout << "Case " << cse << ": ";
        if (!flag)
            cout << "impossible\n";
        else
            cout << mx << "\n";
    }
}
