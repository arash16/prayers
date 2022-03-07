/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 714
  Name: Copying Books
  Problem: https://onlinejudge.org/external/7/714.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 4611686018427387904
typedef unsigned long long Long;

int n, k, X[600], Pa[600];
Long DP[600][600], sum;


bool tryfit(Long maxp) {
    int l = 1;
    Long sum = 0;
    for (int i=n-1; i>=0; i--) {
        sum += X[i];
        if (sum>maxp) {
            sum = X[i];
            if (++l > k)
                return 0;
        }
    }
    return 1;
}


int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);

        Long lo=0, hi=0;
        for (int i=0; i<n; i++) {
            scanf("%d", X+i);
            Pa[i] = -1;
            hi += X[i];
            if (X[i] > lo)
                lo = X[i];
        }

        while (lo <= hi) {
            Long mid = (lo+hi)>>1;
            if (tryfit(mid))
                 hi = mid-1;
            else lo = mid+1;
        }

        int l=k; sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += X[i];
            if (sum>hi+1 || i+1<l) {
                Pa[--l] = i+1;
                sum = X[i];
            }
        }

        printf("%d", X[0]);l=1;
        for (int i=1; i<n; i++) {
            if (Pa[l] == i) {
                printf(" /");
                l++;
            }
            printf(" %d", X[i]);
        }
        putchar('\n');
    }
}
