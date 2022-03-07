/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10730
  Name: Antiarithmetic?
  Problem: https://onlinejudge.org/external/107/10730.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int X[10143], Y[10143], n;
bool check() {
    int hn = n>>1;
    for (int i=0; i<n; ++i) {
        int x = X[i];
        for (int d = max(-hn, -(x>>1)); x+2*d < n; ++d) if (d) {
            int j = Y[x + d];
            if (j > i && Y[x + 2*d] > j)
                return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n && n) {
        cin.ignore(1);
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            Y[X[i]] = i;
        }

        cout << (check() ? "yes\n" : "no\n");
    }
}
