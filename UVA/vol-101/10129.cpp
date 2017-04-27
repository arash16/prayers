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

inline int readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return 0;

    int l = 0;
    str[l++] = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        str[l++] = ch;
    str[l] = 0;
    return l;
}

// ------------------------------------------------------------------------

int E[26][26], I[26], O[26];
int dfs(int u) {
    int sum = 0;
    for (int v=0; v<26; ++v)
        if (E[u][v]) {
            --E[u][v];
            sum += dfs(v) + 1;
        }
    return sum;
}

bool check(int n) {
    int odd=0, st=-1, ste;
    for (int i=0; i<26; ++i)
        if (O[i] > I[i]) {
            if (++odd > 1)
                return false;
            st = i;
        }
        else if (O[i])
            ste = i;

    return dfs(st!=-1 ? st : ste) == n;
}


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    char str[1043];
    int T = readUInt();
    while (T--) {
        int n = readUInt();

        memset(E, 0, sizeof(E));
        memset(I, 0, sizeof(I));
        memset(O, 0, sizeof(O));
        for (int i=0; i<n; ++i) {
            int l = readStr(str),
                u = str[0] - 'a',
                v = str[l-1]-'a';

            ++E[u][v];
            ++O[u]; ++I[v];
        }

        cout << (check(n) ? "Ordering is possible.\n" : "The door cannot be opened.\n");
    }
}
