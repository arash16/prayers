#include <bits/stdc++.h>
using namespace std;


int X[143], Y[143], n,
    S[143][143], DP[143][143], cse;
int dp(int idx, int r) {
    if (idx == n) return 0;
    r = min(r, n-idx);

    int &result = DP[idx][r];
    if (S[idx][r] == cse)
        return result;
    S[idx][r] = cse;

    result = dp(idx + 1, r + Y[idx]) + X[idx];
    if (r) result = min(result, dp(idx + 1, r + Y[idx] - 1) + X[idx]/2);
    S[idx][r] = cse;
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (cse=1; cin >> n && n; ++cse) {
        for (int i=0; i<n; ++i)
            cin >> X[i] >> Y[i];

        cout << dp(0, 0) << '\n';
    }
}
