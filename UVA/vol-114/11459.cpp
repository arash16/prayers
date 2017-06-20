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

// ------------------------------------------------------------------

char BUF[8000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 8000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int P[1000143];
    int T = readUInt();
    while (T--) {
        int p = readUInt(),
            m = readUInt(),
            n = readUInt();

        for (int i=0; i<p; ++i)
            P[i] = 1;

        int J[117] = {};
        for (int i=0; i<m; ++i) {
            int u = readUInt(),
                v = readUInt();
            J[u] = v;
        }

        bool fin = 0;
        for (int i=0, k=0; i<n; ++i) {
            int die = readUInt();
            if (fin) continue;

            P[k] += die;
            if (J[P[k]])
                P[k] = J[P[k]];

            if (P[k] >= 100) {
                P[k] = 100;
                fin = 1;
            }

            if (++k == p) k = 0;
        }

        for (int i=0; i<p; ++i)
            cout << "Position of player " << (i+1) << " is " << P[i] << ".\n";
    }
}
