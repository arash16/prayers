/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10957
  Name: So Doku Checker
  Problem: https://onlinejudge.org/external/109/10957.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

char msg[4][17] = {
    "Impossible.\n",
    "Unique.\n",
    "Ambiguous.\n",
    "Illegal.\n"
};


int X[9][9];
bool R[9][9], C[9][9], S[3][3][9];
int backtrack(int i, int j) {
    if (j == 9) ++i, j=0;
    if (i == 9) return 1;
    if (X[i][j]) return backtrack(i, j+1);

    int cc = 0;
    int si = i/3, sj = j/3;
    for (int k=0; k<9; ++k)
        if (!R[i][k] && !C[j][k] && !S[si][sj][k]) {
            R[i][k] = 1;
            C[j][k] = 1;
            S[si][sj][k] = 1;

            int rr = backtrack(i, j+1);
            if (rr > 1) return rr;
            if (rr > 0) ++cc;
            if (cc > 1) return cc;

            R[i][k] = 0;
            C[j][k] = 0;
            S[si][sj][k] = 0;
        }

    return cc;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; ; ++cse) {
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j)
                if (!(cin >> X[i][j]))
                    return 0;
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        memset(S, 0, sizeof(S));

        int result = 0;
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j) {
                int x = X[i][j] - 1;
                if (x < 0) continue;
                if (R[i][x]++ || C[j][x]++ || S[i/3][j/3][x]++)
                    result = 3;
            }

        if (result < 3) result = backtrack(0, 0);
        cout << "Case " << cse << ": " << msg[result];
    }
}
