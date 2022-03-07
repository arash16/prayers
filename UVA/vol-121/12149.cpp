/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12149
  Name: Feynman
  Problem: https://onlinejudge.org/external/121/12149.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n && n)
        cout << (n*(n+1)*(2*n+1))/6 << endl;
}
