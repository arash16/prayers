/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12210
  Name: A Match Making Problem
  Problem: https://onlinejudge.org/external/122/12210.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, x;
    for (int cse=1; cin >> n >> m && (n||m); ++cse) {
        int dif = n - m, mn = 100;
        while (n--) {
            cin >> x;
            mn = min(mn, x);
        }

        while (m--) cin >> x;

        cout << "Case " << cse << ": ";
        if (dif <= 0) cout << "0\n";
        else cout << dif << ' ' << mn << "\n";
    }
}
