/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1583
  Name: Digit Generator
  Problem: https://onlinejudge.org/external/15/1583.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int D[100143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=1; i<100143; ++i) {
        int s = i;
        for (int x=i; x; x/=10)
            s += x % 10;
        if (s<100143 && !D[s]) D[s] = i;
    }


    int T, n;
    cin >> T;
    while (T-- && cin>>n)
        cout << D[n] << '\n';
}
