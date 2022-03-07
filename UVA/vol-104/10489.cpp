/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10489
  Name: Boxes of Chocolates
  Problem: https://onlinejudge.org/external/104/10489.pdf
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


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int n = readUInt(),
            b = readUInt(),
            sum = 0;
        while (b--) {
            int k = readUInt(), x = 1;
            while (k--)
                x = (x * readUInt()) % n;
            sum += x;
        }
        cout << (sum % n) << endl;
    }
}
