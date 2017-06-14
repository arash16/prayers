#include <bits/stdc++.h>
using namespace std;


char chh[] = "*+-?";
bool dp[44][88000];
int X[44], R[44], C[44], seen[44][88000], cse, n;
bool dfs(int idx, int f) {
    if (C[idx] < abs(f)) return 0;
    if (idx == n) return !f;
    if (seen[idx][f+44000] == cse)
        return dp[idx][f+44000];

    bool r1 = dfs(idx+1, f - X[idx]),
         r2 = dfs(idx+1, f + X[idx]);

    R[idx] |= r2<<1 | r1;

    seen[idx][f+44000] = cse;
    return dp[idx][f+44000] = r1 || r2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int f;
    for (cse=1; cin>>n>>f && (n||f); ++cse) {
        for (int i=0; i<n; ++i)
            cin >> X[i];

        C[n] = 0;
        for (int i=n-1; i>=0; --i)
            C[i] = C[i+1] + X[i];

        memset(R, 0, sizeof(R));
        bool r = dfs(0, f);
        if (!r) cout << "*\n";
        else {
            for (int i=0; i<n; ++i)
                cout << chh[R[i]];
            cout << '\n';
        }
    }
}
