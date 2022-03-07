/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12192
  Name: Grapevine
  Problem: https://onlinejudge.org/external/121/12192.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXNN 300000
int H[501][501], n, m, l, r;
int ispos(int sz) {
    for (int i=0, j=m; i<=n-sz; i++) {
        j = lower_bound(H[i], H[i]+min(m, j+1), l) - H[i];
        if (j<=m-sz && H[i+sz-1][j+sz-1] <= r)
            return true;
    }
    return false;
}


int main(){
    int q;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%d", &H[i][j]);

        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &l, &r);
            int lo=1, hi=min(n, m);
            while (lo <= hi) {
                int mid = (lo+hi)>>1;
                if (ispos(mid))
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            printf("%d\n", lo-1);
        }
        puts("-");
    }
}
