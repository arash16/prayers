/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1644
  Name: Prime Gap
  Problem: https://onlinejudge.org/external/16/1644.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

bool isnp[1299710];
int primes[100143], ins[1299710], pnt;
void sieve() {
    isnp[0] = isnp[1] = 1;
    for (int i=2; i<=1299709; ++i)
        if (!isnp[i]) {
            primes[pnt++] = i;
            for (int j=i<<1; j<=1299709; j+=i)
                isnp[j] = 1;
        }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve();
    for (int j=2, k=-1; j<=1299709; ++j) {
        if (!isnp[j]) ++k;
        ins[j] = k;
    }

    int n;
    while (cin >> n && n)
        if (!isnp[n]) cout << "0\n";
        else {
            int ind = ins[n];
            cout << primes[ind+1]-primes[ind] << '\n';
        }
}
