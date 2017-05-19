#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int A[143], n, r;
    double C[10143], DP[143], b, v, e, f;
    A[0] = C[0] = DP[0] = 0;

    while (cin >> n && n) {
        for (int i=1; i<=n; ++i)
            cin >> A[i];
        cin >> b >> r >> v >> e >> f;

        for (int x=0; x<=A[n]; ++x)
            C[x] = (x?C[x-1]:0) + (x>=r ? 1/(v-e*(x-r)) : 1/(v-f*(r-x)));

        for (int i=1; i<=n; ++i) {
            DP[i] = 1e100;
            for (int j=0; j<i; ++j)
                DP[i] = min(DP[i], DP[j] + C[A[i]-A[j]-1] + b);
        }
        cout << DP[n]-b << endl;
    }
}
