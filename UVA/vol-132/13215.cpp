/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13215
  Name: Polygonal Park
  Problem: https://onlinejudge.org/external/132/13215.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


const double a = sqrt(3)/4.0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        char ch;
        double sl[4]={}, l, sum = 0;
        for (int i=0, s=3; i<n; ++i) {
            cin >> ch >> l;
            sum += l*l*(ch == 'T' ? a : 1);
            sl[s] += l;
            if (ch == 'C') {
                if (++s == 4) s = 0;
                sl[s] += l;
            }
        }
        cout << max(sl[0], sl[2])*max(sl[1], sl[3])-sum << endl;
    }
}
