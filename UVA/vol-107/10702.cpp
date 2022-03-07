/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10702
  Name: Travelling Salesman
  Problem: https://onlinejudge.org/external/107/10702.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;

inline int readchar() {
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
    return *p++;
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

// ------------------------------------------------------------------------


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int D[1043][143], W[143][143], n;
    while ((n=readUInt())>0) {
        int src = readUInt(),
            dn = readUInt(),
            m = readUInt();

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                W[i][j] = readUInt();

        memset(D[0], -1, sizeof(D));
        D[0][src-1] = 0;
        for (int i=1; i<=m; ++i) {
            memset(D[i], -1, n*sizeof(int));
            for (int u=0; u<n; ++u)
            if (D[i-1][u]!=-1)
                for (int v=0; v<n; ++v)
                if (u!=v)
                    D[i][v] = max(D[i][v], D[i-1][u]+W[u][v]);
        }

        int mx = 0;
        for (int i=0, e; i<dn; ++i)
            mx = max(mx, D[m][readUInt()-1]);
        cout << mx << endl;
    }
}
