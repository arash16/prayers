/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10773
  Name: Back to Intermediate Math
  Problem: https://onlinejudge.org/external/107/10773.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T;
    double d, u, v;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>d>>v>>u;
        printf("Case %d: ", cse);
        if (v>=u || v==0) puts("can't determine");
        else printf("%.3f\n", d*(1/sqrt(u*u-v*v) - 1/u));
    }
}
