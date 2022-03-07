/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10466
  Name: How Far?
  Problem: https://onlinejudge.org/external/104/10466.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int n, t, ri, ti;
    while (cin >> n >> t) {
        double x = 0, y = 0;
        for (int i=0; i<n; ++i) {
            cin >> ri >> ti;
            double deg = 2*PI*double(t % ti) / ti;
            x += ri * cos(deg);
            y += ri * sin(deg);

            if (i) cout << ' ';
            cout << sqrt(x*x + y*y);
        }
        cout << '\n';
    }
}
