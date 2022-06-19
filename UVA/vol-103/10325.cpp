#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);   
}

int X[23], n, m;
int dfs(long long mm, int sgn, int i) {
  if (mm > n) return 0;
  if (i == m) {
    return mm>1 ? sgn * floor(n/mm) : 0;
  }

  return dfs(mm*X[i]/gcd(mm, X[i]), sgn*-1, i+1) + dfs(mm, sgn, i+1);
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> n >> m) {
    for (int i=0; i<m; ++i) {
      cin >> X[i];
    }

    cout << (n - dfs(1, -1, 0)) << endl;
  }
}
