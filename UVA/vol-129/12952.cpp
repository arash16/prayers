/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12952
  Name: Tri-du
  Problem: https://onlinejudge.org/external/129/12952.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x, y;
    while (cin >> x >> y)
        cout << max(x, y) << '\n';
}
