#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL modular_pow(LL base, LL exponent, LL modulus) {
    if(modulus == 1) return 0;

    LL result = 1;
    base %= modulus;

    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % modulus;
        }

        exponent >>= 1;
        base = (base * base) % modulus;
    }

    return result;
}

bool isPrime(LL n, int iteration = 5) {     // Miller-Rabin primality test.
    if(n < 2) return false;
    if(n <= 3) return true;
    if(!(n & 1)) return false;              // If n is even.

    LL d = n-1;                             // d * 2^r = n-1 where d is odd and r > 0.
    while(!(d & 1))
        d >>= 1;

    while(iteration--) {                    // Witness loop.
        LL a = rand() % (n-1) + 1;
        LL x = modular_pow(a, d, n);        // x = a^d % n
        LL d1 = d;

        while(d1 != n-1 && x != 1 && x != n-1) {
            x = (x * x) % n;                // x = (x * x) % n.
            d1 <<= 1;
        }

        if(x != n-1 && !(d1 & 1)) {
            return false;
        }
    }

    return true;
}


int nextPrime(LL x, LL L, LL R) {
  if (x < 0) return -1;
  for (LL y = x+1; y<=R; ++y)
    if (isPrime(y))
      return y;
  return -1;
}


char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);

    int L, R;
    while (cin >> L >> R) {

      int ap, aq, bp, bq;
      int mn = 1e7;
      int mx = 0;

      for (
        int p = nextPrime(L-1, L, R), q = nextPrime(p, L, R);
        p>0 && q>0;
        p = q, q = nextPrime(p, L, R)
      ) {

        if (q-p < mn) {
          mn = q-p;
          ap = p;
          aq = q;
        }

        if (q-p > mx) {
          mx = q-p;
          bp = p;
          bq = q;
        }
      }

      if (!mx) cout << "There are no adjacent primes.\n" << flush;
      else cout << ap << ',' << aq << " are closest, "
                << bp << ',' << bq << " are most distant.\n" << flush;
    }
}
