/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10812
  Name: Beat the Spread!
  Problem: https://onlinejudge.org/external/108/10812.pdf
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

    while(n--) {
        int s, d;
        cin >> s >> d;
        if (d > s || ((s + d) % 2))
            cout << "impossible\n";
        else
            cout << (s + d)/2 << " " << (s - d)/2 << endl;
    }
}
