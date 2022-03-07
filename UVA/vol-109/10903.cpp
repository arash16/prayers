/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10903
  Name: Rock-Paper-Scissors Tournament
  Problem: https://onlinejudge.org/external/109/10903.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 41943040;
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

char readFirstChar() {
    char ch, th;
    while ((ch=readchar())==' ');
    while ((th=readchar())!=' ' && th!='\n');
    return ch;
}

// -----------------------------------------------------------------------


char BUF[8000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 8000000);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    bool wins[127][127] = {};
    wins['r']['s'] =
    wins['s']['p'] =
    wins['p']['r'] = true;

    bool frst = 1;
    while (true) {
        int n = readUInt(),
            k = readUInt();
        if (n<0 || k<0) break;

        if (frst) frst = 0;
        else cout << '\n';

        int sz = n*(n-1)*k/2;
        int W[101] = {}, L[101] = {};
        for (int i=0; i<sz; ++i) {
            int p1 = readUInt()-1;
            char m1 = readFirstChar();
            int p2 = readUInt()-1;
            char m2 = readFirstChar();

            if (wins[m1][m2]) ++W[p1], ++L[p2];
            if (wins[m2][m1]) ++W[p2], ++L[p1];
        }

        for (int i=0; i<n; ++i) {
            double q = W[i] + L[i];
            if (!q) cout << "-\n";
            else cout << W[i]/q << '\n';
        }
    }
}
