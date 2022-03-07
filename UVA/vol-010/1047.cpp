/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1047
  Name: Zones
  Problem: https://onlinejudge.org/external/10/1047.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int countbit(int x) {
    int c = 0;
    while (x) {
        x ^= x & -x;
        ++c;
    }
    return c;
}

int snoob(int x) {
    if (!x) throw 1;
    int rightOne = x & -x,
        nextHigherOneBit = x + rightOne;
    return ((x ^ nextHigherOneBit)/rightOne) >> 2 | nextHigherOneBit;
}


int X[23], Y[1<<21], B[1<<21], n, m, bn;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n >> m && (n||m); ++cse) {
        for (int i=0; i<n; ++i)
            cin >> X[i];

        cin >> bn;
        for (int i=0, sz, b; i<bn; ++i) {
            B[i] = 0;
            cin >> sz;
            while (sz--) {
                cin >> b;
                B[i] |= 1<<(b-1);
            }
            cin >> Y[i];
        }

        int best = 0, bestc;
        for (int mask=(1<<m)-1, sz=1<<n; mask<sz; mask=snoob(mask)) {
            int sum = 0;
            for (int i=0; i<n; ++i)
                if (1<<i & mask)
                    sum += X[i];

            for (int i=0; i<bn; ++i) {
                if (sum <= best) break;
                int a = B[i] & mask;
                if (a) sum -= (countbit(a) - 1) * Y[i];
            }

            if (best < sum) {
                best = sum;
                bestc= mask;
            }
        }

        cout << "Case Number  " << cse << '\n'
             << "Number of Customers: " << best << '\n'
             << "Locations recommended:";

        for (int i=0; i<n; ++i)
            if (1<<i & bestc)
                cout << ' ' << i+1;
        cout << "\n\n";
    }
}
