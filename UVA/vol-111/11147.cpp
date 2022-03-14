/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11147
  Name: KuPellaKeS BST
  Problem: https://onlinejudge.org/external/111/11147.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int X[1143], Y[1143], n;

void solve(int l, int r) {
  if (r - l == 0 || l >= n) {
    return;
  }
  if (r - l == 1) {
    cout << X[l];
    return;
  }

  int bdiff = 0xfffffff, idx = l, mxl = 0;
  for (int i=l; i<r; ++i) {
    if (i < r-1 && X[i] == X[i+1]) continue;

    int sl = Y[i] - Y[l];
    int sr = Y[r] - Y[i+1];
    int d = sl < sr ? sr-sl : sl-sr;

    if (d < bdiff) {
      mxl = sl;
      bdiff = d;
      idx = i;
    }

    if (d == bdiff && sl > mxl) {
      mxl = sl;
      idx = i;
    }
  }

  cout << X[idx] << "(";
  solve(l, idx);
  if (idx != l && idx != r-1) {
    cout << ",";
  }
  solve(idx+1, r);
  cout << ")";
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  for (int cse=1; cse<=T; ++cse) {
    cin >> n;
    for (int i=0; i<n; ++i) {
      cin >> X[i];
    }

    sort(X, X+n);
    for (int i=1; i<=n; ++i) {
      Y[i] = Y[i-1] + X[i-1];
    }
    Y[n+1] = Y[n];

    cout << "Case #" << cse << ": ";
    solve(0, n);
    cout << endl;
  }
}
