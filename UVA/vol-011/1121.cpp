/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1121
  Name: Subsequence
  Problem: https://onlinejudge.org/external/11/1121.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int N, S, X[100143], C[100143] = {0};
  while (cin >> N >> S) {
    for (int i=1; i<=N; ++i) {
      cin >> X[i];
      C[i] = X[i] + C[i-1];
    }

    int best = N+1;
    for (int i=1; i<=N; ++i) {
      int *p = lower_bound(C+i, C+N, C[i-1]+S);
      if (*p - C[i-1] >= S) {
        int len = p - (C+i) + 1;
        best = min(best, len);
      }
    }
    cout << (best>N ? 0 : best) << endl;
  }
}
