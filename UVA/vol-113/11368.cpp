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

    return r;
}

// ------------------------------------------------------------------------------

struct Point {
    int x, y;
    bool operator < (const Point &o) const { return x!=o.x ? x<o.x : y>o.y; }
} P[20086];

int M[20086];
int LIS(int n) {
    int L = 0, mx=0;
    for (int i=0; i<n; ++i) {
        int y = P[i].y,
            lo = 1, hi = L;
        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            if (M[mid] >= y) {
                lo = mid + 1;
                if (mid==L || M[lo]<y) break;
            }
            else hi = mid - 1;
        }

        M[lo] = y;
        L = max(L, lo);
    }
    return L;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int n = readUInt();
        for (int i=0; i<n; ++i)
            P[i].x = readUInt(),
            P[i].y = readUInt();
        sort(P, P+n);
        cout << LIS(n) << "\n";
    }
}
