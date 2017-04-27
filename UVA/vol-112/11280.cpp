#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[114];
    int C[114][114], D[114][114], Q[12], R[114],
        T; cin >> T;

    string s1, s2;
    for (int cse=1; cse<=T; ++cse) {
        cout << (cse>1 ? "\n" : "") << "Scenario #" << cse << endl;
        unordered_map<string, int> ids;

        int n; cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> s1;
            ids[s1] = i;
            adj[i].clear();
            for (int j=0; j<n; ++j)
                C[i][j] = INF;
            D[i][0] = INF;
        }    D[0][0] = 0;

        int m; cin >> m;
        for (int i=0, c; i<m; ++i) {
            cin >> s1 >> s2 >> c;
            int u = ids[s1], v = ids[s2];
            if (C[u][v] == INF)
                adj[u].push_back(v);

            if (c < C[u][v])
                C[u][v] = c;
        }

        cin >> m;
        int mxq = 0;
        for (int i=0; i<m; ++i) {
            cin >> Q[i];
            if (Q[i] >= n-1)
                Q[i]  = n-2;
            if (Q[i] > mxq)
                mxq = Q[i];
        }

        int i=1;
        for (int som=1; som-- && i<=mxq+1; ++i) {
            for (int u=0; u<n; ++u)
                D[u][i] = D[u][i-1];

            for (int u=0; u<n; ++u)
                if (D[u][i-1] != INF)
                for (int v: adj[u]) {
                    int nc = D[u][i-1] + C[u][v];
                    if (nc < D[v][i]) {
                        D[v][i] = nc;
                        som = 1;
                    }
                }

            R[i-1] = D[n-1][i];
        }
        for (; i<=mxq+1; ++i)
            R[i-1] = R[i-2];

        for (int i=0; i<m; ++i)
            if (R[Q[i]] == INF)
                cout << "No satisfactory flights\n";
            else
                cout << "Total cost of flight(s) is $" << R[Q[i]] << endl;
    }
}
