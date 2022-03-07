/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 929
  Name: Number Maze
  Problem: https://onlinejudge.org/external/9/929.pdf
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

// ----------------------------------------------------------------

#define MAXN 1017

bool S[MAXN][MAXN];
int  D[MAXN][MAXN],
     X[MAXN][MAXN], n, m,
     dy[] = {0,0,1,-1},
     dx[] = {1,-1,0,0};

struct State {
    int i, j, d;
    State(int i, int j, int dd):i(i),j(j),d(-1){
        if (i>=0 && i<n && j>=0 && j<m) {
            d = dd + X[i][j];
            if (d < D[i][j])
                D[i][j] = d;
            else d = -1;
        }
    }
    bool operator < (const State &s) const { return d > s.d; }
    bool isvalid() { return d != -1; }
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        n = readUInt();
        m = readUInt();

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                X[i][j] = readUInt();
                D[i][j] = INF;
                S[i][j] = 0;
            }

        priority_queue<State> q;
        q.push(State(0,0,0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (s.i==n-1 && s.j==m-1) {
                cout << s.d << endl;
                break;
            }

            if (S[s.i][s.j]) continue;
            S[s.i][s.j] = true;

            for (int k=0; k<4; ++k) {
                State t(s.i+dy[k], s.j+dx[k], s.d);
                if (t.isvalid())
                    q.push(t);
            }
        }
    }
}
