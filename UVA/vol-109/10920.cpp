/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10920
  Name: Spiral Tap
  Problem: https://onlinejudge.org/external/109/10920.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>

int sdi[] = {1,  0, -1, 0},
    sdj[] = {0, -1,  0, 1};

int main() {
    long long sz, n, t, i, j;
    while (scanf("%lld%lld", &sz, &n)==2 && sz) {
        if ( n > 1) {
            int m = (sz+1)>>1,
                l = int(ceil(sqrt(n))) | 1,    // 5
                hl = (l+1)>>1,                // 3
                o = (l-2)*(l-2) + 1,        // 10
                d = n - o,
                s = d / (l - 1),            // side
                so = d % (l - 1);            // side offset
                i = m + hl - 1,
                j = m + (hl>1 ? hl-2 : 0) - so;

            for (int k=0; k<s; ++k) {
                t = j;
                j = sz-i+1;
                i = t;
            }
        }
        else i=j=(sz+1)>>1;

        printf("Line = %lld, column = %lld.\n", i, j);
    }
}
