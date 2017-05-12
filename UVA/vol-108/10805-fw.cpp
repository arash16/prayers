#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int M[414][414], T, n, m;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> m;

        for (int i=n+m; i>=0; --i) {
            memset(M[i], 127, (n+m)*sizeof(int));
            M[i][i] = 0;
        }

        int N = n;
        for (int i=0, u,v; i<m; ++i) {
            cin >> u >> v;
            M[u][N] = M[N][u] =
            M[v][N] = M[N][v] = 1;
            ++N;
        }

        // floyd-warshall
        for (int k=0; k<N; ++k)
            for (int i=0; i<N; ++i)
            if (M[i][k] < 10000)
                for (int j=0; j<N; ++j)
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

        int mn = 10000;
        for (int i=0; i<N; ++i) {
            int mx = 0;
            for (int j=0; j<n; ++j)
                mx = max(mx, M[i][j]);

            mn = min(mn, mx);
        }

        cout << "Case #" << cse << ":\n"
             << mn << "\n\n";
    }
}
