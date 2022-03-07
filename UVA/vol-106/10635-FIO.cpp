/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10635
  Name: Prince and Princess
  Problem: https://onlinejudge.org/external/106/10635.pdf
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
    static bool fin = 0;
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
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return EOF;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

// =================================================================

int I[73000], X[73000], M[73000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readInt();
    for (int cse=1; cse <= T; ++cse) {
        int n = readInt(),
            p = readInt() + 1,
            q = readInt() + 1;
        n = n*n;

        memset(I, -1, sizeof(I));
        for (int i=0; i<p; ++i)
            I[readInt()] = i;

        int L = 0;
        for (int j=0; j<q; ++j) {
            X[j] = readInt();
            if (I[X[j]] == -1) continue;

            int lo = 1, hi = L;
            while (lo <= hi) {
                int mid = (lo + hi + 1) >> 1;
                if (I[X[M[mid]]] < I[X[j]])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            M[lo] = j;
            L = max(L, lo);
        }

        cout << "Case " << cse << ": " << L << '\n';
    }
}
