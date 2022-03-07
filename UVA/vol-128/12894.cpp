/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12894
  Name: Perfect Flag
  Problem: https://onlinejudge.org/external/128/12894.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, x0, x1, y0, y1, cx, cy, r;
    cin >> T;
    while (T--) {
        cin>> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
        int l = x1 - x0,
            w = y1 - y0;

        if (10*w == 6*l && l == 5*r &&
            cy == (y0+y1)/2.0 &&
            cx == x0 + l * 9 / 20.0)
             cout << "YES\n";
        else cout << "NO\n";
    }
}
