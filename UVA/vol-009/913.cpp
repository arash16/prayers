/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 913
  Name: Joana and the Odd Numbers
  Problem: https://onlinejudge.org/external/9/913.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int n;
    while(cin>>n) {
        long long t = (n+1)*((n+1)>>1)-1;
        cout << 3*t - 6 <<endl;
    }
}

