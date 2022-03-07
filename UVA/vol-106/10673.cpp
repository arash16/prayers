/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10673
  Name: Play with Floor and Ceil
  Problem: https://onlinejudge.org/external/106/10673.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

struct Triple {
    int d, x, y;
    Triple(int q, int w, int e):d(q),x(w),y(e) {}
};

Triple egcd(int a, int b) {
    if (!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a % b);
    return Triple(q.d, q.y, q.x - a/b*q.y );
}

Triple ldioph(int a, int b, int c) {
    Triple t = egcd(a, b);
    if (c % t.d) return Triple(0, 0, 0);
    t.x *= c / t.d; t.y *= c / t.d;
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, x, k;
    cin >> T;
    while (T-- && cin >> x >> k) {
        int a = x / k,
            b = (x + k - 1) / k;

        Triple r = ldioph(a, b, x);
        cout << r.x << ' ' << r.y << endl;
    }
}
