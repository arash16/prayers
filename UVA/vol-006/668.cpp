/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 668
  Name: Parliament
  Problem: https://onlinejudge.org/external/6/668.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        int res[500]={}, sz=0, i;
        for (i=2; i<=n; ++i)
            res[sz++] = i,
            n -= i;

        if (n > 0) {
            int k = i-n-2;
            if (k < 0) k = 0;
            res[sz++] = n + res[k];
            res[k] = 0;
        }

        i=0;
        while (!res[i])++i;
        cout << res[i];
        for (++i; i<sz; ++i)
            if (res[i])
                cout << ' ' << res[i];
        cout << '\n';
        if (T) cout << '\n';
    }
}
