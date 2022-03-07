/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11137
  Name: Ingenuous Cubrency
  Problem: https://onlinejudge.org/external/111/11137.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

long long DP[20000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    DP[0] = 1;
    for (int i=1, c; (c=i*i*i)<10000; ++i)
        for (int j=0; j<=10000; ++j)
            DP[j+c] += DP[j];

    int n;
    while (cin >> n)
        cout << DP[n] << "\n";
}
