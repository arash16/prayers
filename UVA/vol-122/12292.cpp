/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12292
  Name: Polyomino Decomposer
  Problem: https://onlinejudge.org/external/122/12292.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int Px[23], Py[23], sz, cnt, n;
char M[17][17];

// check & fill
bool check() {
    char ch = 'A';
    int oy = Py[0],
        ox = Px[0];

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (M[i][j] == '*') {
                for (int k=0; k<sz; ++k) {
                    int ii = i+Py[k]-oy,
                        jj = j+Px[k]-ox;

                    if (ii>=0 && ii<n && jj>=0 && jj<n && M[ii][jj] == '*')
                        M[ii][jj] = ch;
                    else goto cancel;
                }
                ++ch;
            }
    return 1;

    cancel:
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (M[i][j] >= 'A')
                M[i][j] = '*';
    return 0;
}


// check if pattern is connected
bool used[23][23];
int dfs(int i, int j) {
    if (!used[i][j]) return 0;
    used[i][j] = 0;

    int r = 1;
    if (i) r += dfs(i-1, j);
    if (j) r += dfs(i, j-1);
    if (i<n-1) r+= dfs(i+1, j);
    if (j<n-1) r+= dfs(i, j+1);
    return r;
}

// permutations in lexicographic order
int Sx[23], Sy[23], pat[23];
bool decomposable(int snt) {
    for (int i=0; i<snt; ++i)
        pat[i] = i >= sz;

    do {
        int k = 0;
        memset(used, 0, sizeof(used));
        for (int j=0; j<snt; ++j)
            if (!pat[j])
                Py[k] = Sy[j],
                Px[k] = Sx[j],
                used[Py[k]][Px[k]] = 1,
                ++k;

        if (dfs(Py[0], Px[0]) == sz && check())
            return 1;
    }
    while (next_permutation(pat, pat+snt));
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n && n) {
        int snt = 0;
        for (int i=0; i<n; ++i) {
            cin >> M[i];
            for (int j=0; j<n; ++j)
                if (M[i][j] == '*') {
                    Sy[snt] = i;
                    Sx[snt] = j;
                    ++snt;
                }
        }

        for (cnt=2; cnt<snt; ++cnt)
            if (snt % cnt == 0) {
                sz = snt / cnt;
                if (decomposable(snt)) {
                    for (int i=0; i<n; ++i)
                        cout << M[i] << '\n';
                    break;
                }
            }

        // decompose to 1x1 squares
        if (cnt == snt) {
            char ch = 'A';
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j)
                    cout << (M[i][j] == '*' ? ch++ : '.');
                cout << '\n';
            }
        }
        cout << '\n';
    }
}
