/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11044
  Name: Searching for Nessy
  Problem: https://onlinejudge.org/external/110/11044.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (a / 3) * (b / 3) << endl;
    }
}