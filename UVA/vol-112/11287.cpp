/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11287
  Name: Pseudoprime Numbers
  Problem: https://onlinejudge.org/external/112/11287.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool isPrime(int x) {
    for (int i=2; i*i <= x; ++i)
        if (x%i == 0)
            return 0;
    return 1;
}

int powmod(int a, int b, int m) {
    if (!b) return 1;
    if (b==1) return a%m;

    long long r = powmod(a, b>>1, m);
    r = (r*r) % m;
    if (b&1) r = (r*a) % m;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int p, m; cin >> p >> m && (p||m); )
        cout << (isPrime(p) || powmod(m, p, p)!=m%p ? "no\n" : "yes\n");
}
