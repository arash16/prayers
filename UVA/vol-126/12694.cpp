/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12694
  Name: Meeting Room Arrangement
  Problem: https://onlinejudge.org/external/126/12694.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> E[23];

int memo[13][23];
int dfs(int s, int i) {
  if (i == n) return 0;
  if (E[i].first < s) {
    return dfs(s, i+1);
  }

  if (memo[s][i] != -1) {
    return memo[s][i];
  }

  return memo[s][i] = max(
    dfs(E[i].second, i+1)+1,
    dfs(s, i+1)
  );
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  while (T--) {
    int s, f;
    for (n=0; cin >> s >> f && (s || f); n++) {
      E[n].first = s;
      E[n].second = f;
    }
    sort(E, E+n);
    memset(memo, -1, sizeof(memo));
    cout << dfs(0, 0) << endl;
  }
}
