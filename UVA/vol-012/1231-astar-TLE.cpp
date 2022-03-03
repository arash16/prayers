#include <bits/stdc++.h>
using namespace std;

#define MAXTH 2143
int M[MAXTH][MAXTH], nexta[MAXTH][MAXTH], S[MAXTH], SS[MAXTH][MAXTH], t, f;
int best;

int upper(int i, int j) {
  int jj = j-f <= 0 ? 0 : j-f;
  return S[jj] + SS[i][j] - SS[i][jj];
}

void astar(int i, int j, int sum) {
  if (sum > best) best = sum;
  if (i<0 || i>t || j<0) return;
  if (sum + upper(i, j) <= best) return;
  if (!M[i][j] && nexta[i][j]==j) return;
  if (!M[i][j]) return astar(i, nexta[i][j], sum);

  astar(i, j-1, sum + M[i][j]);
  for (int k=0; k<t; ++k) {
    if (k != i) {
      astar(k, j-f, sum + M[i][j]);
    }
  }
}

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

        int jj = nj;
        while (jj < j) {
          nexta[i][jj++] = nj;
        }
        nj = j;
      }
      int jj = nj;
      while (jj <= h) {
        nexta[i][jj++] = nj;
      }
    }

    for (int j=0; j<=h; ++j) {
      int mx = 0;
      for (int i=0; i<t; ++i) {
        mx = max(mx, M[i][j]);
        SS[i][j] = (j ? SS[i][j-1] : 0) + M[i][j];
      }
      S[j] = (j ? S[j-1] : 0) + mx;
    }

    best = 0;
    for (int i=0; i<t; ++i) {
      astar(i, h, 0);
    }
    cout << best << endl;
  }
}
