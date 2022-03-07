/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11701
  Name: Cantor
  Problem: https://onlinejudge.org/external/117/11701.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define EPS 1e-12
using namespace std;


bool isCantor(double x, double l=0, double r=1) {
    double d = r - l;
    if (d < EPS) return 1;

    double m = l + d/3;
    if (x <= m)
        return isCantor(x, l, m);

    m += d/3;
    if (x >= m)
        return isCantor(x, m, r);

    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    double x;
    while (cin >> x)
        cout << (isCantor(x) ? "MEMBER\n" : "NON-MEMBER\n");
}
