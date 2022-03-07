/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11428
  Name: Cubes
  Problem: https://onlinejudge.org/external/114/11428.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int X[10001], Y[10001], n;

int main(){
    for (int i=60; i>0; i--)
        for (int j=i-1; j>0; j--) {
            int d = i*i*i - j*j*j;
            if (d > 10000) break;
            X[d] = i; Y[d] = j;
        }



    while (cin>>n && n)
        if (X[n])
            printf("%d %d\n", X[n], Y[n]);
        else
            puts("No solution");
}
