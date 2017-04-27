#include <bits/stdc++.h>
using namespace std;

vector<int> adj[143];
int matchR[143];
bool seen[143];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = true;
            if (matchR[v]<0 || bpm(matchR[v])) {
                matchR[v] = u;
                return true;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, m, X[143];
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            adj[i].clear();
        }

        cin >> m;
        for (int j=0, y; j<m; ++j) {
            cin >> y;
            for (int i=0; i<n; ++i)
                if (!y || (X[i] && y%X[i] == 0))
                    adj[i].push_back(j);
        }

        int cnt = 0;
        memset(matchR, -1, m*sizeof(int));
        for (int i=0; i<n; ++i) {
            memset(seen, 0, m);
            if (bpm(i)) ++cnt;
        }

        cout << "Case " << cse << ": " << cnt << endl;
    }
}
