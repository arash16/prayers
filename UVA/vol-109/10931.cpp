/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10931
  Name: Parity
  Problem: https://onlinejudge.org/external/109/10931.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int parity(int n) {
    if (!n) return 0;

    int r = (n & 1) + parity(n >> 1);
    cout << (n & 1);
    return r;
}


int main() {
    int n;
    while (cin >> n && n) {
        cout << "The parity of ";
        int r = parity(n);
        cout << " is " << r << " (mod 2).\n";
    }
}