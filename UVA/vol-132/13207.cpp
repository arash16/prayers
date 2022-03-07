/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13207
  Name: AirCraft: Monster
  Problem: https://onlinejudge.org/external/132/13207.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int X[43], Y[43], Z[43],
    Cx[43], Cy[43], Cz[43], n;

bool bt(int i, int x, int y, int z) {
    if (!x && !y && !z) return 1;
    if (x<0 || x-Cx[i]>0 ||
        y<0 || y-Cy[i]>0 ||
        z<0 || z-Cz[i]>0 || i>=n) return 0;

    return bt(i+1, x, y, z) || bt(i+1, x-X[i], y-Y[i], z-Z[i]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, x, y, z;
    cin >> T;
    while (T-- && cin >> x >> y >> z >> n) {
        string str;
        for (int i=0; i<n; ++i)
            cin >> str >> X[i] >> Y[i] >> Z[i];

        Cx[n] = Cy[n] = Cz[n] = 0;
        for (int i=n-1; i>=0; --i)
            Cx[i] = Cx[i+1] + X[i],
            Cy[i] = Cy[i+1] + Y[i],
            Cz[i] = Cz[i+1] + Z[i];

        cout << (bt(0, x, y, z) ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
