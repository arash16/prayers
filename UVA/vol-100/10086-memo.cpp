/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10086
  Name: Test the Rods
  Problem: https://onlinejudge.org/external/100/10086.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 268435456
using namespace std;

int M[43], C1[43][23], C2[43][23], R[43], n, t1, t2,
    DP[313][313][43], P[313][313][43], S[313][313][43], cse;

int solve(int t1, int t2, int id) {
    if (t1<0 || t2<0) return INF;
    if (id == n) return 0;
    if (S[t1][t2][id] == cse)
        return DP[t1][t2][id];

    int best = INF, besj;
    for (int j1=min(M[id], t1); j1>=0; --j1) {
        int j2 = M[id] - j1;
        if (j2 <= t2) {
            int r = solve(t1-j1, t2-j2, id+1)
                + C1[id][j1] + C2[id][j2];
            if (r < best) {
                best = r;
                besj = j1;
            }
        }
    }

    S[t1][t2][id] = cse;
    P[t1][t2][id] = besj;
    return DP[t1][t2][id] = best;
}



char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (cse=1; cin >> t1 >> t2 && (t1||t2); ++cse) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> M[i];
            for (int j=1; j<=M[i]; ++j)
                cin >> C1[i][j];
            for (int j=1; j<=M[i]; ++j)
                cin >> C2[i][j];
        }

        cout << solve(t1, t2, 0) << "\n";
        for (int k=n-1, i=0; k>=0; --k, ++i) {
            int j1 = P[t1][t2][i];
            t2 -= M[i] - j1;
            t1 -= j1;
            cout << j1;
            if (k) cout << ' ';
        }
        cout << "\n\n";
    }
}
