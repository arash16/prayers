/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12515
  Name: Movie Police
  Problem: https://onlinejudge.org/external/125/12515.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


string MM[1143], C;
int diff(string &M, int bd) {
    int len = M.length(),
        clen = C.length();
    if (len < clen)
        return (int)1e9;

    int rd = bd,
        mi = len-clen;
    for (int i=0; i<=mi && rd; ++i) {
        int d = 0;
        for (int j=0; j<clen; ++j)
            if (M[i+j] != C[j])
                if (++d >= rd)
                    break;
        rd = min(rd, d);
    }
    return rd;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q;
    while (cin >> n >> q) {
        for (int i=0; i<n; ++i)
            cin >> MM[i];

        while (q--) {
            cin >> C;
            int result = -1;
            int bd = (int)1e9;
            for (int i=0; i<n; ++i) {
                int d = diff(MM[i], bd);
                if (d < bd) {
                    bd = d;
                    result = i;
                    if (!bd) break;
                }
            }

            cout << result+1 << '\n';
        }
    }
}
