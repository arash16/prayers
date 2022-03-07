/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11935
  Name: Through the Desert
  Problem: https://onlinejudge.org/external/119/11935.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int D[55], E[55], F[55], n;
bool isEnough(double cap) {
    int ld = 0, lc = 0, ll = 0;
    double fuel = cap;
    for (int i=0; i<=n; ++i) {
        int d = D[i] - ld;
        fuel -= lc * d / 100.0;
        fuel -= ll * d;
        ld = D[i];
        if (fuel < 0) return 0;

        switch (E[i]) {
            case 1: lc = F[i]; break;
            case 2: ++ll; break;
            case 3: fuel = cap; break;
            case 4: ll = 0; break;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (1) {
        string cm, tmp;
        for (n=0; cin >> D[n] >> cm; ++n) {
            if (cm == "Fuel" ) {
                cin >> tmp >> F[n];
                if (!n && !D[n] && !F[n])  return 0;
                E[n] = 1;
            }
            else if (cm == "Leak") {
                E[n] = 2;
            }
            else if (cm == "Gas") {
                cin >> tmp;
                E[n] = 3;
            }
            else if (cm == "Mechanic") {
                E[n] = 4;
            }
            else break;
        }

        double lo = 0, hi = 1e10;
        while (hi-lo > 1e-9) {
            double mid = (lo + hi) / 2;
            if (isEnough(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << fixed << setprecision(3) << lo << "\n";
    }
}
