/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12571
  Name: Brother & Sisters!
  Problem: https://onlinejudge.org/external/125/12571.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T, n, m; cin >> T;
  while (T--) {
    cin >> n >> m;

    int mx = 0, x;
    bool S[256];
    memset(S, 0, sizeof(S));
    for (int i=0; i<n; ++i) {
      cin >> x;
      S[x & 255] = true;
    }

    vector<int> X;
    for (int i=0; i<256; ++i)
      if (S[i])
        X.push_back(i);

    for (int i=0; i<m; ++i) {
      cin >> x;
      mx = 0;
      for (int y: X) {
        mx = max(mx, x&y);
      }
      cout << mx << endl;
    }
  }
}
