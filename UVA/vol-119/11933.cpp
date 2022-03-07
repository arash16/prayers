/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11933
  Name: Splitting Numbers
  Problem: https://onlinejudge.org/external/119/11933.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

int main() {
    int n, a, b, t;
    while (scanf("%d", &n)==1 && n) {
        a = b = 0;
        while (n) {
            t = n & -n;
            a |= t;
            n -= t;
            t = n & -n;
            b |= t;
            n -= t;
        }
        printf("%d %d\n", a, b);
    }
}
