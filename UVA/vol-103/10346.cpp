/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10346
  Name: Peter's Smokes
  Problem: https://onlinejudge.org/external/103/10346.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n, k;

    while (cin >> n >> k) {
        int c = n;
        while (n >= k) {
            c += n / k;
            n = n % k + n / k;
        }
        cout << c << endl;
    }
}