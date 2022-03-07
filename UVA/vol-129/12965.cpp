/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12965
  Name: Angry Bids
  Problem: https://onlinejudge.org/external/129/12965.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int P, C, Pp[10143], Cp[10143];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
      cin >> P >> C; P++;
      for (int i=1; i<P; ++i) {
        cin >> Pp[i];
      }
      for (int i=0; i<C; ++i) {
        cin >> Cp[i];
      }

      sort(Pp, Pp+P);
      sort(Cp, Cp+C);

      int best = 0;
      int besta = 1e9;
      if (P == 0) {
        besta = 0;
      } else {
        for (int i=0; i<P; i++) {
          int price = Pp[i];
          int ap = Pp + P - upper_bound(Pp, Pp+P, price);
          int ac = lower_bound(Cp, Cp+C, price) - Cp;
          int angry = ac + ap;
          if (angry < besta) {
            besta = angry;
            best = Pp[i];
          }
        }
      }
      cout << best << ' ' << besta << endl;
    }
}
