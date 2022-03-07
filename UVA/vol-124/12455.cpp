/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12455
  Name: Bars
  Problem: https://onlinejudge.org/external/124/12455.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[23], T, n, l;
    cin >> T;
    while (T-- && cin>>l>>n) {
        int sz = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[sz];
            if (X[sz] <= l) ++sz;
        }

        bool DP[1001] = { 1 };
        for (int i=0; i<sz; ++i)
            for (int j=l-X[i]; j>=0; --j)
                DP[j + X[i]] |= DP[j];

        cout << (DP[l] ? "YES\n" : "NO\n");
    }
}
