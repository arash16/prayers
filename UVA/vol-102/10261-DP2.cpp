#include <bits/stdc++.h>
using namespace std;

int X[243], C[243], len, n,
    DP[243][10143];
bool P[243][10143];

int maxCar() {
    memset(DP[n], 0, (len+1)*sizeof(int));
    for (int id=n-1; id>=0; --id)
        for (int r1=0; r1<=len; ++r1) {
            int r2 = 2*len - r1 - C[id];

            int mx = 0;
            if (X[id] <= r1) {
                mx = DP[id+1][r1-X[id]] + 1;
                P[id][r1] = 0;
            }

            if (X[id] <= r2) {
                int t = DP[id+1][r1] + 1;
                if (t > mx) {
                    mx = t;
                    P[id][r1] = 1;
                }
            }
            DP[id][r1] = mx;
        }
    return DP[0][len];
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> len; len*=100;
        for (n=0; cin>>X[n] && X[n]; ++n);
        for (int i=1; i<=n; ++i)
            C[i] = C[i-1] + X[i-1];

        int sz = maxCar();
        cout << sz << "\n";
        for (int i=0, rem=len, id=0; i<sz; ++i, ++id)
            if (!P[id][rem]) {
                rem -= X[id];
                cout << "port\n";
            }
            else cout << "starboard\n";
        if (T) cout << "\n";
    }
}
