#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

string names[23];
int M[23][23], S[23];
int main() {
    for (int cse=1, n,m; cin>>n>>m && (n||m); ++cse) {
        cout << "Case #" << cse << " : ";

        for (int i=0; i<n; ++i) {
            cin >> names[i];
            for (int j=0; j<i; ++j)
                M[i][j] = M[j][i] = INF;
        }

        for (int i=0, u,v,d; i<m; ++i) {
            cin >> u >> v >> d;
            M[u-1][v-1] = M[v-1][u-1] = d;
        }

        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
            if (i!=k && M[i][k]!=INF)
                for (int j=0; j<n; ++j)
                if (j!=k && M[k][j]!=INF)
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

        int mnd = INF;
        for (int i=0; i<n; ++i) {
            S[i] = 0;
            for (int j=0; j<n; ++j)
                S[i] += M[i][j];
            mnd = min(mnd, S[i]);
        }

        for (int i=0; i<n; ++i)
            if (S[i] == mnd) {
                cout << names[i] << endl;
                break;
            }
    }
}
