#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

int idcnt;
unordered_map<string, int> ids;
int readId() {
    string s;
    cin >> s;
    auto r = ids.emplace(s, idcnt);
    if (r.second) ++idcnt;
    return r.first->second;
}

int M[55][55];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    for (int cse=1; cin>>n>>m && (n||m); ++cse) {
        cout << "Network " << cse << ": ";

        for (int i=0; i<n; ++i) {
            M[i][i] = 0;
            for (int j=0; j<i; ++j)
                M[i][j] = M[j][i] = INF;
        }

        idcnt = 0;
        ids.clear();
        for (int i=0; i<m; ++i) {
            int u = readId(),
                v = readId();

            M[u][v] = M[v][u] = 1;
        }

        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
            if (i!=k && M[i][k]!=INF)
                for (int j=0; j<n; ++j)
                if (j!=i && M[k][j]!=INF)
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

        int mxd = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                mxd = max(mxd, M[i][j]);

        if (mxd == INF)
            cout << "DISCONNECTED\n\n";
        else
            cout << mxd << "\n\n";
    }
}
