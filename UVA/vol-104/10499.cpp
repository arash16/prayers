/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10499
  Name: The Land of Justice
  Problem: https://onlinejudge.org/external/104/10499.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
    long long int n;
    while (cin >> n && n > -1)
        printf("%lld%%\n", n>1 ? n * 25 : 0);
}