/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1231
  Name: ACORN
  Problem: https://onlinejudge.org/external/12/1231.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXTH 2143
int M[MAXTH][MAXTH], S[MAXTH][MAXTH], t, f;

int Sum(int i, int j0, int j1) {
  if (j0<0) j0 = 0;
  if (j1<0) j1 = 0;
  return S[i][j1] - S[i][j0];
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int cse;
  cin >> cse;
  for (int i=0; i<cse; ++i) {
    int h,sz;
    cin >> t >> h >> f;
    for (int i=0; i<t; ++i) {
      for (int j=0; j<=h+f; ++j) {
        M[i][j] = 0;
      }

      cin >> sz;
      int nj = 0, j;
      for (int k=0; k<sz; ++k) {
        cin >> j;
        M[i][j]++;
      }

      S[i][0] = M[i][0];
      for (int j=1; j<=h+f; ++j) {
        S[i][j] = S[i][j-1] + M[i][j];
      }
    }

    int ci=0, cj=h+f, sum = 0;
    while (cj >= 0) {
      sum += M[ci][cj];
      int ni = ci, 
          nj = cj - 1,
          s = Sum(ci, cj-2*f, cj-1);

      for (int i = 0; i < t; ++i) {
        if (i != ci) {
          int ss = Sum(i, cj-2*f, cj-f);
          if (ss > s) {
            ni = i;
            nj = cj - f;
            s = ss;
          }
        }
      }
      ci = ni;
      cj = nj;

      // cout << ci << "," << cj << endl;
    }
    cout << sum << endl;
  }
}
