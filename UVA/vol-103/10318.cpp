/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10318
  Name: Security Panel
  Problem: https://onlinejudge.org/external/103/10318.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int M[7][7], r, c,
    di[10], dj[10], dsz;
void press(int ii, int jj) {
    for (int k=0; k<dsz; ++k) {
        int i = ii + di[k],
            j = jj + dj[k];

        if (i>=0 && i<r && j>=0 && j<c)
            M[i][j] = !M[i][j];
    }
}

int best, bestp[43], pp[43];
void backtrack(int i, int j, int step = 0) {
    if (i && j>=2 && !M[i-1][j-2]) return;
    if (j == c) {
        if (i && j>=1 && !M[i-1][j-1]) return;
        i++;
        j=0;
    }

    if (i < r) {
        backtrack(i, j+1, step);
        press(i, j);
        pp[step] = i*c + j + 1;
        backtrack(i, j+1, step+1);
        press(i, j);
        return;
    }

    for (int k=0; k<c; ++k)
        if (!M[r-1][k])
            return;
    if (best > step) {
        best = step;
        memcpy(bestp, pp, step*sizeof(int));
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string ln;
    for (int cse=1; cin >> r >> c && (r||c); ++cse) {
        dsz = 0;
        for (int i=0; i<3; ++i) {
            cin >> ln;
            for (int j=0; j<3; ++j)
                if (ln[j] == '*') {
                    di[dsz] = i-1;
                    dj[dsz] = j-1;
                    ++dsz;
                }
        }


        best = 100;
        backtrack(0, 0);
        cout << "Case #" << cse << '\n';
        if (best == 100) cout << "Impossible.\n";
        else {
            cout << bestp[0];
            for (int i=1; i<best; ++i)
                cout << ' ' << bestp[i];
            cout << '\n';
        }
    }
}
