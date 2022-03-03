#include <bits/stdc++.h>
using namespace std;

#define MAXTH 2143
int M[MAXTH][MAXTH], DP[MAXTH][MAXTH], DPP[MAXTH], t, f;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int cse;
  cin >> cse;
  for (int i=0; i<cse; ++i) {
    int h,sz;
    cin >> t >> h >> f;
    for (int i=0; i<t; ++i) {
      for (int j=0; j<=h; ++j) {
        M[i][j] = 0;
      }

      cin >> sz;
      int nj = 0, j;
      for (int k=0; k<sz; ++k) {
        cin >> j;
        M[i][j]++;
      }
    }

    DPP[0] = 0;
    for (int i=0; i<t; ++i) {
      DP[i][0] = M[i][0];
      DPP[0] = max(DPP[0], DP[i][0]);
    }

    for (int j=1; j<=h; ++j) {
      DPP[j] = 0;
      for (int i=0; i<t; ++i) {
        DP[i][j] = M[i][j] + max(DP[i][j-1], DPP[j-f < 0 ? 0 : j - f]);
        DPP[j] = max(DPP[j], DP[i][j]);
      }
    }

    int res = 0;
    for (int i=0; i<t; ++i) {
      res = max(res, DP[i][h]);
    }
    cout << res << endl;
  }
}
