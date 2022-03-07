/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10576
  Name: Y2K Accounting Bug
  Problem: https://onlinejudge.org/external/105/10576.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int s, d;
    while (cin >> s >> d) {
        int m[12], sum = 0, res = 0, k;
        for (k=0; k*d < (5-k)*s; ++k);
        for (int i=0; i<12; ++i) {
            if (i < 5)
                m[i] = i<5-k ? s : -d;
            else {
                sum -= m[i-5];
                if (sum + s <= 0)
                     m[i] = s;
                else m[i] = -d;
            }
            res += m[i];
            sum += m[i];
        }

        if (res < 0) cout << "Deficit\n";
        else cout << res << '\n';
    }
}
