/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11799
  Name: Horror Dash
  Problem: https://onlinejudge.org/external/117/11799.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int C;
    cin >> C;
    for (int c = 1; c <= C; c++) {
        int n, x; cin >> n;
        int max = 0;
        while (n--) {
            cin >> x;
            if (x > max) max = x;
        }

        printf("Case %d: %d\n", c, max);
    }
}