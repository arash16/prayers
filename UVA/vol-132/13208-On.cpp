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

// -----------------------------------------------------------------------------


long long C[10143];
int H[10143], Hl[10143], Hr[10143], X[10143];
int main() {
    int T = readUInt();
    while (T--) {
        int a = readUInt(),
            n = readUInt();

        for (int i=1; i<=n; ++i)
            C[i] = C[i-1] + (X[i] = readUInt());

        int mxi = 0;
        for (int j=0; j<=n; ++j) {
            H[j] = readUInt();
            Hl[j] = mxi = H[mxi] > H[j] ? mxi : j;
        }

        mxi = n;
        for (int j=n; j>=0; --j)
            Hr[j] = mxi = H[mxi] > H[j] ? mxi : j;

        long long sum = 0;
        for (int i=mxi; i<n; ) {
            int ni = Hr[i+1];
            sum += (C[ni]-C[i]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        for (int i=mxi; i>0; ) {
            int ni = Hl[i-1];
            sum += (C[i]-C[ni]) * min(H[i], H[ni]) * a;
            i = ni;
        }

        cout << sum << '\n';
    }
}
