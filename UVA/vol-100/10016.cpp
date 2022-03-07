/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10016
  Name: Flip-Flop the Squarelotron
  Problem: https://onlinejudge.org/external/100/10016.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf)
            return EOF;
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-');
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

// -------------------------------------------------------------------------

int X[200][200];
int main() {
    int T = readInt();
    while (T--) {
        int n = readInt();
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                X[i][j] = readInt();

        for (int i=0; i<(n+1)>>1; ++i) {
            int s = i, e = n-i-1,
                l = n-2*i, md=l>>1,
                cnt = readInt();

            for (int j=0; j<cnt; ++j) {
                switch (readInt()) {
                    case 1:
                        for (int k=s; k<=e; ++k)
                            swap(X[s][k], X[e][k]);
                        for (int k=1; k<md; ++k) {
                            swap(X[s+k][s], X[e-k][s]);
                            swap(X[s+k][e], X[e-k][e]);
                        }
                        break;
                    case 2:
                        for (int k=s; k<=e; ++k)
                            swap(X[k][s], X[k][e]);
                        for (int k=1; k<md; ++k) {
                            swap(X[s][s+k], X[s][e-k]);
                            swap(X[e][s+k], X[e][e-k]);
                        }
                        break;

                    case 3:
                        for (int k=s; k<e; ++k) {
                            swap(X[s][k], X[k][s]);
                            swap(X[e][k], X[k][e]);
                        }
                        break;

                    case 4:
                        for (int k=0; k<e-s; ++k) {
                            swap(X[s][s+k], X[e-k][e]);
                            swap(X[e-k][s], X[e][s+k]);
                        }
                        break;
                }
            }
        }

        for (int i=0; i<n; ++i) {
            printf("%d", X[i][0]);
            for (int j=1; j<n; ++j)
                printf(" %d", X[i][j]);
            putchar('\n');
        }
    }
}
