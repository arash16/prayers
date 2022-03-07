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

template<class T>
class IndexQueue {
    int mind, maxd;
    vector<T> V[20000];

    public:
    IndexQueue() { mind=INF; maxd=-1; }

    bool empty() { return mind>maxd; }

    void clear() {
        for (int i=mind; i<=maxd; ++i)
            V[i].clear();
        mind=INF;
        maxd=-1;
    }

    void push(int key, T data) {
        V[key].push_back(data);
        if (key < mind) mind = key;
        if (key > maxd) maxd = key;
    }

    int top() { return mind; }
    int top(T& r) {
        r = V[mind].back();
        return mind;
    }

    T pop() {
        T r = V[mind].back();
        V[mind].pop_back();

        while (!empty() && V[mind].empty()) ++mind;
        if (empty()) clear();

        return r;
    }
};

// ----------------------------------------------------------------

#define MAXN 1017
int  R[MAXN], C[MAXN],
     D[MAXN][MAXN],
     X[MAXN][MAXN], n, m,
     dy[] = {0,0,1,-1},
     dx[] = {1,-1,0,0};

struct State {
    int i, j;
    State(int i, int j):i(i),j(j) {}
    bool isvalid() { return i>=0 && i<n && j>=0 && j<m; }
};

IndexQueue<State> q;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        n = readUInt();
        m = readUInt();

        for (int i=max(n, m); i>=0; --i)
            C[i]=R[i]=INF;

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                X[i][j] = readUInt();
                D[i][j] = (n+m)*9;

                C[j] = min(C[j], X[i][j]);
                R[i] = min(R[i], X[i][j]);
            }

        R[n] = C[m] = 0;
        for (int i=n-2; i>=0; --i)
            R[i] += R[i+1];

        for (int j=m-2; j>=0; --j)
            C[j] += C[j+1];


        q.clear();
        q.push(D[0][0] = X[0][0]+R[1]+C[1], State(0,0));
        while (!q.empty()) {
            int d = q.top();
            State s = q.pop();
            if (d != D[s.i][s.j]) continue;

            int ds = d - C[s.j+1] - R[s.i+1];
            if (s.i==n-1 && s.j==m-1) {
                cout << ds << endl;
                break;
            }

            for (int k=0; k<4; ++k) {
                State t(s.i+dy[k], s.j+dx[k]);
                if (t.isvalid()) {
                    int dd = X[t.i][t.j] + ds + R[t.i+1] + C[t.j+1];
                    if (dd < D[t.i][t.j])
                        q.push(D[t.i][t.j] = dd, t);
                }
            }
        }
    }
}
