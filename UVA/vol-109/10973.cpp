#include <bits/stdc++.h>
using namespace std;


inline int readchar(bool skip=true) {
    const int N = 4194304;
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

// ------------------------------------------------------------------------------

int mat[3013][3013], used[3013][3013];
vector<int> adj[3013];
int main() {
    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        int n = readUInt(),
            m = readUInt();

        for (int i=0; i<n; ++i)
            adj[i].clear();

        while (m--) {
            int u = readUInt()-1,
                v = readUInt()-1;

            if (u > v) swap(u, v);
            adj[u].push_back(v);
            mat[u][v] = cse;
            used[u][v] = 0;
        }

        int result = 0;
        for (int u=0; u<n; ++u)
            for (int v: adj[u]) {
                int &cnt = used[u][v];
                if (cnt < 2)
                for (int w: adj[v])
                    if (mat[u][w] == cse) {
                        ++result;
                        ++used[v][w];
                        ++used[u][w];
                        if (++cnt >= 2)
                            break;
                    }
            }
        cout << result << '\n';
    }
}
