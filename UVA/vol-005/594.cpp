/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 594
  Name: One Little, Two Little, Three Little Endians
  Problem: https://onlinejudge.org/external/5/594.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin>>n) {
        int m = ((n&0x000000FF)<<24) +
                ((n&0x0000FF00)<<8) +
                ((n&0x00FF0000)>>8) +
                ((n&0xFF000000)>>24);

        printf("%d converts to %d\n", n, m);
    }
}

