/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12578
  Name: 10:6:2
  Problem: https://onlinejudge.org/external/125/12578.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n;
    cin>>T;
    while (T--) {
        cin>>n;n*=n;
        printf("%.2f %.2f\n", 0.125663706144*n, 0.474336293856*n);
    }
}
