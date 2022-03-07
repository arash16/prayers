/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12291
  Name: Polyomino Composer
  Problem: https://onlinejudge.org/external/122/12291.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool findStart(char M[20][20], int n, int &i, int &j) {
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
            if (M[i][j] == '*')
                return 1;
    return 0;
}

int n, m;
char L[20][20], S[20][20];
char getval(int i, int j) {
    return i<0 || i>=n || j<0 || j>=n ? '.' : L[i][j];
}


bool check() {
    int i1, j1, i2, j2;
    bool bs = findStart(S, m, i1, j1);
    for (int k=0; k<2; ++k)
        if (findStart(L, n, i2, j2) != bs)
            return 0;

        else {
            int di = i2-i1, dj = j2-j1;
            for (int i=0; i<m; ++i)
                for (int j=0; j<m; ++j)
                    if (S[i][j] == '*') {
                        if (getval(i+di, j+dj) == '*')
                            L[i+di][j+dj] = '.';
                        else return 0;
                    }
        }

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (L[i][j] == '*')
                return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> m && (n || m)) {
        for (int i=0; i<n; ++i)
            cin >> L[i];
        for (int i=0; i<m; ++i)
            cin >> S[i];

        cout << (check() ? "1\n" : "0\n");
    }
}
