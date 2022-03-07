/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10170
  Name: The Hotel with Infinite Rooms
  Problem: https://onlinejudge.org/external/101/10170.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int a, n;
    while (cin>>a>>n) {
        double delta = 4*(a*a-a+2*n)+1;
        printf("%d\n", (int) ceil((sqrt(delta)-1)/2));
    }
}
