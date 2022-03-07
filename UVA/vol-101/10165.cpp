/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10165
  Name: Stone Game
  Problem: https://onlinejudge.org/external/101/10165.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    while (cin >> n && n>0) {
        int s = 0;
        for (int i=0; i<n; ++i) {
        cin >> x;
        s ^= x;
    }
    cout << (s ? "Yes\n" : "No\n");
    }
}
