/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10407
  Name: Simple division
  Problem: https://onlinejudge.org/external/104/10407.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}

int main() {
    int a, b;
    while (cin>>a && a) {
        int rs = 0;
        while (cin>>b && b)
            if (!rs) rs = fabs(a-b);
            else if (a-b)
                rs = gcd(rs, fabs(a-b));
        cout << rs << endl;
    }
}
