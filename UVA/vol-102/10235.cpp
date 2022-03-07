/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10235
  Name: Simply Emirp
  Problem: https://onlinejudge.org/external/102/10235.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1234567
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

int rev(int n) {
    int r = 0;
    while (n) {
        r = r*10 + n%10;
        n /= 10;
    }
    return r;
}


int main() {
    sieve();
    int n;
    while (cin>>n)
        if (!isPrime(n))
            printf("%d is not prime.\n", n);

        else {
            int r = rev(n);
            if(r==n || !isPrime(r))
                printf("%d is prime.\n", n);

            else printf("%d is emirp.\n", n);
        }
}
