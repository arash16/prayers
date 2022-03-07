/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12531
  Name: Hours and Minutes
  Problem: https://onlinejudge.org/external/125/12531.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool seen[181] = {};
    int h=0, m=0;
    for (int i=1; i<=720; ++i) {
        if (i%12==0)
            h = (h + 1) % 60;
        m = (m + 1) % 60;

        int d = fabs(m-h);
        if (d > 30) d -= 30;
        seen[d * 6] = true;
    }

    while (cin >> m)
        cout << (seen[m] ? "Y\n" : "N\n");
}
