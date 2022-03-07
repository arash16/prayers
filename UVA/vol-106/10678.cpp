/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10678
  Name: The Grazing Cow
  Problem: https://onlinejudge.org/external/106/10678.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int main() {
    cout << fixed << setprecision(3);

    int T;
    cin >> T;
    double d, l;
    while (T-- && cin >> d >> l)
        cout << PI*l*sqrt(l*l-d*d)/4 << '\n';
}
