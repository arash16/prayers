/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11567
  Name: Moliu Number Generator
  Problem: https://onlinejudge.org/external/115/11567.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    unsigned int n;
    while (cin >> n) {
        int cnt = 0;
        for (; n; ++cnt)
            if (n&1)
                if (n>3 && n&2) ++n;
                else --n;
            else n >>= 1;
        cout << cnt << endl;
    }
}
