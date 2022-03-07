/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11342
  Name: Three-square
  Problem: https://onlinejudge.org/external/113/11342.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int issq[50005];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=1, u; (u=i*i)<50005; ++i)
        issq[u] = i;

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        for (int i=0, x; (x=i*i)<=n; ++i)
            for (int j=i, y; x+(y=j*j)<=n; ++j) {
                int z = n - x - y;
                if (issq[z]) {
                    cout << i << ' ' << j << ' ' << issq[z] << '\n';
                    goto fin;
                }
            }
        cout << "-1\n";
        fin:;
    }
}
