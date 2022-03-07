/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10970
  Name: Big Chocolate
  Problem: https://onlinejudge.org/external/109/10970.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int m, n;
    while (scanf("%d%d", &n, &m) == 2)
        cout << n*m - 1 << endl;
}