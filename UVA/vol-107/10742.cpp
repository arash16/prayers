/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10742
  Name: The New Rule in Euphomia
  Problem: https://onlinejudge.org/external/107/10742.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXP 1000001
int primes[80000], priment[MAXP], pnt;
bool notp[MAXP]={1,1};

int main(){
    for (int i=2; i<MAXP; i++) {
        if (!notp[i]) {
            primes[pnt++] = i;

            for (int j=2*i; j<MAXP;j+=i)
                notp[j] = 1;
        }
        priment[i] = priment[i-1] + !notp[i];
    }

    int cse=1, n;
    while (cin>>n && n) {
        unsigned int result = 0, nh = n>>1;
        for (int i=0; primes[i] <= nh; i++)
            result += priment[n-primes[i]] - priment[primes[i]];

        printf("Case %d: %u\n", cse++, result);
    }
}
