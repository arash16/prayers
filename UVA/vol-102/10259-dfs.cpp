/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10259
  Name: Hippity Hopscotch
  Problem: https://onlinejudge.org/external/102/10259.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    int result = *p;
    if (skip) ++p;
    return result;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return EOF;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    while (ch!=' ' && ch!='\n')
        ch = readchar();
    return r;
}

// -------------------------------------------------------------------------

int D[143][143], X[143][143], n, d,
    di[] = {1,-1,0,0},
    dj[] = {0,0,1,-1};

int dfs(int ii, int jj) {
    if (D[ii][jj] != -1)
        return D[ii][jj];

    int mx = 0;
    for (int dir=0; dir<4; ++dir)
        for (int k=1; k<=d; ++k) {
            int ni = ii + k*di[dir],
                nj = jj + k*dj[dir];
            if (ni<0 || ni>=n || nj<0 || nj>=n) break;
            if (X[ni][nj] > X[ii][jj])
                mx = max(mx, dfs(ni, nj));
        }
    return D[ii][jj] = X[ii][jj] + mx;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        n = readUInt();
        d = readUInt();
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                X[i][j] = readUInt(),
                D[i][j] = -1;

        cout << dfs(0, 0) << '\n';
        if (T) cout << '\n';
    }
}
