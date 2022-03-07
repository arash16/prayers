/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11039
  Name: Building designing
  Problem: https://onlinejudge.org/external/110/11039.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

inline int readchar() {
    const int N = 1048576;
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

// ------------------------------------------------------------------

inline int abs(int x) { return x<0 ? -x : x; }
inline bool comp(int x, int y) { return abs(x) > abs(y); }

int X[500017];
int main() {
    int T = readInt();
    while (T--) {
        int n = readInt();
        for (int i=0; i<n; ++i)
            X[i] = readInt();
        sort(X, X+n, comp);

        int cnt = 1, lst = X[0] < 0;
        for (int i=1; i<n; ++i)
            if (X[i]<0 != lst) {
                lst = !lst;
                ++cnt;
            }
        print(cnt);
    }
}
