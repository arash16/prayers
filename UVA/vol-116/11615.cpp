/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11615
  Name: Family Tree
  Problem: https://onlinejudge.org/external/116/11615.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int lg2(int x) {
    int r = 0;
    for (; x; x>>=1)
        ++r;
    return r-1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, a, b;
    cin >> T;
    while (T-- && cin >> n >> a >> b) {
        int al = (1<<n) - 1,
            gr = n - lg2(max(a, b)),
            ar = (1<<(gr)) - 2;
        cout << al - ar << '\n';
    }
}
