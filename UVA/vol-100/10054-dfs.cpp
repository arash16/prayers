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

// -------------------------------------------------------------

int E[51][51], S[51];
void dfs(int u) {
    for (int v=1; v<=50; ++v)
        if (E[u][v]) {
            --E[u][v]; --E[v][u];
            dfs(v);
            cout << v << ' ' << u << "\n";
        }
}

char BUF[8000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 8000000);
    ios_base::sync_with_stdio(0);

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        int n = readUInt();

        if (cse > 1) cout << "\n";
        cout << "Case #" << cse << "\n";

        memset(E, 0, sizeof(E));
        memset(S, 0, sizeof(S));

        int mn = 100;
        for (int i=0; i<n; ++i) {
            int u = readUInt(),
                v = readUInt();
            ++E[u][v];
            ++E[v][u];
            ++S[u]; ++S[v];
            mn = min(mn, min(u, v));
        }

        bool bad=0;
        for (int u=1; u<=50; ++u)
            if (S[u]&1) {
                bad = 1;
                break;
            }

        if (bad) cout << "some beads may be lost\n";
        else dfs(mn);
    }
}
