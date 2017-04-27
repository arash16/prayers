#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXP 1000009

int cnt = 1;
int primes[670000] = {2};

unsigned int prime[MAXP / 64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
void sieve() {
    memset(prime, -1, sizeof(prime));

    int i, sqrtN = sqrt((double)MAXP) + 1;
    for (i = 3; i < sqrtN; i += 2 ) if(gP(i)) {
        primes[cnt++] = i;
        int i2 = i<<1;
        for(int j = i * i; j < MAXP; j += i2)
            prime[j>>6] &= ~(1<<((j>>1)&31));
    }

    for (; i<MAXP; i+=2)
        if (gP(i))
            primes[cnt++] = i;
}


bool isPrime(int x) {
    return x==2 || (x>2 && x&1 && (gP(x)));
}


int main(){
    sieve();
    int n, i;
    while (cin>>n && n) {
        for (i=0; primes[i]*2 <= n; i++)
            if (isPrime(n - primes[i]))
                break;

        printf("%d:\n", n);
        if (2*primes[i] > n) puts("NO WAY!");
        else printf("%d+%d\n", primes[i], n-primes[i]);
    }
}
