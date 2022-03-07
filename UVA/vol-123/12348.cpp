#include <bits/stdc++.h>
using namespace std;

// UVa has issue with this solution, but it looks right based on uDebug
// https://www.udebug.com/UVa/12348

int bitcount(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0F0F0F0F;
  return (i * 0x01010101) >> 24;
}

int n, m;
set<int> sets;
bool check_permutation(int perm) {
  for (int s: sets) {
    int reds = s & perm;
    // no reds, or all reds
    if (!reds || reds == s) {
      return false;
    }
  }
  return true;
}

bool permutation_exists() {
  for (int perm=(1<<n)-1; perm>=0; --perm) {
    if (check_permutation(perm)) {
      return true;
    }
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    string ln;
    getline(cin, ln);

    sets.clear();
    for (int i=0; i<m; ++i) {
      getline(cin, ln);
      istringstream iss(ln);

      int v = 0;
      for(int x; iss >> x; ) {
        v |= 1 << (x-1);
      }

      // more than one constraint
      if (bitcount(v) > 1) {
        sets.insert(v);
      }
    }

    cout << (permutation_exists() ? 'Y' : 'N');
  }
  cout.flush();
}
