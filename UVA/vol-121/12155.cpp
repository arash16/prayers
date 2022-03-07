/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12155
  Name: ASCII Diamondi
  Problem: https://onlinejudge.org/external/121/12155.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

inline int abs(int x){ return x<0 ? -x : x; }
int main() {
    int n, r1, c1, r2, c2;
    for (int cse=1; scanf("%d%d%d%d%d", &n, &r1, &c1, &r2, &c2)==5 && n>0; cse++) {
        int sz = 2*n - 1,
            h = r2 - r1 + 1,
            w = c2 - c1 + 1;

        printf("Case %d:\n", cse);
        for (int i=r1; i<=r2; i++) {
            int d1 = abs(i - (sz*(i/sz)+n-1));
            for (int j=c1; j<=c2; j++) {
                int d = d1 + abs(j - (sz*(j/sz)+n-1));
                putchar(d<n ? 'a'+(d%26) : '.');
            }
            putchar('\n');
        }
    }
}
