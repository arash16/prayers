#include <bits/stdc++.h>
using namespace std;

#define MAXP 46350

bool isNotPrime[MAXP] = { true, true, false };
vector<int> primes;

void sieve() {
  for (int i=2; i<MAXP; i++)
    if (!isNotPrime[i]) {
      primes.push_back(i);
      for (int j=i+i; j<MAXP; j += i)
        isNotPrime[j] = true;
    }
}

bool isPrime(int x) {
  if (x < MAXP)
    return !isNotPrime[x];

  for (int i=0, sq = sqrt(x); i<primes.size() && primes[i] <= sq; ++i)
    if (x % primes[i] == 0)
      return false;

  return true;
}

int nextPrime(int x, int mx) {
  if (x >= mx) return -1;
  for (int y = x+1; y<=mx; ++y)
    if (isPrime(y))
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
      int ap, aq, bp, bq;
      int mn = 1e7;
      int mx = 0;

      for (
        int p = nextPrime(L-1, R), q = nextPrime(p, R);
        p>0 && q>0;
        p = q, q = nextPrime(p, R)
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
