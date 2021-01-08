#include <bits/stdc++.h>
using namespace std;

#define MAXP 46350

vector<unsigned> primes;

bool isNotPrime[MAXP] = { true, true, false };
void sieve() {
  for (unsigned i=2; i<MAXP; i++)
    if (!isNotPrime[i]) {
      primes.push_back(i);
      for (unsigned j=i*i; j<MAXP; j += i)
        isNotPrime[j] = true;
    }
}

bool isPrime[1000005];
void sieve2(unsigned L, unsigned R) {
  memset(isPrime, 1, R-L+5);
  for (unsigned p: primes) {
    if (p*p > R) break;

    unsigned j = max(p*p, L);
    while (j<=R && (j%p)) ++j;
    for (; j<=R; j+=p) isPrime[j-L] = false;
  }
}

int nextPrime(long long x, unsigned L, unsigned R) {
  if (x < 0) return -1;

  for (unsigned y = x+1; y<=R; ++y)
    if (y>=2 && isPrime[y-L])
      return y;
  return -1;
}


char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);

	sieve();

    int L, R;
    while (cin >> L >> R) {
      sieve2(L, R);

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

      if (!mx) cout << "There are no adjacent primes.\n";
      else cout << ap << ',' << aq << " are closest, "
                << bp << ',' << bq << " are most distant.\n";
    }
}
