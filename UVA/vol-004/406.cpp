#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10002
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
    return n==2 || ((n&1) && gP(n));
}



int main(){
    sieve();
    vector<int> primes;
    primes.push_back(1);
    for(int i=2; i<1001; i++)
        if (isPrime(i))
            primes.push_back(i);

    int n, c;
    while (cin>>n>>c) {
        int p = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
        if (primes[p] != n) p--;
        int off = ceil((p-2*c+1)/2.0),
            cnt = 2*c - (p%2?0:1);

        printf("%d %d:", n, c);

        if (off<=0) {
            off=0;
            cnt=p+1;
        }

        for (int i=0; i<cnt; i++)
            printf(" %d", primes[off+i]);

        cout<<endl<<endl;
    }
}
