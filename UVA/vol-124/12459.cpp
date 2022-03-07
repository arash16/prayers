/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12459
  Name: Bees' ancestors
  Problem: https://onlinejudge.org/external/124/12459.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

int main(){
    long long DP[81];
    DP[0] = DP[1] = 1;
    for (int i=2; i<81; i++)
        DP[i] = DP[i-1] + DP[i-2];

    int n;
    while (scanf("%d", &n)==1 && n)
        printf("%lld\n", DP[n]);
}
