#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[143];
    int n, C[143];
    bool frst = 1;
    while (cin >> n) {
        if (frst) frst = 0;
        else cout << "\n";

        for (int i=0, sz; i<n; ++i) {
            C[i] = 0;
            cin >> sz;
            adj[i].resize(sz);
            for (int j=0; j<sz; ++j)
                cin >> adj[i][j];

            if (!sz) adj[i].push_back(n);
        }

        C[0] = 1; C[n] = 0;
        for (int i=0; i<n; ++i)
            for (int v: adj[i])
                C[v] += C[i];

        cout << C[n] << "\n";
    }
}
