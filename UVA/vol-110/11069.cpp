/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11069
  Name: A Graph Problem
  Problem: https://onlinejudge.org/external/110/11069.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int DP[77] = { 0, 1, 2, 2 };
    for (int i=4; i<77; ++i)
        DP[i] = DP[i-2] + DP[i-3];

    int n;
    while (cin >> n)
        cout << DP[n] << endl;
}
