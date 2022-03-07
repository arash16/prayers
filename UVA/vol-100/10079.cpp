/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10079
  Name: Pizza Cutting
  Problem: https://onlinejudge.org/external/100/10079.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int n;
    while(cin>>n && n>=0)
        if (n%2)
            cout << n*((n+1)/2) + 1 << endl;
        else
            cout << (n/2)*(n+1) + 1 << endl;
}

