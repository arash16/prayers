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
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return EOF;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}
inline bool readDouble(double &r) {
    char ch;
    int sgn=1;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF)
            return 0;

    r = 0;
    if (ch!='.') {
        if (ch == '-') sgn = -1;
        else r = ch-'0';
        while (isdigit(ch=readchar()))
            r = r*10 + ch-'0';
    }

    if (ch=='.') {
        double p = 1;
        while (isdigit(ch=readchar()))
            r += (ch-'0') * (p *= 0.1);
    }

    if (ch=='e' || ch=='E') {
        double p10 = readInt();
        r *= pow(10, p10);
    }

    return 1;
}

// ---------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(5);

    int n, a;
    while ((n = readInt())>0) {
        int a = readInt();
        double x, y;
        int a2 = a*a, m = 0;
        for (int i=0; i<n; ++i) {
            readDouble(x);
            readDouble(y);
            double ax = a-x, ay=a-y,
                x2=x*x, ax2=ax*ax, y2=y*y, ay2=ay*ay;
            if (x2+y2 <= a2 && ax2+y2 <= a2 && x2+ay2 <= a2 && ax2+ay2 <= a2)
                ++m;
        }

        cout << double(m)*a2/n << '\n';
    }
}
