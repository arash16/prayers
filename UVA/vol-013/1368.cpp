#include <bits/stdc++.h>
using namespace std;

char DNA[] = "ACGT", D[55][1143];
int ids[91];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; DNA[i]; ++i)
        ids[DNA[i]] = i;

    int T, n, m;
    cin >> T;
    while (T-- && cin>>m>>n) {
        for (int i=0; i<m; ++i)
            cin >> D[i];

        int sum = 0;
        for (int j=0; j<n; ++j) {
            int C[4] = {};
            for (int i=0; i<m; ++i)
                ++C[ids[D[i][j]]];

            int mxi=0;
            for (int i=1; i<4; ++i)
                if (C[i] > C[mxi])
                    mxi = i;
            cout << DNA[mxi];
            for (int i=0; i<4; ++i)
                if (mxi!=i)
                    sum += C[i];
        }
        cout << '\n' << sum << '\n';
    }
}
