/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10459
  Name: The Tree Root
  Problem: https://onlinejudge.org/external/104/10459.pdf
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

vector<int> adj[5543];
struct Edge {
    int u, d;
    Edge(int u, int d):u(u),d(d){}
};


bool inside[5543];
Edge dfs(int u) {
    inside[u] = true;

    Edge r(u, 0);
    for (int v: adj[u])
        if (!inside[v]) {
            Edge rr = dfs(v);
            if (++rr.d > r.d)
                r = rr;
        }

    inside[u] = false;
    return r;
}


int D[5543];
void dfs(int u, int d) {
    inside[u] = true;

    D[u] = max(D[u], d);
    for (int v: adj[u])
        if (!inside[v])
            dfs(v, d+1);

    inside[u] = false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while ((n=readUInt()) != EOF) {
        for (int u=0; u<n; ++u) {
            adj[u].resize(readUInt());
            for (int i=0; i<adj[u].size(); ++i)
                adj[u][i] = readUInt() - 1;
            D[u] = 0;
        }

        int u = dfs(0).u;
        Edge e = dfs(u);
        dfs(u, 0);
        dfs(e.u, 0);

        cout << "Best Roots  :";
        int dm1 = e.d>>1, dm2 = (e.d+1)>>1;
        for (int i=0; i<n; ++i)
            if (D[i] == dm1 || D[i] == dm2)
                cout << ' ' << i+1;
        cout << endl;

        cout << "Worst Roots :";
        for (int i=0; i<n; ++i)
            if (D[i] == e.d)
                cout << ' ' << i+1;
        cout << endl;
    }
}
