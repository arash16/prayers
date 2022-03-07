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

int M[43], MS[43], C1[43][23], C2[43][23], R[43], n, t1, t2,
    DP[43][313], P[43][313];

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> t1 >> t2 && (t1||t2)) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> M[i];
            for (int j=1; j<=M[i]; ++j)
                cin >> C1[i][j];
            for (int j=1; j<=M[i]; ++j)
                cin >> C2[i][j];
        }

        for (int i=1; i<n; ++i)
            MS[i] = MS[i-1] + M[i-1];

        memset(DP[n], 0, 313*sizeof(int));
        for (int id=n-1; id>=0; --id) {
            int ts = t1+t2-MS[id];
            for (int t1=0; t1<=ts; ++t1) {
                int t2 = ts - t1;

                int best = INF, besj;
                for (int j1=min(M[id], t1); j1>=0; --j1) {
                    int j2 = M[id] - j1;
                    if (j2 <= t2) {
                        int r = DP[id+1][t1-j1] + C1[id][j1] + C2[id][j2];
                        if (r < best) {
                            best = r;
                            besj = j1;
                        }
                    }
                }

                DP[id][t1] = best;
                P[id][t1] = besj;
            }
        }

        cout << DP[0][t1] << "\n";
        for (int k=n-1, i=0; k>=0; --k, ++i) {
            int j1 = P[i][t1];
            t1 -= j1;
            cout << j1;
            if (k) cout << ' ';
        }
        cout << "\n\n";
    }
}
