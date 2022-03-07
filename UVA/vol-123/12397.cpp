/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12397
  Name: Roman Numerals
  Problem: https://onlinejudge.org/external/123/12397.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int vals[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000},
    cnts[] = {1, 3, 2, 3, 2,  4,  2,  4,  2,   5,   3,   6,   4};

int main(){
    int n;
    while (scanf("%d", &n)==1) {
        int c = 0;
        for (int i=12; i>=0; i--) {
            int x = n/vals[i];
            n -= x * vals[i];
            c += cnts[i] * x;
        }

        printf("%d\n", c);
    }
}
