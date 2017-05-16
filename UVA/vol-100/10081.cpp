#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(5);

    double DP[11][101][11];
    for (int k=0; k<10; ++k) {
        for (int j=0; j<=k; ++j)
            DP[k][0][j] = 1;

        for (int i=1; i<101; ++i)
            for (int j=0; j<=k; ++j) {
                DP[k][i][j] = DP[k][i-1][j];
                if (j>0) DP[k][i][j] += DP[k][i-1][j-1];
                if (j<k) DP[k][i][j] += DP[k][i-1][j+1];

                DP[k][i][j] /= k+1;
            }
    }

    int k, n;
    while (cin >> k >> n) {
        double sum = 0;
        for (int j=0; j<=k; ++j)
            sum += DP[k][n-1][j];
        cout << 100*sum/(k+1) << '\n';
    }
}
