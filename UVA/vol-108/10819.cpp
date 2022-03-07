/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10819
  Name: Trouble of 13-Dots
  Problem: https://onlinejudge.org/external/108/10819.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int cse=1, p[101], f[101], m,
    memoid[101][12001],
    memo[101][12001];

int ks(int ind, int spent) {
    if (spent>m+200) return -100;
    if (spent>=m) {
        if (spent <= 2000) {
            if (spent<=1800)
                return spent>m ? -100 : 0;
        }
        else if (spent == m+200)
            return 0;
    }
    if (ind < 0)
        return spent>m && spent<=2000 ? -100 : 0;

    if (memoid[ind][spent] == cse)
        return memo[ind][spent];

    int res = max(
        ks(ind-1, spent),
        ks(ind-1, spent + p[ind]) + f[ind]
    );

    memoid[ind][spent] = cse;
    return memo[ind][spent] = res;
}

int main() {
    int n;
    while (scanf("%d%d", &m, &n)==2) {
        for (int i=0; i<n; i++)
            scanf("%d%d", p+i, f+i);

        printf("%d\n", ks(n-1, 0));
        cse++;
    }
}
