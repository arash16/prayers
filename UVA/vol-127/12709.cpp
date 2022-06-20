/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12709
  Name: Falling Ants
  Problem: https://onlinejudge.org/external/127/12709.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, l, w, h;
  while (cin >> n && n) {
    int mxh=0, mxv=0;
    for (int i=0; i<n; ++i) {
      cin >> l >> w >> h;
      int v = l*w*h;
      if (h > mxh || (h == mxh && v > mxv)) {
        mxh = h;
        mxv = v;
      }
    }
    cout << mxv << endl;
  }
}
