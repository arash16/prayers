/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10229
  Name: Modular Fibonacci
  Problem: https://onlinejudge.org/external/102/10229.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define Long long long

unsigned int mask;
struct Mat {
    int a, b, c, d;
    Mat (Long a, Long b, Long c, Long d): a(a&mask),b(b&mask),c(c&mask),d(d&mask) {}
    Mat operator *(const Mat& o) const {
        return Mat(a*o.a+b*o.c, a*o.b+b*o.d, c*o.a+d*o.c, c*o.b+d*o.d);
    }
};

Mat powmod(Mat mat, int n) {
    if (n==0) return Mat(1,0,1,0);
    if (n==1) return mat;

    Mat r = powmod(mat, n>>1);
    r = r*r;

    return n&1 ? r*mat : r;
}

int main() {
    int n, m;
    while (cin>>n>>m) {
        mask = (1<<m) - 1;
        cout << powmod(Mat(1,1,1,0), n).b << endl;
    }
}
