#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long Int;

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
inline bool readUInt(Int &r) {
    char ch;
    r = 0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return 0;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    while (ch!=' ' && ch!='\n')
        ch = readchar();
    return 1;
}


int main() {
    for (Int n; readUInt(n); ) {
        Int cnt = n>>1;
        for (; n>1; cnt += n>>1)
            n = (n+1) >> 1;
        cout << cnt << endl;
    }
}
