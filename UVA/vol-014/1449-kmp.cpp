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

// --------------------------------------------------------------------------

int lps[143];
int kmp(const char str[], const char pat[]) {
    int pl = 1;
    for (int l=0; pat[pl]; )
        if (pat[pl] == pat[l])
            lps[pl++] = ++l;
        else if (l > 0)
            l = lps[l-1];
        else lps[pl++] = 0;

    int cnt = 0;
    for (int i=0, j=0; str[i]; ) {
        if (str[i] == pat[j]) {
            ++i; ++j;
            if (j == pl) {
                ++cnt;
                j = lps[j-1];
            }
        }
        else if (j > 0)
            j = lps[j-1];
        else ++i;
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int doms[155], n;
    char pat[155][143], str[1000143];
    while ((n=readUInt())>0) {
        for (int i=0; i<n; ++i)
            readStr(pat[i]);

        readStr(str);
        int a = 0, sz = 0;
        for (int i=0; i<n; ++i) {
            int x = kmp(str, pat[i]);
            if (x > a) {
                a = x;
                sz = 1;
                doms[0] = i;
            }
            else if (x == a)
                doms[sz++] = i;
        }

        cout << a << '\n';
        for (int i=0; i<sz; ++i)
            cout << pat[doms[i]] << '\n';
    }
}
