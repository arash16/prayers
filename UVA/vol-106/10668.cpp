/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10668
  Name: Expanding Rods
  Problem: https://onlinejudge.org/external/106/10668.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    double l, t, c, lp;
    while (cin >> l >> t >> c && l>=0) {
        lp = (1 + t*c) * l;
        if (fabs(lp-l) < 1e-6) cout << 0.0 << endl;
        else {
            double lo=0, hi=PI;
            while (hi-lo > 1e-13) {
                double a = (lo + hi) / 2;
                if (a*l/(2*sin(a/2)) < lp)
                    lo = a;
                else
                    hi = a;
            }

            double r = lp/lo;
            cout << (r - r*cos(lo/2)) << '\n';
        }
    }
}
