/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11100
  Name: The Trip, 2007
  Problem: https://onlinejudge.org/external/111/11100.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[10143], n;
    vector<int> vec[10143];

    bool frst = 1;
    while (cin >> n && n) {
        if (frst) frst = 0;
        else cout << "\n";

        for (int i=0; i<n; ++i)
            cin >> X[i];
        sort(X, X+n);

        int sz=1, cnt=1;
        for (int i=1; i<n; ++i)
            if (X[i] == X[i-1])
                 ++cnt;
            else sz = max(sz, cnt),
                 cnt = 1;

        sz = max(sz, cnt);
        for (int i=0; i<sz; ++i)
            vec[i].clear();

        for (int i=0, j=-1; i<n; ++i)
            vec[j=(j+1)%sz].push_back(X[i]);

        cout << sz << "\n";
        for (int i=0; i<sz; ++i) {
            cout << vec[i][0];
            for (int j=1; j<vec[i].size(); ++j)
                cout << ' ' << vec[i][j];
            cout << "\n";
        }
    }
}
