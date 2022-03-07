/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11466
  Name: Largest Prime Divisor
  Problem: https://onlinejudge.org/external/114/11466.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

long long mod_mul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}
long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = mod_mul(ans, a, mod);
    a = mod_mul(a, a, mod);
    exp >>= 1;
  }
  return ans;
}
const int rounds = 20;
bool witness(long long a, long long n) {
  long long u = n - 1;
  int t = 0;
  while (u % 2 == 0) {
    t++;
    u >>= 1;
  }
  long long next = mod_pow(a, u, n);
  if (next == 1) return false;
  long long last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    if (next == 1) {
      return last != n - 1;
    }
  }
  return next != 1;
}
bool miller_rabin(long long n, int it = rounds) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) {
    long long a = rand() % (n - 1) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}

// ----------------------------------------------------------------------

bool np[10000143] = {1, 1};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    long long n, r;
    while (cin >> n && n) {
        if (n < 0) n = -n;
        int sq = sqrt(n), c=0;
        if (!miller_rabin(n)) {
            for (int i=2; i<=sq; ++i)
                if (n%i == 0) {
                    while (n%i == 0)
                        n /= i;
                    r = i;
                    ++c;
                    if (miller_rabin(n)) break;
                    sq = sqrt(n);
                }

            if (n > 1) ++c;
            if (n > r) r = n;
        }

        cout << (c>1 ? r : -1) << '\n';
    }
}
