/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 457
  Name: Linear Cellular Automata
  Problem: https://onlinejudge.org/external/4/457.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    char CH[] = " .xW";
    while (T--) {
        int DNA[10];
        for (int i=0; i<10; ++i)
            cin >> DNA[i];

        int X[42] = {};
        X[20] = 1;
        for (int i=0; i<50; ++i) {
            for (int j=1; j<=40; ++j)
                cout << CH[X[j]];
            cout << '\n';

            for (int j=1, b=0, k; j<=40; ++j)
                k = b+X[j]+X[j+1],
                b = X[j],
                X[j] = DNA[k];
        }

        if (T) cout << endl;
    }
}
