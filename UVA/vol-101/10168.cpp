/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10168
  Name: Summation of Four Primes
  Problem: https://onlinejudge.org/external/101/10168.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXP 10000090

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


int smallerize(int x) {
    int xh = x>>1;
    for (int i=0; primes[i]<=xh; i++)
        if (isPrime(x - primes[i]))
            return primes[i];

    return -1;
}


int main(){
    sieve();

    int n;
    while (cin>>n)
        if (n<8) cout<<"Impossible.\n";
        else {
            int ind = lower_bound(primes, primes+cnt, n-6) - primes;

            int a = primes[ind] <= n-6 ? primes[ind] : primes[ind-1],
                b = (n-a)&1 ? 3 : 2,
                c = smallerize(n-a-b),
                d = n-a-b-c;

            printf ("%d %d %d %d\n", a, b, c, d);
        }
}
