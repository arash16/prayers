#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


int X[143][143], n, m, rj,
    di[] = { 0, 0, 1, -1 },
    dj[] = { 1, -1, 0, 0 };

void dfs(int i, int j, int x=1, int c=1) {
    if (x > c) x=1, ++c;
    if (i<0 || i>=n || j<0 || j>m || X[i][j]!=x) return;
    if (i == n-1) { rj = min(rj, j); return; }

    int o = X[i][j]; X[i][j]=0;
    for (int k=0; k<4; ++k)
        dfs(i+di[k], j+dj[k], x+1, c);
    X[i][j] = o;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                cin >> X[i][j];

        rj = INF;
        for (int j=0; j<m; ++j) {
            dfs(0, j);
            if (rj != INF) {
                cout << "1 " << j+1 << '\n' << n << ' ' << rj+1 << '\n';
                break;
            }
        }
        if (T) cout << '\n';
    }
}
