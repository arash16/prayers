/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13212
  Name: How many inversions?
  Problem: https://onlinejudge.org/external/132/13212.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
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

// ------------------------------------------------------------------

long long cnt;
int X[1000143], L[1000143], R[1000143], n;
void merge(int l, int m, int r) {
    int n1 = m - l,
        n2 = r - m;

    for (int i=0; i<n1; ++i)
        L[i] = X[l + i];

    for (int j=0; j<n2; ++j)
        R[j] = X[m + j];

    L[n1] = R[n2] = INF;

    int i=0, j=0;
    for (int k=l; k<r; ++k)
        if (L[i] <= R[j])
            X[k] = L[i++];
        else {
            X[k] = R[j++];
            cnt += n1 - i;
        }
}

void mergesort(int l, int r) {
    if (l+1 >= r) return;
    int m = (l + r) >> 1;
    mergesort(l, m);
    mergesort(m, r);
    merge(l, m, r);
}

int main() {
    while ((n = readUInt())>0) {
        for (int i=0; i<n; ++i)
            X[i] = readUInt();

        cnt = 0;
        mergesort(0, n);
        cout << cnt << '\n';
    }
}
