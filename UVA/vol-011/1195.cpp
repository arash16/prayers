/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1195
  Name: Calling Extraterrestrial Intelligence Again
  Problem: https://onlinejudge.org/external/11/1195.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


bool isnp[100100];
int prv[100100], prs[100100]={0,0,2}, primes[9600]={2}, pnt=1;
inline bool isprime(int n) {
    return n==2 || ((n&1) && !isnp[n]);
}


int main() {
    int lastp = 2;
    for (int i=3; i<100099; i+=2) {
        if (!isnp[i]) {
            prv[i] = pnt;
            lastp = primes[pnt++] = i;
            for (int k=2*i; k<100100; k+=i)
                isnp[k] = 1;
        }
        prs[i]=prs[i+1]=lastp;
    }

    int m, a, b;
    while (scanf("%d%d%d", &m, &a, &b)==3 && (m||a||b)) {
        int bp=0, bq=0, nq=0;

        int p = prs[(int)sqrt(m)];
        for (int pi=prv[p]; pi>=0; pi--) {
            p=primes[pi];
            int q = prs[m/p];
            if (!nq && p*b < a*q) {
                nq = 1;
                while (p*b < a*q)
                    q = primes[ prv[q]-1 ];
            }

            if (p*b < a*q) break;
            if (p*q > bp*bq) {
                bp = p;
                bq = q;
                if (p*q == m) break;
            }
        }

        printf("%d %d\n", bp, bq);
    }
}
