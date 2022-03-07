/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 636
  Name: Squares (III)
  Problem: https://onlinejudge.org/external/6/636.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    char s[17];
    while (cin >> s && (s[1] || s[0]!='0')) {
        int b = 0;
        for (int i=0; s[i]; ++i)
            b = max(b, s[i]-'0'+1);

        for (; b<101; ++b) {
            int n = 0;
            for (int i=0; s[i]; ++i)
                n = n*b + s[i]-'0';

            int sq = sqrt(n);
            if (sq*sq == n) break;
        }

        cout << b << endl;
    }
}
