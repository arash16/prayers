/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10323
  Name: Factorial! You Must be Kidding!!!
  Problem: https://onlinejudge.org/external/103/10323.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

long long fac[] = {40320, 362880, 3628800, 39916800, 479001600, 6227020800};
int main(){
    int n;
    while (cin>>n) {
        if ((n<0 && n%2) || n>13)
            cout << "Overflow!\n";
        else if ((n<0 && n%2==1) || n<8)
            cout << "Underflow!\n";
        else
            cout << fac[n-8] << endl;
    }
}

