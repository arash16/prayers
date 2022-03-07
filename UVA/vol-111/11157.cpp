/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11157
  Name: Dynamic Frog
  Problem: https://onlinejudge.org/external/111/11157.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char tp[143], ch;
    int X[143]={}, T, n, d;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> d;

        int sz = 1;
        for (int i=0; i<n; ++i) {
            cin >> tp[sz] >> ch >> X[sz];
            if (X[i] < d) ++sz;
        }
        tp[0] = tp[sz] = 'B';
        X[sz++] = d;

        int lx=0, mxd=0;
        bool used[101] = {};
        for (int i=0; i<sz; ++i) {
            if (tp[i] == 'S') ++i;
            if (tp[i] == 'S') used[i] = 1;
            mxd = max(mxd, X[i]-lx);
            lx = X[i];
        }

        for (int i=sz-1; i>=0; --i)
            if (!used[i]) {
                mxd = max(mxd, lx-X[i]);
                lx = X[i];
            }

        cout << "Case " << cse << ": " << mxd << '\n';
    }
}
