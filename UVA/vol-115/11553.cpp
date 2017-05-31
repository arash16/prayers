#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


int X[17][17], n;
bool used[17];
int bt(int r) {
    if (r == n) return 0;

    int mx = INF;
    for (int c=0; c<n; ++c)
        if (!used[c]) {
            used[c] = 1;
            mx = min(mx, bt(r+1) + X[r][c]);
            used[c] = 0;
        }
    return mx;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T-- && cin>>n) {
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin >> X[i][j];

        cout << bt(0) << '\n';
    }
}
