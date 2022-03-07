/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10465
  Name: Homer Simpson
  Problem: https://onlinejudge.org/external/104/10465.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, t;
    while (cin >> n >> m >> t) {
        if (n > m) swap(n, m);

        int bt = 100000, bs = 0;
        for (int i=t/n, x=i*n; bt && i>=0; --i, x-=n) {
            int j = (t-x) / m,
                y = j*m;

            if (bt > t-x-y) {
                bt = t-x-y;
                bs = i + j;
            }
        }
        cout << bs;
        if (bt) cout << ' ' << bt;
        cout << "\n";
    }
}
