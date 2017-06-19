#include <bits/stdc++.h>
using namespace std;


int X[143], Y[143], DP[143][143], n;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n && n) {
        int mxr = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i] >> Y[i];
            mxr += Y[i];
        }

        memset(DP[n], 0, (n+1)*sizeof(int));
        for (int i=n-1; i>=0; --i) {
            int nr = n-i-1;
            DP[i][0] = DP[i+1][min(Y[i], nr)] + X[i];
            for (int r=min(mxr, n-i); r>0; --r)
                DP[i][r] = min(DP[i+1][min(r+Y[i], nr)] + X[i], DP[i+1][min(r+Y[i]-1, nr)] + X[i]/2);
        }

        cout << DP[0][0] << '\n';
    }
}
