/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1230
  Name: MODEX
  Problem: https://onlinejudge.org/external/12/1230.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int powmod(int a, int b, int m) {
    if (!b) return 1;
    if (b==1) return a%m;

    long long r = powmod(a, b>>1, m);
    r = (r * r) % m;
    if (b&1) r = (r * a) % m;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, x, y, n;
    cin >> T;
    while (T-- && cin >> x >> y >> n)
        cout << powmod(x, y, n) << '\n';
}
