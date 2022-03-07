/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11231
  Name: Black and white painting
  Problem: https://onlinejudge.org/external/112/11231.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int calc(int n, int m) {
    return (n/2-3) * (m/2-3);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, c;
    while (cin>>n>>m>>c && n) {
        if (c)
            cout << calc(n, m) + calc(n-1, m-1) << endl;
        else
            cout << calc(n, m-1) + calc(n-1, m) << endl;
    }
}
