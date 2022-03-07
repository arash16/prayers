/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11547
  Name: Automatic Answer
  Problem: https://onlinejudge.org/external/115/11547.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        x = (x * 63 + 7492) * 5 - 498;
        if (x < 0) x = -x;
        cout << (x / 10) % 10 << endl;
    }
}
