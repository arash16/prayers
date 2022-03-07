/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 906
  Name: Rational Neighbor
  Problem: https://onlinejudge.org/external/9/906.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a%b);
}

int main(){
    int a, b;
    double n;

    while (scanf("%d%d%lf", &a, &b, &n)==3) {
        int gg = gcd(a, b); a/=gg; b/=gg;

        double bna = b*n+a;
        for (int d=1; ; d++) {
            int c = bna*d / b;
            if (c*b > a*d) {
                printf("%d %d\n", c, d);
                break;
            }
        }
    }
}
