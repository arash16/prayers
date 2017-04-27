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

//---------------------------------------------------------------

#define MAXC 1000000043
int *nxt, SC;
void insertW(char s[], long long cur=0) {
    for (int i=0; s[i]; ++i) {
        char d = s[i]-'0';
        long long ind = cur*10+d;
        if (!nxt[ind]) {
             nxt[ind] = ++SC;
             if (SC >= MAXC) while(1);
            memset(nxt+SC*10, 0, 40);
        }
        cur = nxt[ind];
    }
}

int sumW(int x, long long cur=0) {
    int sum = x;
    for (int i=0; i<10; ++i)
        if (nxt[cur*10+i])
            sum = (sum + sumW((x*10+i)%2012, nxt[cur*10+i])) % 2012;

    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    nxt = new int[MAXC*10];

    int n;
    char s[200043];
    while ((n=readUInt())!=EOF) {
        memset(nxt, SC=0, 40);
        for (int i=0; i<n; ++i) {
            int l = readStr(s);
            for (int j=0; s[j]; ++j)
                if (s[j]!='0')
                    insertW(s+j);
        }

        cout << sumW(0) << endl;
    }
}
