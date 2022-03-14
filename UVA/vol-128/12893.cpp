/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12893
  Name: Count It
  Problem: https://onlinejudge.org/external/128/12893.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int solve(unsigned long long n) {
  if (n<=0) return 0;
  return solve(n / 2) + (n % 2);
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  while (T--) {
    unsigned long long n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
