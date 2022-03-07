/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 152
  Name: Tree's a Crowd
  Problem: https://onlinejudge.org/external/1/152.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 5001

int n, px[MAXN], py[MAXN], pz[MAXN], dd[MAXN], rr[10];
int dist2(int i, int j) {
    int xx=px[i]-px[j],
        yy=py[i]-py[j],
        zz=pz[i]-pz[j];

    return xx*xx + yy*yy + zz*zz;
}

int main(){
    for (n=0; cin>>px[n]>>py[n]>>pz[n] && (px[n]||py[n]||pz[n]); n++) {
        dd[n] = 1<<30;
        for (int i=0; i<n; i++) {
            int d = dist2(i, n);
            if (d < dd[n]) dd[n]=d;
            if (d < dd[i]) dd[i]=d;
        }
    }

    for (int i=0; i<n; i++)
        if (dd[i] < 100)
            rr[(int)(sqrt((float)dd[i]))]++;

    for (int i=0; i<10; i++)
        printf("%4d", rr[i]);
    putchar('\n');
}
