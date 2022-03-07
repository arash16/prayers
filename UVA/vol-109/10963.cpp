/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10963
  Name: The Swallowing Ground
  Problem: https://onlinejudge.org/external/109/10963.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool solve(int n) {
    if (!n) return true;

    int y1, y2, gap;
    cin >> y1 >> y2;
    gap = y1 - y2;

    bool result = true;
    for (int i=1; i<n; ++i) {
        cin >> y1 >> y2;
        result &= y1-y2 == gap;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- && cin >> n) {
        cout << (solve(n) ? "yes\n" : "no\n");
        if (T) cout << '\n';
    }
}
