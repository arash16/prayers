/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11498
  Name: Division of Nlogonia
  Problem: https://onlinejudge.org/external/114/11498.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int k;
    while ((cin >> k) && k) {
        int x, y, a, b;
        cin >> x >> y;
        while (k--) {
            cin >> a >> b;
            if (a == x || b == y)
                cout << "divisa\n";
            else cout << (b < y ? "S" : "N") << (a < x ? "O" : "E") << endl;
        }
    }
}