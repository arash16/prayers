#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

// O(n^2)
int F[255], C[255], DP[255][255], P[255][255], n;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<255; ++i)
        P[i][i] = i;

    while (cin >> n) {
        for (int i=1; i<=n; ++i) {
            cin >> F[i];
            C[i] = C[i-1] + F[i];
        }

        for (int d=1; d<n; ++d)
            for (int i=1, j; (j=i+d)<=n; ++i) {
                int br = INF, bk;
                for (int k=P[i][j-1]; k<=P[i+1][j]; ++k) {
                    int nr = DP[i][k-1] + DP[k+1][j] - F[k];
                    if (nr < br) {
                        br = nr;
                        bk = k;
                    }
                }
                DP[i][j] = br + C[j]-C[i-1];
                P[i][j] = bk;
            }

        cout << DP[1][n] << '\n';
    }
}
