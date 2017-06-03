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

// --------------------------------------------------------------------------------

int sgn(int x) {
    return x<0 ? -1 : 1;
}

int main() {
    int X[30313];
    int T = readInt();
    while (T--) {
        int n = readInt();
        for (int i=0; i<n; ++i)
            X[i] = readInt();

        int dir = 1, r = 0;
        for (int i=1; i<n; dir = -dir) {
            while (i<n && sgn(X[i]-X[i-1]) == dir) ++i;
            ++r;
        }
        cout << r << '\n';;
    }
}
