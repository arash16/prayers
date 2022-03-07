/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10585
  Name: Center of symmetry
  Problem: https://onlinejudge.org/external/105/10585.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator < (const Point &o) const {
        return x==o.x ? y<o.y : x<o.x;
    }
}
P[10143], pp;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- && cin >> n) {
        long long sx = 0, sy = 0;
        for (int i=0; i<n; ++i) {
            cin >> P[i].x >> P[i].y;
            sx += P[i].x;
            sy += P[i].y;
        }

        bool result = 0;
        if ((2*sx)%n==0 && (2*sy)%n==0) {
            long long tx = 2*sx/n, ty = 2*sy/n;
            sort(P, P+n);
            result = 1;
            for (int i=0; result && i<n; ++i) {
                pp.x = tx - P[i].x;
                pp.y = ty - P[i].y;
                result &= binary_search(P, P+n, pp);
            }
        }

        cout << (result ? "yes\n" : "no\n");
    }
}
