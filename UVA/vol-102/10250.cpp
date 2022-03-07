/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10250
  Name: The Other Two Trees
  Problem: https://onlinejudge.org/external/102/10250.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(10);

    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
        cout << -(y2 - my) + mx << ' '
             << +(x2 - mx) + my << ' '
             << -(y1 - my) + mx << ' '
             << +(x1 - mx) + my << '\n';
    }
}
