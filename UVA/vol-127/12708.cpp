/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12708
  Name: GCD The Largest
  Problem: https://onlinejudge.org/external/127/12708.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    long long n;
    while (T-- && cin >> n)
        cout << (n >> 1) << '\n';
}
