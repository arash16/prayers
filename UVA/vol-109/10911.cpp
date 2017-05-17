#include <bits/stdc++.h>
using namespace std;

int S[1<<16], cse, n;
bool chosen[20];
double D[20][20], DP[1<<16];
double rec(int s, int state) {
    if (!state) return 0;
    if (S[state] == cse)
        return DP[state];

    double result = 1e100;
    while (chosen[s]) ++s;
    chosen[s] = 1;

    int nst = state ^ (1<<s);
    for (int j=s+1; j<n; ++j)
        if (!chosen[j]) {
            chosen[j] = 1;
            result = min(result, rec(s+1, nst^(1<<j)) + D[s][j]);
            chosen[j] = 0;
        }

    chosen[s] = 0;

    S[state] = cse;
    return DP[state] = result;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(2);

    string name;
    int X[20], Y[20];
    for (cse=1; cin >> n && n; ++cse) {
        n <<= 1;
        for (int i=0; i<n; ++i)
            cin >> name >> X[i] >> Y[i];

        for (int i=0; i<n; ++i)
            for (int j=0; j<i; ++j) {
                int xx = X[i]-X[j],
                    yy = Y[i]-Y[j];
                D[i][j] = D[j][i] = sqrt(xx*xx + yy*yy);
            }

        cout << "Case " << cse << ": " << rec(0, (1<<n)-1) << '\n';
    }
}
