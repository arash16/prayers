#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        int cnt = 0;
        for (int i=0; i<n; ++i) {
            bool f = 1;
            for (int j=0, x; j<m; ++j) {
                cin >> x;
                f &= x > 0;
            }
            cnt += f;
        }
        cout << cnt << '\n';
    }
}
