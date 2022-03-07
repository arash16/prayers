/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10365
  Name: Blocks
  Problem: https://onlinejudge.org/external/103/10365.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> factors[1001];
    for (int i=1; i<1001; ++i)
        for (int j=1; j<=i; ++j)
            if (i % j == 0)
                factors[i].push_back(j);

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        int ms = (int)1e9;
        for (int i: factors[n])
            for (int j: factors[n/i]) {
                int k = (n/i)/j;
                ms = min(ms, (i*j + j*k + k*i)<<1);
            }
        cout << ms << "\n";
    }
}
