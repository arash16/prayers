/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12720
  Name: Algorithm of Phil
  Problem: https://onlinejudge.org/external/127/12720.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  for (int cse=1; cse<=T; ++cse) {
    string a; cin >> a;
    int l=a.length(), i=(l-1)>>1;
    int s = l%2 ? a[i--] == '1' : 0;
    for (; i>=0; --i) {
      bool ii=a[i]=='1', jj=a[l-i-1]=='1';
      int t = ii&&jj ? 3 : ii||jj ? 2 : 0;
      s = (((long long)s << 2) | t) % 1000000007;
    }

    printf("Case #%d: %d\n", cse, s);
  }
}
