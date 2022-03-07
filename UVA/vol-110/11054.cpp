/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11054
  Name: Wine trading in Gergovia
  Problem: https://onlinejudge.org/external/110/11054.pdf
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

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline long long readInt() {
    char ch;
    long long sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return EOF;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

// ---------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while ((n=readInt()) > 0) {
        long long b = readInt(), s = 0;
        for (int i=1; i<n; ++i) {
            s += abs(b);
            b += readInt();
        }
        cout << s << '\n';
    }
}
