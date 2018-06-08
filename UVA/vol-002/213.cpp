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

inline char readNonBlankChar() {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return EOF;
    return ch;
}

inline int readLine(char *str) {
    int len=0;
    char ch;
    while ((ch=readchar())!='\n' && ch!=EOF)
        str[len++] = ch;

    str[len] = 0;
    if (ch == EOF && !len) return EOF;
    return len;
}


int readBin(int len) {
    int r = 0;
    while (len--)
        r = (r<<1) | (readNonBlankChar() == '1');
    return r;
}

int main() {
    char H[1024];
    int S[] = { 0, 1, 4, 11, 26, 57, 120, 247, 502, 1013 };
    while (readLine(H) != EOF) {
        if (!H[0]) continue;

        int l, x;
        while ( (l = readBin(3)) > 0 ) {
            int fin = (1 << l) - 1;
            while ( (x = readBin(l)) != fin && x!=EOF )
                cout << H[S[l-1] + x];
        }
        cout << endl;
        while (readchar()!='\n');
    }
}
