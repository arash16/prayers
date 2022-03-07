/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1148
  Name: The mysterious X network
  Problem: https://onlinejudge.org/external/11/1148.pdf
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

// ----------------------------------------------------------------------

#define MAXQS 131072
class FastQueue {
    int data[MAXQS], l, r;
    public:
        FastQueue():l(0),r(0) {}
        void clear() { l=r=0; }
        bool empty() { return l==r; }
        void push(int x) { data[r++] = x; r&=MAXQS-1; }
        int pop(){ int result = data[l++]; l&=MAXQS-1; return result; }
        int front() { return data[l]; }
        int size() { return r>=l ? r-l : MAXQS-l+r; }
} q;

vector<int> adj[MAXQS];
int dist[MAXQS];

int main() {
    int T = readUInt();
    while (T--) {
        int n = readUInt();
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            dist[i] = -1;
        }

        for (int i=0; i<n; ++i) {
            int u = readUInt(),
                c = readUInt();

            for (int j=0; j<c; ++j) {
                int v = readUInt();
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        int src = readUInt(),
            dst = readUInt();
        q.clear();
        q.push(src);
        dist[src]=0;

        while (!q.empty()) {
            int u = q.pop();
            for (int v: adj[u])
                if (dist[v] < 0) {
                    if (v == dst) {
                        printf("%d %d %d\n", src, dst, dist[u]);
                        goto fin;
                    }
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
        }
        fin:
        if (T) putchar('\n');
    }
}
