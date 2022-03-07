/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 674
  Name: Coin Change
  Problem: https://onlinejudge.org/external/6/674.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int C[] = {1,5,10,25,50}, DP[10143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    DP[0] = 1;
    for (int i=0; i<5; ++i)
        for (int j=0; j<10043; ++j)
            DP[j+C[i]] += DP[j];

    int n;
    while (cin >> n)
        cout << DP[n] << "\n";
}
