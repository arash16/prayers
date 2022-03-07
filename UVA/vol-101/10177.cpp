/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10177
  Name: (2/3/4)-D Sqr/Rects/Cubes/Boxes?
  Problem: https://onlinejudge.org/external/101/10177.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

typedef unsigned long long ULong;
ULong S2[102], S3[102], S4[102], C[102];
int main(){
    for (int i=1; i<102; i++) {
        ULong i2 = i*i;
        S2[i] = S2[i-1] + i2;
        S3[i] = S3[i-1] + i2*i;
        S4[i] = S4[i-1] + i2*i2;
        if (i>1) C[i] = i*(i-1)>>1;
    }

    int n;
    while (scanf("%d", &n)==1) {
        ULong c=C[n+1], c2=c*c;
        printf("%llu %llu %llu %llu %llu %llu\n",
        S2[n], c2-S2[n], S3[n], c2*c-S3[n], S4[n], c2*c2-S4[n]);
    }
}
