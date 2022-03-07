/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10394
  Name: Twin Primes
  Problem: https://onlinejudge.org/external/103/10394.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N 20000000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve() {
    memset(prime, -1, sizeof(prime));

    unsigned int i;
    unsigned int sqrtN = (unsigned int) sqrt((double)N) + 1;
    for (i = 3; i < sqrtN; i += 2) if(gP(i)) {
        unsigned int i2 = i + i;
        for (unsigned int j = i * i; j < N; j += i2 ) rP(j);
    }
}

bool isP(int x){ return gP(x); }

int dp[100005];
int main(){
    sieve();

    int cnt = 0;
    for (int i=3; cnt<100001; i+=2)
        if (isP(i) && isP(i+2))
            dp[cnt++] = i;

    int n;
    while (cin>>n)
        printf("(%d, %d)\n", dp[n-1], dp[n-1]+2);
}
