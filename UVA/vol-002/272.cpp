/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 272
  Name: TEX Quotes
  Problem: https://onlinejudge.org/external/2/272.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char ch;
    bool f = false;
    while (scanf("%c", &ch) == 1) {
        if (ch == '"') {
            cout << (f ? "''" : "``");
            f = !f;
        }
        else cout << ch;
    }
}
