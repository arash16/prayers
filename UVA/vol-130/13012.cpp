/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13012
  Name: Identifying tea
  Problem: https://onlinejudge.org/external/130/13012.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    while (cin >> t) {
        int r = 0;
        for (int i=0, x; i<5; ++i) {
            cin >> x;
            if (x == t) ++r;
        }
        cout << r << '\n';
    }
}
