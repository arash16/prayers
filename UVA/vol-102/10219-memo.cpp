/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10219
  Name: Find the ways !
  Problem: https://onlinejudge.org/external/102/10219.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 21000647
int l = 2;
double cum[MAX];
double logf(int n) {
    for (; l <= n; l++)
        cum[l] = cum[l-1] + log10(l);
    return cum[n];
}

int main() {
    int n, k;
    while (cin>>n>>k)
        cout << floor(logf(n)-logf(k)-logf(n-k))+1 << endl;
}
