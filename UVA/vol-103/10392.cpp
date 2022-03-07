/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10392
  Name: Factoring Large Numbers
  Problem: https://onlinejudge.org/external/103/10392.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool isnp[1000143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> primes;
    for (int i=2; i<1000143; ++i)
        if (!isnp[i]) {
            for (int j=i+i; j<1000143; j+=i)
                isnp[j] = 1;
            primes.push_back(i);
        }

    long long n;
    while (cin >> n && n>=0) {
        for (int p: primes) {
            if (p > n) break;
            while (n % p == 0) {
                cout << "    " << p << '\n';
                n /= p;
            }
        }
        if (n > 1)
            cout << "    " << n << '\n';
        cout << '\n';
    }
}
