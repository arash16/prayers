#include <math.h>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

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
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-');
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

char buf[50];
void print(long long x) {
    int i=48, neg=0;
    buf[i--] = '\n';
    if (!x) buf[i--] = '0';
    else if (x < 0) {
        x = -x;
        neg = 1;
    }
    for (; x; x/=10)
        buf[i--] = x%10 + '0';

    if (neg) buf[i--] = '-';
    fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// -------------------------------------------------------------------

int n, m, Y[20000];
bool comp(int x, int y) {
    int md1 = x%m, md2 = y%m;
    if (md1 != md2) return md1 < md2;
    int eo1 = (2+x%2)&1, eo2 = (2+y%2)&1;
    return eo1 != eo2 ? eo1 > eo2 :
        eo1 ? x > y : x < y;
}

int main() {
    while ((n=readInt()) && (m=readInt())) {
        printf("%d %d\n", n, m);
        for (int i=0; i<n; ++i)
            Y[i] = readInt();

        sort(Y, Y+n, comp);
        for (int i=0; i<n; ++i)
            print(Y[i]);
    }
    puts("0 0");
}
