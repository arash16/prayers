/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 990
  Name: Diving for Gold
  Problem: https://onlinejudge.org/external/9/990.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int cse,
    n, t, w, d[43], v[43],
    DP[43][1043], dpb[43][1043],
    P[43][1043];

int dfs(int j, int r) {
    if (r < 0) return -INF;
    if (!r || j == n) return 0;
    if (dpb[j][r] == cse)
        return DP[j][r];

    int s1 = dfs(j+1, r),
        s2 = dfs(j+1, r-3*w*d[j]) + v[j];

    dpb[j][r] = cse;
    P[j][r] = s2 >= s1;
    return DP[j][r] = max(s1, s2);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool sel[43];
    for (cse=1; cin >> t >> w >> n; ++cse) {
        if (cse > 1) cout << "\n";
        for (int i=0; i<n; ++i)
            cin >> d[i] >> v[i];

        cout << dfs(0, t) << "\n";

        int cnt = 0;
        memset(sel, 0, n);
        for (int j=0, r=t; j<n && r>0; ++j)
            if (P[j][r]) {
                ++cnt;
                sel[j] = 1;
                r -= 3*w*d[j];
            }

        cout << cnt << "\n";
        for (int i=0; i<n; ++i)
            if (sel[i])
                cout << d[i] << ' ' << v[i] << "\n";
    }
}
