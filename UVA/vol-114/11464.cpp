/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11464
  Name: Even Parity
  Problem: https://onlinejudge.org/external/114/11464.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int X[16][16], M[16][16], n;
void click(int i, int j) {
    if (i) M[i-1][j] = !M[i-1][j];
    if (j) M[i][j-1] = !M[i][j-1];
    if (i<n-1) M[i+1][j] = !M[i+1][j];
    if (j<n-1) M[i][j+1] = !M[i][j+1];
}


int best;
void backtrack(int i, int j, int step) {
    if (step >= best) return;
    if (i && j && M[i-1][j-1]) return;
    if (j>1 && M[i][j-2] && X[i+1][j-2]) return;
    if (j == n) {
        if (j && M[i][j-1] && X[i+1][j-1]) return;
        ++i, j=0;
    }

    if (i < n) {
        backtrack(i, j+1, step);
        if (!X[i][j]) {
            click(i, j);
            backtrack(i, j+1, step+1);
            click(i, j);
        }
        return;
    }

    best = step;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (int cse=1; T-- && cin >> n; ++cse) {
        memset(M, 0, sizeof(M));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> X[i][j];
                if (X[i][j])
                    click(i, j);
            }
            X[n][i] = 1;
        }

        best = 616;
        backtrack(0, 0, 0);
        cout << "Case " << cse << ": " << (best==616 ? -1 : best) << '\n';
    }
}
