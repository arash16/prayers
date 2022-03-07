/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10977
  Name: Enchanted Forest
  Problem: https://onlinejudge.org/external/109/10977.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
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

// ----------------------------------------------------------------

int dist2(int x1, int y1, int x2, int y2) {
    int xx = x1-x2,
        yy = y1-y2;

    return xx*xx + yy*yy;
}

struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d) {}
};

int dy[] = {0,0,1,-1},
    dx[] = {1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    bool B[217][217];
    memset(B, -1, sizeof(B));
    while ((n=readUInt())>0 && (m=readUInt())>0) {
        memset(B[n+1], -1, m+2);
        for (int i=1; i<=n; ++i) {
            memset(B[i]+1, 0, m);
            B[i][m+1] = 1;
        }

        int c = readUInt();
        for (int k=0; k<c; ++k) {
            int i = readUInt(),
                j = readUInt();
            B[i][j] = 1;
        }

        c = readUInt();
        for (int k=0; k<c; ++k) {
            int y = readUInt(),
                x = readUInt(),
                l = readUInt(),
                l2 = l*l;

            int mxy = min(n, y + l)+1,
                mxx = min(m, x + l)+1,
                mnx = max(1, x - l);
            for (int i=max(1, y- l); i<mxy; ++i)
                for (int j=mnx; j<mxx; ++j)
                    if (!B[i][j] && dist2(x, y, j, i)<=l2)
                        B[i][j] = 1;
        }

        if (!B[1][1] && !B[n][m]) {
            B[1][1]=1;
            queue<State> q;
            q.push(State(1,1,0));
            while (!q.empty()) {
                State s = q.front(); q.pop();
                for (int k=0; k<4; ++k) {
                    State t(s.i+dy[k], s.j+dx[k], s.d+1);
                    if (!B[t.i][t.j]) {
                        if (t.i==n && t.j==m) {
                            cout << t.d << endl;
                            goto fin;
                        }
                        B[t.i][t.j] = 1;
                        q.push(t);
                    }
                }
            }
        }
        cout << "Impossible.\n";
        fin:;
    }
}
