/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11332
  Name: Summing Digits
  Problem: https://onlinejudge.org/external/113/11332.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
    int n;
    while ((cin >> n) && n) {
        while (n > 9) {
            int s = 0;
            while (n) {
                s += n % 10;
                n /= 10;
            }
            n = s;
        }
        cout << n << endl;
    }
}
