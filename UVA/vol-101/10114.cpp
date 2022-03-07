/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10114
  Name: Loansome Car Buyer
  Problem: https://onlinejudge.org/external/101/10114.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, j;
    double P[143], x, t, p;
    while (cin >> n >> x >> t >> m && n>=0) {
        fill(P, P+143, -1);
        for (int i=0; i<m; ++i) {
            cin >> j >> p;
            P[j] = p;
        }

        for (int i=0; i<143; ++i)
            if (P[i] < 0)
                P[i] = P[i-1];

        double v = (t+x)*(1 - P[0]);
        x = t / n;
        for (j=1; t >= v && j<=n; ++j) {
            v -= P[j] * v;
            t -= x;
        }

        cout << j-1 << " month" << (j==2 ? "\n" : "s\n");
    }
}
