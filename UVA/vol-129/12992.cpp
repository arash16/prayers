/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12992
  Name: Huatuo's Medicine
  Problem: https://onlinejudge.org/external/129/12992.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    for (int cse=1; T-- && cin >> n; ++cse)
        cout << "Case #" << cse << ": " << 2*n-1 << '\n';
}
