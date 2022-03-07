/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10469
  Name: To Carry or not to Carry
  Problem: https://onlinejudge.org/external/104/10469.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    long int x, y;
    while (cin >> x >> y)
        cout << (x ^ y) << endl;
}