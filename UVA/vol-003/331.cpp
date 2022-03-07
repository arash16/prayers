/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 331
  Name: Mapping the Swaps
  Problem: https://onlinejudge.org/external/3/331.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int X[7], n, r, best;
void bt(int cnt) {
    if (cnt > best) return;

    bool sorted = 1;
    for (int i=1; i<n; ++i)
        if (X[i] < X[i-1]) {
            swap(X[i], X[i-1]);
            bt(cnt + 1);
            swap(X[i], X[i-1]);
            sorted = 0;
        }

    if (sorted) {
        if (cnt < best) r = 0;
        best = cnt; ++r;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n && n; ++cse) {
        for (int i=0; i<n; ++i)
            cin >> X[i];

        best = n*(n-1)/2;
        r = 0;
        bt(0);
        cout << "There are " << (!best ? 0 : r) << " swap maps for input data set " << cse << ".\n";
    }
}
