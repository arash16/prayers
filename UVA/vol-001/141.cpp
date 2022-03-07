/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 141
  Name: The Spot Game
  Problem: https://onlinejudge.org/external/1/141.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


void rot(bool X[55][55], int n) {
    for (int k=0; k<n/2; ++k)
        for (int i=k; i<n-k-1; ++i) {
            bool t = X[k][i];
            X[k][i] = X[i][n-k-1];
            X[i][n-k-1] = X[n-k-1][n-i-1];
            X[n-k-1][n-i-1] = X[n-i-1][k];
            X[n-i-1][k] = t;
        }
}

bool eq(bool X[55][55], bool Y[55][55], int n) {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (X[i][j] != Y[i][j])
                return 0;
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char ch;
    int n, r, c;
    bool S[143][55][55]={};

    while (cin >> n && n) {
        bool done = false;
        for (int i=1; i<=2*n; ++i) {
            cin >> r >> c >> ch; --r; --c;
            if (done) continue;

            memcpy(S[i], S[i-1], sizeof(S[i]));
            S[i][r][c] = ch=='+';
            // Optimization: count black cells, later compare only if different blacks

            for (int k=0; k<4 && !done; ++k) {
                rot(S[i], n);
                for (int j=1; j<i; ++j)
                    if (eq(S[i], S[j], n)) {
                        cout << "Player " << ((i%2)+1) << " wins on move " << i << endl;
                        done = true;
                        break;
                    }
            }
        }

        if (!done) cout << "Draw\n";
    }
}
