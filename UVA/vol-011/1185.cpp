/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1185
  Name: Big Number
  Problem: https://onlinejudge.org/external/11/1185.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int R[10000001] = {1,1,1,1};
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  double l = 0;
  for (int i=2; i<10000001; ++i) {
    l += log10(i);
    R[i] = ceil(l);
  }

  int T, n; cin >> T;
  while (T--) {
    cin >> n;
    cout << R[n] << endl;
  }
}
