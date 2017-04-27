#include <bits/stdc++.h>
using namespace std;

unsigned long long DP[21][21], n, a;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> a) {
        DP[n][1] = a;
        for (int j=1; j<=n; ++j)
            for (int i=n; i>=j; --i)
                if (i!=n || j!=1) {
                    unsigned long long mx1 = 0;
                    for (int k=i+1; k<=n; ++k)
                        mx1 = max(mx1, DP[k][1] + DP[k][j]);

                    unsigned long long mx2 = 0;
                    for (int k=1; k<j; ++k)
                        mx2 = max(mx2, DP[i][k] + DP[n][k]);

                    DP[i][j] = mx1 + mx2;
                }

        for (int i=n-1; i>0; --i)
            for (int j=i+1; j<=n; ++j) {
                unsigned long long mx = 0;
                for (int k=i; k<j; ++k)
                    mx = max(mx, DP[i][k] + DP[k+1][j]);
                DP[i][j] = mx;
            }

        cout << DP[1][n] << "\n";
    }
}
