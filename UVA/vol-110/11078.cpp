/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11078
  Name: Open Credit System
  Problem: https://onlinejudge.org/external/110/11078.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

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

char buf[50];
void print(long long x) {
    int i=48, neg=0;
    buf[i--] = '\n';
    if (!x) buf[i--] = '0';
    else if (x < 0) {
        x = -x;
        neg = 1;
    }
    for (; x; x/=10)
        buf[i--] = x%10 + '0';

    if (neg) buf[i--] = '-';
    fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// -----------------------------------------------------------

int main() {
    int T = readInt();
    while (T--) {
        int n = readInt(),
            x = readInt(),
            mx = readInt(),
            di = x - mx;

        if (x > mx) mx = x;
        for (int i=2; i<n; ++i) {
            x = readInt();
            if (mx - x > di)
                di = mx - x;

            if (x > mx) mx = x;
        }

        print(di);
    }
}
