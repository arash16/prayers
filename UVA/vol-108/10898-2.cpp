#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


int Ci[143][6], Cp[143], csz,
    S[10][10][10][10][10][10], DP[10][10][10][10][10][10], cse;
int rec(int r0, int r1, int r2, int r3, int r4, int r5) {
    if (r0<0 || r1<0 || r2<0 || r3<0 || r4<0 || r5<0) return INF;
    int &ss = S[r0][r1][r2][r3][r4][r5];
    if (ss == cse) return DP[r0][r1][r2][r3][r4][r5];

    int mn = INF;
    for (int i=0; i<csz; ++i)
        mn = min(mn, rec(r0-Ci[i][0], r1-Ci[i][1], r2-Ci[i][2], r3-Ci[i][3], r4-Ci[i][4], r5-Ci[i][5]) + Cp[i]);

    ss = cse;
    return DP[r0][r1][r2][r3][r4][r5] = mn;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    for (cse=1; cin >> n && n; ++cse) {
        S[0][0][0][0][0][0] = cse;
        csz = 0;

        for (int i=0; i<n; ++i) {
            memset(Ci[csz], 0, 24);
            Ci[csz][i] = 1;
            cin >> Cp[csz++];
        }

        cin >> m;
        while (m--) {
            memset(Ci[csz], 0, 24);
            for (int i=0; i<n; ++i)
                cin >> Ci[csz][i];
            cin >> Cp[csz++];
        }

        cin >> m;
        while (m--) {
            int R[6] = {};
            for (int i=0; i<n; ++i)
                cin >> R[i];
            cout << rec(R[0], R[1], R[2], R[3], R[4], R[5]) << endl;
        }
    }
}
