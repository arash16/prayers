/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10110
  Name: Light, more light
  Problem: https://onlinejudge.org/external/101/10110.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    long long int n;
    while ((cin>>n) && n) {
        long long int sq = sqrt(n);
        cout << (sq*sq == n ? "yes" : "no") << endl;
    }
}

