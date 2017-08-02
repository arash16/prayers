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

inline bool readBool() {
    char ch;
    while ((ch=readchar())!='c' && ch!='i');
    return ch == 'c';
}

// ---------------------------------------------------------------



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int Q = readUInt();

        int D1[10] = {}, D2[10] = {};
        for (int i=0; i<Q; ++i) {
            int d = readUInt()-1,
                s = readUInt(),
                c = readBool();

            if (s && c)
                ++D1[d];

            else if (!s && !c)
                ++D2[d];
        }

        int sum = 0;
        for (int i=0; i<10; ++i)
            for (int j=0; j<i; ++j)
                sum += D1[i] * D2[j];
        cout << sum << endl;
    }
}
