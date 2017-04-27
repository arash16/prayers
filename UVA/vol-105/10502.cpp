#include <bits/stdc++.h>
using namespace std;
// O(n^3)
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    int n, m, M[143][143], D[143];
    while (cin >> n >> m && (n || m)) {
        for (int i=0; i<n; ++i) {
            cin >> line;
            for (int j=0; j<m; ++j)
                M[i][j] = line[j] - '0';
        }

        int cnt = 0;
        for (int i1=0; i1<n; ++i1) {
            memset(D, 0, m*sizeof(int));
            for (int i2=i1; i2<n; ++i2) {
                int k = 0;
                for (int j=0; j<m; ++j) {
                    D[j] += M[i2][j];

                    if (D[j] == i2-i1+1)
                        cnt += ++k;
                    else k = 0;
                }
            }
        }
        cout << cnt << "\n";
    }
}
