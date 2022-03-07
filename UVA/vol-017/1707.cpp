/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1707
  Name: Surveillance
  Problem: https://onlinejudge.org/external/17/1707.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

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

// --------------------------------------------------------------------------

#define MAXN 2000170
int n, A[MAXN], B[MAXN], J[23][MAXN];

int main() {
    while ((n=readUInt()) != EOF) {
        int k = readUInt(),
            ln = log2(k)+1,
            n2 = (n<<1);
        memset(J[0], 0, n2*sizeof(int));
        J[0][n2] = n2;

        for (int i=0; i<k; ++i) {
            A[i] = readUInt()-1;
            B[i] = readUInt()-1;
            if (B[i] < A[i]) {
                B[i] += n;
                J[0][n+A[i]] = n2;
            }
            else
            J[0][n+A[i]] = max(J[0][n+A[i]], n+B[i]+1);
            J[0][A[i]] = max(J[0][A[i]], B[i]+1);
        }

        vector<int> ev;

        int lst = -1;
        for (int i=0; i<n2; ++i) {
            if (J[0][i] > lst) {
                ev.push_back(i);
                lst = J[0][i];
            }
            J[0][i] = lst>i ? lst : 0;
        }

        for (int j=1; j<=ln; ++j)
            for (int i=0; i<=n2; ++i)
                J[j][i] = J[j-1][ J[j-1][i] ];

        int result = MAXN;
        for (int s: ev) if (J[ln][s]-s>=n) {
            int pos = s,
                cnt = 0;
            for (int j=ln; j>=0; --j)
                if (J[j][pos]-s < n) {
                    pos = J[j][pos];
                    cnt |= 1<<j;
                }

            result = min(result, cnt+1);
        }

        if (result == MAXN)
             puts("impossible");
        else printf("%d\n", result);
    }
}
