#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define EPS 1e-9

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf)
            return EOF;
        p = buf;
    }
    return *p++;
}


bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline unsigned int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return 0;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return r;
}

// ---------------------------------------------------------------

int n, X[1000017];
int main() {
    while ((n=readUInt())) {
        for (int i=0; i<n; ++i)
            X[i] = readUInt();

        int mid = (n-1)>>1;
        nth_element(X, X+mid  , X+n);
        int a1 = X[mid], a2 = a1;
        if (n%2 == 0) {
            nth_element(X, X+mid+1, X+n);
            a2 = X[mid+1];
        }

        int cnt = 0;
        for (int i=0; i<n; ++i)
            if (X[i]==a1 || X[i]==a2)
                ++cnt;

        printf("%d %d %d\n", a1, cnt, a2-a1+1);
    }
}
