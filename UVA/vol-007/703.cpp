#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[143];
    int coi[143][143], eqi[143][143], res[161800][3], n;
    while (cin >> n) {
        for (int i=0; i<n; ++i) {
            adj[i].clear();
            for (int j=0; j<n; ++j)
                cin >> coi[i][j];
        }

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (i != j) {
                    if (coi[i][j] || !coi[j][i])
                        adj[i].push_back(j);

                    eqi[i][j] = !coi[i][j] && !coi[j][i];
                }

        int cnt = 0;
        for (int i=0; i<n; ++i)
            for (int j: adj[i])
                for (int k: adj[j])
                    if ((coi[i][j] && coi[j][k] && coi[k][i] && (j>i ? k>j : k<j))
                        || (eqi[i][j] && eqi[j][k] && eqi[k][i] && i<j && j<k)) {
                        res[cnt][0] = i+1;
                        res[cnt][1] = j+1;
                        res[cnt][2] = k+1;
                        ++cnt;
                    }

        cout << cnt << '\n';
        for (int i=0; i<cnt; ++i)
            cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << '\n';
    }
}
