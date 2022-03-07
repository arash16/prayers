/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12577
  Name: Hajj-e-Akbar
  Problem: https://onlinejudge.org/external/125/12577.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    char str[50];
    int cse = 0;
    while (cin.getline(str, 50) && str[0] != '*')
        printf("Case %d: Hajj-e-%s\n", ++cse, str[0] == 'H' ? "Akbar" : "Asghar");
}
