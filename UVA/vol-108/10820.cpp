/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10820
  Name: Send a Table
  Problem: https://onlinejudge.org/external/108/10820.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


long long phi[50005];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=1; i<50005; i++)
        phi[i] = i;
    for (int p=2; p<50005; ++p)
        if (phi[p] == p) {
            phi[p] = p-1;
            for (int i=2*p; i<50005; i += p)
                phi[i] = (phi[i]/p) * (p-1);
        }

    phi[1] = 1;
    for (int p=2; p<50005; ++p)
        phi[p] = phi[p]*2 + phi[p-1];

    int n;
    while (cin >> n && n)
        cout << phi[n] << endl;
}
