/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11495
  Name: Bubbles and Buckets
  Problem: https://onlinejudge.org/external/114/11495.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

// BIT/Fenwick Tree
int X[100143], n, x;

void add(int i, int inc) {
  if (i == 0) {
    X[0] += inc;
    return;
  }

  for(; i<=n; i += (i & -i)) {
    X[i] += inc;
  }
}

int sum(int i) {
  int result = X[0];
  for (; i; i -= (i & -i)) {
    result += X[i];
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> n && n > 0) {
    memset(X, 0, n*sizeof(int));

    int result = 0;
    for (int i=0; i<n; ++i) {
      cin >> x;
      add(x, 1);
      result += i-sum(x-1);
    }
    cout << (result%2 ? "Marcelo" : "Carlos") << endl;
  }
}
