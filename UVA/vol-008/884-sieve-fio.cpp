/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 884
  Name: Factorial Factors
  Problem: https://onlinejudge.org/external/8/884.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

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

// ------------------------------------------------------------------------------------

const int MAXP = 1000003;
int C[MAXP];
int divcount(int n, int p) {
    int cnt = 0;
    while (1) {
        int r = n%p, q = n/p;
        if (r) break;
        n = q;
        ++cnt;
    }
    return cnt;
}

void sieve() {
    for (int i=2; i<MAXP; ++i)
        if (!C[i]) {
            C[i] = 1;
            for (int j=i+i; j<MAXP; j+=i)
                C[j] += divcount(j, i);
        }
    for (int i=1; i<MAXP; ++i)
        C[i] += C[i-1];
}


int main() {
    sieve();

    int n;
    while ((n=readUInt()) != EOF)
        cout << C[n] << '\n';
}
