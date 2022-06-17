/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1587
  Name: Box
  Problem: https://onlinejudge.org/external/15/1587.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define PAIR pair<int, int>
PAIR X[100];

bool eq(int x, PAIR p) {
  return x == p.first || x == p.second;
}

bool check0(PAIR p1, PAIR p2, PAIR p3) {
  return (eq(p1.first, p2) && eq(p1.second, p3)) || (eq(p1.first, p3) && eq(p1.second, p2));
}

bool check() {
  if (X[0] != X[1] || X[2] != X[3] || X[4] != X[5]) {
    return false;
  }

  return check0(X[0], X[2], X[4]) && check0(X[2], X[0], X[4]) && check0(X[4], X[0], X[2]);
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> X[0].first >> X[0].second) {
    for (int i=1; i<6; ++i) {
      cin >> X[i].first >> X[i].second;
    }

    for (int i=0; i<6; ++i) {
      if (X[i].first > X[i].second) {
        swap(X[i].first, X[i].second);
      }
    }

    sort(X, X+6);
    cout << (check() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
}
