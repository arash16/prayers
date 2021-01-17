#include <bits/stdc++.h>
using namespace std;

#define N 100100100
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
void sieve() {
    memset(prime, -1, sizeof(prime));
    unsigned int i, i2, sqrtN = (unsigned int)sqrt((double)N) + 1;
    for(i = 3; i<sqrtN; i+=2)
        if(gP(i)) {
            i2 = i + i;
            for(unsigned int j = i*i; j<N; j+= i2)
                prime[j>>6] &= ~(1<<((j>>1)&31));
        }
}

bool isPrime(int n) {
    return n>1 && (n==2 || ((n&1) && gP(n)));
}

int findPrimes(int n){
  if (n%2 == 1) {
    return isPrime(n-2) ? 2 : -1;
  }

  int mid = n/2 - 1;
  if (mid % 2 == 0) --mid;
  for (int i=mid; i>1; i-=2)
    if (isPrime(i) && isPrime(n-i))
      return i;

  return -1;
}

char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);
	sieve();

	int n;
	while (cin >> n) {
	  int ii = findPrimes(n);
	  if (ii < 0) cout << n << " is not the sum of two primes!" << endl;
	  else cout << n << " is the sum of " << ii << " and " << (n-ii) << "." << endl;
	}
}
