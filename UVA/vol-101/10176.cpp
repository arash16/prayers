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


int main() {
    char ch;
    int d = 0;
    while ((ch=readchar())!=EOF) {
        if (ch == '#') {
            cout << (d ? "NO\n" : "YES\n");
            d = 0;
        }
        else if (isdigit(ch))
            d = (d*2 + ch-'0') % 131071;
    }
}
