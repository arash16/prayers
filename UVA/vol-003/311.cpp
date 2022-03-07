/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 311
  Name: Packets
  Problem: https://onlinejudge.org/external/3/311.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int C2[] = { 0, 5, 3, 1 },
        C1[] = { 0, 7, 6, 5 },
        x1, x2, x3, x4, x5, x6;
    while (cin>>x1>>x2>>x3>>x4>>x5>>x6 && (x1||x2||x3||x4||x5||x6)) {
        int cnt = x6 + x5 + x4 + ceil(x3/4.0);
        x1 -= 11*x5 + C1[x3%4];
        x2 -=  5*x4 + C2[x3%4];
        if (x2 > 0) {
            cnt += ceil(x2 / 9.0);
            x2 -= 9 * ceil(x2 / 9.0);
        }
        if (x2 < 0) {
            x1 -= -x2*4;
            x2 = 0;
        }

        if (x1 > 0)
            cnt += ceil(x1/36.0);

        cout << cnt << '\n';
    }
}
