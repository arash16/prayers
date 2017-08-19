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
inline int readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return EOF;

    int l = 0;
    str[l++] = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        str[l++] = ch;
    str[l] = 0;
    return l;
}

// ----------------------------------------------------------------------

int S[100143][10], F[100143], scnt;
bool insertWord(char num[]) {
    int cur = 0;
    bool result;
    for (int i=0; num[i]; ++i) {
        int d = num[i]-'0';
        result = !S[cur][d];
        if (result) {
            S[cur][d] = ++scnt;
            F[scnt] = false;
            memset(S[scnt], 0, 10*sizeof(int));
        }
        cur = S[cur][d];
        if (F[cur]) return false;
    }
    F[cur] = true;
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int n = readUInt();
        memset(S[scnt = 0], 0, 10*sizeof(int));

        char num[17];
        bool consistent = true;
        for (int i=0; i<n; ++i) {
            readStr(num);
            consistent = consistent && insertWord(num);
        }
        cout << (consistent ? "YES\n" : "NO\n");
    }
}
