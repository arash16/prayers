/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10617
  Name: Again Palindrome
  Problem: https://onlinejudge.org/external/106/10617.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

string ln;
long long memo[64][64];
long long dfs(int i, int j) {
  if (j-i<0) return 1;
  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  // remove i-th
  long long res = dfs(i+1, j);

  // preserve i-th
  for (int k=i; k<=j; ++k)
    if (ln[k] == ln[i]) {
      res += dfs(i+1, k-1);
    }

  return memo[i][j] = res;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  while(T--) {
    cin >> ln;
    memset(memo, -1, sizeof(memo));
    cout << dfs(0, ln.size()-1)-1 << endl;
  }
}
