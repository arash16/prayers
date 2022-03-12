/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10385
  Name: Duathlon
  Problem: https://onlinejudge.org/external/103/10385.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int n;
double R[43], C[43], t;
double finishTime(int i, double r) {
  return (r/R[i] + (t - r) / C[i]) * 60 * 60;
}

double margin(double r) {
  double res = 1e9;
  for (int i=0; i<n-1; i++) {
    res = min(res, finishTime(i, r) - finishTime(n-1, r));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> t >> n) {
    for (int i=0; i<n; ++i) {
      cin >> R[i] >> C[i];
    }

    double lo = 0, hi = t, l, r, ml, mr;
    while (hi - lo > 1e-6) {
      l = (2*lo + hi)/3;
      ml = margin(l);
      r = (lo + 2*hi)/3;
      mr = margin(r);

      if (ml > mr) {
        hi = r;
      } else {
        lo = l;
      }
    }

    if (ml < -1e-3 && mr < -1e-3) {
      cout << "The cheater cannot win." << endl;
    } else {
      cout << "The cheater can win by " << fixed << setprecision(0) << fabs(ml)
           << " seconds with r = " << setprecision(2) << lo 
           << "km and k = " << (t - lo) << "km." 
           << endl;
    }
  }
}
