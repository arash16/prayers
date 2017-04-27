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

int n, p, D[100143];
vector<int> adj[100143];
bool comp(int u, int v) { return D[u] < D[v]; }

int dfs(int u) {
    if (adj[u].empty()) return 1;

    for (int v: adj[u])
        D[v] = dfs(v);

    int mid = ceil(adj[u].size() * (p/100.0));
    nth_element(adj[u].begin(), adj[u].begin()+mid, adj[u].end(), comp);

    int sum = 0;
    for (int i=0; i<mid; ++i)
        sum += D[adj[u][i]];
    return sum;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while ((n=readUInt())) {
        p = readUInt(); ++n;
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int i=1; i<n; ++i)
            adj[readUInt()].push_back(i);

        cout << dfs(0) << endl;
    }
}
