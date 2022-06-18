/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10717
  Name: Mint
  Problem: https://onlinejudge.org/external/107/10717.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);   
}

long long lcm(long long a, long long b) {
  return (a*b) / gcd(a, b);
}

long long N, T, X[143], S[4], t, mn, mx;
void dfs(int i, int j) {
  if (i == 4) {
    long long g = lcm(lcm(lcm(S[0], S[1]), S[2]), S[3]);
    mn = max(mn, (long long)(floor(t/double(g))*g));
    mx = min(mx, (long long)(ceil(t/double(g))*g));
    return;
  }

  for (int k=j; k<N; ++k) {
    S[i] = X[k];
    dfs(i+1, k+1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> N >> T) {
    for (int i=0; i<N; ++i) {
      cin >> X[i];
    }

    for (int i=0; i<T; ++i) {
      mn = 0; mx = 1<<30;
      cin >> t;
      dfs(0, 0);
      cout << mn << " " << mx << endl;
    }
  }
}
