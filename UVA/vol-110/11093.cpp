#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
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

// ----------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt(),
        p[100043], q[100043];
    for (int cse=1; cse<=T; ++cse) {
        int n = readUInt();
        for (int i=0; i<n; ++i)
            p[i] = readUInt();
        for (int i=0; i<n; ++i)
            q[i] = readUInt();

        cout << "Case " << cse << ": ";
        for (int i=0, k, j; i<n; i+=j+1) {
            int f = 0;
            for (j=0; j<n; ++j) {
                k = (i+j)%n;
                f += p[k] - q[k];
                if (f < 0) break;
            }
            if (j == n) {
                cout << "Possible from station " << i+1 << "\n";
                goto fin;
            }
        }
        cout << "Not possible\n";
        fin:;
    }
}
