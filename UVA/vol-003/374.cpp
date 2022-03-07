/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 374
  Name: Big Mod
  Problem: https://onlinejudge.org/external/3/374.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int powmod(int b, int p, int m) {
    if (!p) return 1;
    if (p == 1) return b % m;

    int half = powmod(b, p / 2, m);
    int result = (half * half) % m;

    return p % 2 ? (result * b) % m : result;
}

int main() {
    int b, p, m;
    while (cin >> b >> p >> m)
        cout << powmod(b % m, p, m) << endl;
}