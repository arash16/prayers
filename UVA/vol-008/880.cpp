/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 880
  Name: Cantor Fractions
  Problem: https://onlinejudge.org/external/8/880.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long n;
    while (cin >> n) { n--;
        long long y = (sqrt(8*n+1)-1)/2,
                  d = n - y*(y+1)/2;
        cout << (y + 1 - d) << '/' << (1 + d) << endl;
    }
}
