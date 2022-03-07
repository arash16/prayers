/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 121
  Name: Pipe Fitters
  Problem: https://onlinejudge.org/external/1/121.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const double cc = 1.1547005383792515;
int skew(double w, double h) {
    int hn = cc*(h-1) + 1,
        hn1 = hn>>1,
        hn2 = hn-hn1,
        wn2 = w,
        wn1 = w-wn2<0.5 ? wn2-1 : wn2;

    return hn1*wn1 + hn2*wn2;
}

int main(){
    double a, b;
    while (cin>>a>>b) {
        int g = floor(a)*floor(b),
            s = max(skew(a,b), skew(b,a));

        if (g >= s)
             printf("%d grid\n", g);
        else printf("%d skew\n", s);
    }
}
