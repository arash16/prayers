/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11516
  Name: WiFi
  Problem: https://onlinejudge.org/external/115/11516.pdf
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

// ----------------------------------------------------------------------------

int X[100143], n, m;
bool check(int len) {
    int last = -(int)1e9,
        cnt = 0;
    for (int i=0; i<m; ++i)
        if (X[i]-last > len) {
            last = X[i] + len;
            if (++cnt > n) return 0;
        }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(1);

    int T = readUInt();
    while (T--) {
        n = readUInt();
        m = readUInt();
        for (int i=0; i<m; ++i)
            X[i] = readUInt() * 10;
        sort(X, X+m);

        int lo=0, hi=(X[m-1]-X[0]+n)/(2*n);
        while (lo <= hi) {
            int mid = (lo + hi)>>1;
            if (check(mid))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << (hi+1)/10.0 << '\n';
    }
}
