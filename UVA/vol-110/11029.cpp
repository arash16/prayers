/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11029
  Name: Leading and Trailing
  Problem: https://onlinejudge.org/external/110/11029.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int powmod(long long a, long long b, int modul) {
    if (!b) return 1;
    int h = powmod(a, b/2, modul); h *= h;
    return (b%2 ? h*a : h) % modul;
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  while (T--) {
    long long n, k; 
    cin >> n >> k;

    int digits = ceil(k*log10(n));
    int hi = floor(pow(10, k*log10(n) - (digits - 3)));
    int lo = powmod(n, k, 1000);
    printf("%03d...%03d\n", hi, lo);
  }
}
