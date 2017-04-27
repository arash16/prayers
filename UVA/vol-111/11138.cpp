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

// -------------------------------------------------------------------

vector<int> adj[555];
int matchR[555];
bool seen[555];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = true;
            if (matchR[v]<0 || bpm(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
    return false;
}


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        int n = readUInt(),
            m = readUInt();

        for (int i=0; i<n; ++i) {
            adj[i].clear();
            for (int j=0, x; j<m; ++j)
                if (readUInt())
                    adj[i].push_back(j);
        }

        int cnt = 0;
        memset(matchR, -1, m*sizeof(int));
        for (int i=0; i<n; ++i) {
            memset(seen, 0, m);
            if (bpm(i)) ++cnt;
        }

        cout << "Case " << cse << ": a maximum of " << cnt << " nuts and bolts can be fitted together\n";
    }
}
