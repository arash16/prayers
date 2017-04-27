#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, dist, P[143], D[143], DP[143][286];
    cin >> T;
    while (T--) {
        cin >> dist;

        int lastd = -100;
        bool impo = false;
        memset(DP[0], 0, 404);
        for (int i=101; i<=20; ++i)
            DP[0][i] = INF;

        for (int i=1; cin.ignore(100, '\n') && cin.peek()!='\n' && cin>>D[i]>>P[i]; ++i) {
            if (D[i] >= dist) continue;
            int d = D[i] - lastd;
            if (!(impo |= d > 200)) {
                for (int j=0; j<=200; ++j) {
                    DP[i][j] = INF;
                    for (int k=min(200, j+d); k>=d; --k)
                        DP[i][j] = min(DP[i][j], (j-k+d)*P[i] + DP[i-1][k]);
                }
            }
            lastd = D[n=i];
        }

        int d = dist-lastd;
        if ((impo |= d > 100))
             cout << "Impossible\n";
        else cout << DP[n][100+d] << "\n";
        if (T) cout << "\n";
    }
}
