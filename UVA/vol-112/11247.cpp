/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11247
  Name: Income Tax 
  Problem: https://onlinejudge.org/external/112/11247.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int m, x, v;
    while (scanf("%d%d", &m, &x)==2 && (m||x)) {
        long long v = (m-1)/(1-x/100.0) - 1e-3;
        if (v < m) puts("Not found");
        else printf("%lld\n", v);
    }
}
