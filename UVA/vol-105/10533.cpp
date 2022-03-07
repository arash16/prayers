/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10533
  Name: Digit Primes
  Problem: https://onlinejudge.org/external/105/10533.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


#define MAXP 1000064
int P[5+MAXP] = {0,0,1};

int dsum(int x) {
    int r = 0;
    for (; x; x/=10)
        r += x%10;
    return r;
}

unsigned int prime[MAXP / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))

bool isPrime(int x) {
    return x==2 || (x>2 && x&1 && (gP(x)));
}

void sieve() {
    memset(prime, -1, sizeof(prime));

    int i, sqrtN = sqrt((double)MAXP) + 1;
    for (i = 3; i < sqrtN; i += 2 ) {
        if (gP(i)) {
            P[i] = P[i-1] + isPrime(dsum(i));

            int i2 = i<<1;
            for(int j = i * i; j < MAXP; j += i2)
                prime[j>>6] &= ~(1<<((j>>1)&31));
        }
        else P[i] = P[i-1];
        P[i+1] = P[i];
    }

    for (; i<MAXP; i+=2)
        P[i+1] = P[i] = P[i-1] + (gP(i) && isPrime(dsum(i)));
}


int main(){
    sieve();

    int n, l, r;
    cin>>n;
    while(n--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", P[r] - P[l-1]);
    }
}
