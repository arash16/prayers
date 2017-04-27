#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m, S[101];
    cin >> T;
    while (T--) {
        cin >> n >> m;

        int DP[101] = {};
        for (int i=0; i<n; ++i) {
            for (int j=1; j<=m; ++j)
                cin >> S[j];

            for (int r=m; r>0 && DP[r]>=0; --r) {
                int mx = -INF;
                for (int j=r-i; j>0 && S[j]>4; --j)
                    mx = max(mx, DP[r-j] + S[j]);
                DP[r] = mx;
            }
        }

        double result = round(100.0*DP[m] / n)/100.0;
        if (result<5)
            cout << "Peter, you shouldn't have played billiard that much.\n";
        else
            cout << "Maximal possible average mark - "
                 << fixed << setprecision(2) << result << ".\n";
    }
}
