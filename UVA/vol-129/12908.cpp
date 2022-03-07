/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12908
  Name: The book thief
  Problem: https://onlinejudge.org/external/129/12908.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int n; cin>>n && n; ) {
        int m = floor((sqrt(1 + 8*n)-1) / 2) + 1;
        cout << (m*(m+1)/2 - n) << ' ' << m << '\n';
    }
}
