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

// ---------------------------------------------------------------------

vector<int> adj[1143];
int matchL[1143], matchR[1143];
bool seen[1143];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (matchR[v] < 0 || bpm(matchR[v])) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
    return false;
}

// http://www.immorlica.com/combOpt/lec1.pdf
void konig(int u) {
    matchL[u] = -1;
    for (int v: adj[u])
        if (!seen[v] && matchR[v]>=0) {
            seen[v] = 1;
            konig(matchR[v]);
        }
}

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (1) {
        int r = readUInt(),
            c = readUInt(),
            n = readUInt();
        if (r<=0 && c<=0 && n<=0)
            return 0;

        for (int i=0; i<=r; ++i)
            adj[i].clear();

        while (n--) {
            int u = readUInt()-1,
                v = readUInt()-1;
            adj[u].push_back(v);
        }

        int cnt = 0;
        memset(matchL, -1, r*sizeof(int));
        memset(matchR, -1, c*sizeof(int));
        for (int i=0; i<r; ++i) {
            memset(seen, 0, c);
            if (bpm(i)) ++cnt;
        }

        memset(seen, 0, c);
        for (int i=0; i<r; ++i)
            if (matchL[i]<0)
                konig(i);

        cout << cnt;
        for (int i=0; i<r; ++i)
            if (matchL[i]>=0)
                cout << " r" << i+1;

        for (int i=0; i<c; ++i)
            if (seen[i])
                cout << " c" << i+1;

        cout << '\n';
    }
}
