/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11172
  Name: Relational Operator
  Problem: https://onlinejudge.org/external/111/11172.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

void main() {
    int n;
    cin >> n;
    while (n--) {
        long long int x, y;
        cin >> x >> y;
        cout << (x<y ? "<" : x > y ? ">" : "=") << endl;
    }
}
