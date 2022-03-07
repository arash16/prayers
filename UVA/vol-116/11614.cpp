/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11614
  Name: Etruscan Warriors Never Play Chess
  Problem: https://onlinejudge.org/external/116/11614.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long T, n;
    cin>>T;
    while (T--) {
        cin>>n;
        cout << (int) floor((1 + sqrt(1 + (long double)8*n))/2)-1 << endl;
    }
}
