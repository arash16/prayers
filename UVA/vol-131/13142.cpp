/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13142
  Name: Destroy the Moon to Save the Earth
  Problem: https://onlinejudge.org/external/131/13142.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int C;
    cin >> C;
    while (C--) {
      double C, T, S, D;
      cin >> T >> S >> D;
      double t = T * 24 * 60 * 60;
      double d = D * 1e6;
      int res = d / t;
      if (res > 0) {
        cout << "Remove " << res << " tons" << endl;
      } else {
        cout << "Add " << (-res) << " tons" << endl;
      }
    }
}
