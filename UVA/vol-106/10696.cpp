/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10696
  Name: f91
  Problem: https://onlinejudge.org/external/106/10696.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int p[101];
int f(int x) {
    if (x > 100) return x - 10;
    if (p[x]) return p[x];
    return p[x] = f(f(x + 11));
}

int main() {
    int n;
    while ((cin >> n) && n)
        printf("f91(%d) = %d\n", n, f(n));
}
