/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11461
  Name: Square Numbers
  Problem: https://onlinejudge.org/external/114/11461.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int cum[100001] = { 1, 2 };
int main() {
    for (int i = 1, j = 0, c = 0; j < 100001; i++)
        for (c++; j < i*i && j < 100001; j++)
            cum[j] = c;

    int a, b;
    while ((cin >> a >> b) && a)
        cout << cum[b] - cum[a - 1] << endl;
}