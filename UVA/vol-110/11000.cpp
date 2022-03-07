/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11000
  Name: Bee
  Problem: https://onlinejudge.org/external/110/11000.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 60
long long int mr[MAXN], tr[MAXN];
int main(){
    long long int f=1, m=0;
    long long int f2, m2, n;

    for (int i=0; i<MAXN; i++) {
        mr[i] = mr[i-1]+m;
        tr[i] = tr[i-1]+f+m;
        f2 = m;
        m2 = f + m;
        f = f2;
        m = m2;
    }

    while(cin>>n && n>-1)
        printf("%lld %lld\n", mr[n], tr[n]);
}
