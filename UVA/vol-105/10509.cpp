/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10509
  Name: R U Kidding Mr. Feynman?
  Problem: https://onlinejudge.org/external/105/10509.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    double n;
    while (cin >> n && n!=0) {
        int a = pow(n, 1/3.0);
        if ((a+1)*(a+1)*(a+1) <= n) ++a;
        double dx = (n - a*a*a) / (3*a*a);
        cout << a + dx << endl;
    }
}
