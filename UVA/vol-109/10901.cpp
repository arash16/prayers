/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10901
  Name: Ferry Loading III
  Problem: https://onlinejudge.org/external/109/10901.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1073741824
#define MAXN 10017
int xl[MAXN], xr[MAXN], tl[MAXN], tr[MAXN], res[MAXN];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, t, m, tm;
    cin>>T;
    while (T--) {
        cin>> n >> t >> m;
        int lc=0, lr=0;
        for (int i=0; i<m; ++i) {
            char dir[20];
            cin >> tm >> dir;
            if (dir[0]=='l') {
                xl[lc] = i;
                tl[lc++] = tm;
            }
            else {
                xr[lr] = i;
                tr[lr++] = tm;
            }
        }

        tr[lr] = tl[lc] = INF;
        tm = 0;
        int i=0, j=0,
            *ic=&i, *io=&j,
            *xc=xl, *xo=xr,
            *tc=tl, *to=tr;
        while (i<lc || j<lr) {
            if (tm < tc[*ic]) {
                if (tc[*ic] <= to[*io])
                    tm = tc[*ic];
                else {
                    tm = max(tm, to[*io]) + t;
                    swap(ic, io);
                    swap(xc, xo);
                    swap(tc, to);
                }
            }

            for (int k=0; k<n && tc[*ic]<=tm; ++k)
                res[xc[(*ic)++]] = tm + t;

            tm += t;
            swap(ic, io);
            swap(xc, xo);
            swap(tc, to);
        }

        for (int i=0; i<m; ++i)
            cout << res[i] << endl;
        if (T) cout << endl;
    }
}
