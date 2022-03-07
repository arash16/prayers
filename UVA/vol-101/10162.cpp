/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10162
  Name: Last Digit
  Problem: https://onlinejudge.org/external/101/10162.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int powmod(int a, int b, int c) {
    if (!b) return 1;
    int d = powmod(a, b>>1, c) % c;
    d = (d*d) % c;
    if (b&1) d *= a;
    return d%c;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[201] = {}, n;
    for (int i=1; i<=200; ++i)
        X[i] = (X[i-1] + powmod(i, i, 10)) % 10;

    string s;
    while (cin >> s && s!="0") {
        if (s.length() > 3)
            s = s.substr(s.length()-3);

        stringstream sin(s); sin >> n;
        cout << X[n % 200] << endl;
    }
}
