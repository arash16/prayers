/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11310
  Name: Delivery Debacle
  Problem: https://onlinejudge.org/external/113/11310.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long DP[43] = { 1, 1, 5 };
    for (int i=3; i<43; ++i)
        DP[i] = DP[i-1] + 4*DP[i-2] + 2*DP[i-3];

    int T, n;
    cin >> T;
    while (T-- && cin>>n)
        cout << DP[n] << '\n';
}
