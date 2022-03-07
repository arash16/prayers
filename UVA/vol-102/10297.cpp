/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10297
  Name: Beavergnaw
  Problem: https://onlinejudge.org/external/102/10297.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    double pi = 3.1415926535897932384, d, v;
    while (cin >> d >> v && (d||v))
        cout << fixed << setprecision(3)
             << pow((pi*d*d*d - 6*v)/pi, 1.0/3) << endl;
}
