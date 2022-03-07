/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10596
  Name: Morning Walk
  Problem: https://onlinejudge.org/external/105/10596.pdf
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

// ---------------------------------------------------------------

int E[243][243], S[243], n, m;
vector<int> adj[243];

int dfs(int u) {
    int sum = 0;
    for (int v: adj[u])
        if (E[u][v]) {
            --E[u][v];
            --E[v][u];
            sum += dfs(v) + 1;
        }

    return sum;
}


bool check() {
    int st = -1;

    for (int i=0; i<n; ++i)
        if (S[i]) {
            if (S[i]&1)
                return 0;
            st = i;
        }
    return st>=0 && dfs(st) == m;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    while ((n=readUInt())!=EOF) {
        m = readUInt();
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            memset(E[i], 0, n*sizeof(int));
            S[i] = 0;
        }


        for (int i=0; i<m; ++i) {
            int u = readUInt(),
                v = readUInt();
            if (!E[u][v]) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            ++E[u][v]; ++S[u];
            ++E[v][u]; ++S[v];
        }
        cout << (check() ? "Possible\n" : "Not Possible\n");
    }
}
