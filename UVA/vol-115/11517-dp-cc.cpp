#include <bits/stdc++.h>
using namespace std;

int C[143], DP[20086];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, p;
    cin >> T;
    while (T--) {
        cin >> p >> n;
        for (int i=0; i<n; ++i)
            cin >> C[i];

        memset(DP, 127, sizeof(DP));
        DP[0] = 0;
        for (int i=0; i<n; ++i) {
            int c = C[i];
            for (int j=p; j>=0; --j)
                DP[j+c] = min(DP[j+c], DP[j]+1);
        }

        int j;
        for (j=p; DP[j]>100; ++j);
        cout << j << ' ' << DP[j] << '\n';
    }
}
