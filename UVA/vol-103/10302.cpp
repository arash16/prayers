/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10302
  Name: Summation of Polynomials
  Problem: https://onlinejudge.org/external/103/10302.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

long long int DP[50001] = {1};

long long p(long long int i) {
    return i*i*i;
}

int main() {
    for (int i=0; i<50001; i++)
        DP[i] = DP[i-1] + p(i);

    int n;
    while(cin>>n)
        cout<<DP[n]<<endl;
}
