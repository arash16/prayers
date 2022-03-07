/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10350
  Name: Liftless EME
  Problem: https://onlinejudge.org/external/103/10350.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
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
inline int readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return EOF;

    int l = 0;
    str[l++] = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        str[l++] = ch;
    str[l] = 0;
    return l;
}

// -----------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char title[143];
    int DP[121][16];
    while (readStr(title)>0) {
        cout << title << '\n';

        int n = readUInt(),
            m = readUInt();

        for (int k=0; k<n-1; ++k) {
            for (int i=0; i<m; ++i)
                DP[k+1][i] = INF;

            for (int i=0; i<m; ++i)
                for (int j=0; j<m; ++j)
                    DP[k+1][j] = min(DP[k+1][j], DP[k][i] + readUInt() + 2);
        }

        int mn = INF;
        for (int i=0; i<m; ++i)
            mn = min(mn, DP[n-1][i]);
        cout << mn << '\n';
    }
}
