/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12187
  Name: Brothers
  Problem: https://onlinejudge.org/external/121/12187.pdf
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

// ------------------------------------------------------------------

int di[] = {0,0,1,-1},
    dj[] = {1,-1,0,0};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[128][128], Y[128][128], n, r, c, k;
    memset(X, -1, sizeof(X));
    memset(Y, -1, sizeof(Y));
    while ( (n=readUInt())!=EOF ) {
        r = readUInt();
        c = readUInt();
        k = readUInt();
        if (!(n||r||c||k)) break;

        memset(X[r+1], -1, 512);
        memset(Y[r+1], -1, 512);
        for (int i=1; i<=r; ++i) {
            X[i][c+1] = Y[i][c+1] = -1;
            for (int j=1; j<=c; ++j)
                X[i][j] = readUInt();
        }

        bool some = 1;
        while (k-- && some) {
            some = 0;
            for (int i=1; i<=r; ++i)
                for (int j=1; j<=c; ++j) {
                    int en = (n+X[i][j]-1) % n;
                    Y[i][j] = X[i][j];
                    for (int k=0; k<4; ++k)
                        if (X[i+di[k]][j+dj[k]] == en) {
                            Y[i][j] = en;
                            some = 1;
                            break;
                        }
                }
            swap(X, Y);
        }

        for (int i=1; i<=r; ++i) {
            cout << X[i][1];
            for (int j=2; j<=c; ++j)
                cout << ' ' << X[i][j];
            cout << '\n';
        }
    }
}
