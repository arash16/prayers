/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10130
  Name: SuperSale
  Problem: https://onlinejudge.org/external/101/10130.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, g;
    cin >> T;
    while (T--) {
        cin >> n;
        int DP[31]={};
        for (int i=0, p, w; i<n; i++) {
            cin >> p >> w;
            for (int r=30; r>=w; --r)
                DP[r] = max(DP[r], DP[r-w] + p);
        }

        cin >> g;
        int res = 0;
        for (int i=0, mw; i<g; i++) {
            cin >> mw;
            res += DP[mw];
        }
        cout << res << endl;
    }
}
