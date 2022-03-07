/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11235
  Name: Frequent values
  Problem: https://onlinejudge.org/external/112/11235.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

inline int readchar() {
    const int N = 4194304;
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
    int i=48;
    buf[i--] = '\n';
    if (!x) buf[i--] = '0';
    for (; x; x/=10)
        buf[i--] = x%10 + '0';
    fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// --------------------------------------------------------------------

#define MAXN 100017
int F[MAXN][17], S[MAXN], E[MAXN], I[MAXN], cnt;
void initRMQ() {
    for (int j=1, tj; (tj=1<<j) <= cnt; ++j)
        for (int i=0; i <= cnt-tj; ++i)
            F[i][j] = max(
                F[ i ][ j-1 ],
                F[ i + (1<<(j-1)) ][ j-1 ]
            );
}

int findMax(int s, int e) {
    if (e < s) return 0;
    int j = log2(e-s+1);
    return max(
        F[s][j],
        F[e-(1<<j)+1][j]
    );
}

int main() {
    int n, m;
    while ((n=readInt()) && (m=readInt())) {
        cnt = 0;
        for (int i=0, lst, x; i<=n; ++i) {
            if (i < n) {
                x = readInt();
                if (!i) lst = x;
            }
            else x = !lst;

            if (i && x != lst) {
                F[cnt][0] = (E[cnt] = i) - S[cnt];
                S[++cnt] = i;
                lst = x;
            }
            I[i] = cnt;
        }

        initRMQ();

        for (int i=0; i<m; ++i) {
            int u = readInt() - 1,
                v = readInt() - 1;
            print(I[u] == I[v] ? v-u+1 :
                max(
                    max(
                        E[I[u]] - u,
                        v - S[I[v]] + 1
                    ),
                    findMax(I[u]+1, I[v]-1)
                )
            );
        }
    }
}
