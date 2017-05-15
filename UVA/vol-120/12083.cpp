#include <bits/stdc++.h>
using namespace std;


vector<int> adj[555];
bool seen[555];
int match[555];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (match[v]==-1 || bpm(match[v])) {
                match[v] = u;
                return true;
            }
        }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string M[555], S[555], g;
    int H[555], T, n;
    cin >> T;
    while (T-- && cin >> n) {
        vector<int> L, R;
        for (int i=0; i<n; ++i) {
            cin >> H[i] >> g >> M[i] >> S[i];
            if (g[0] == 'M')
                L.push_back(i);
            else
                R.push_back(i);
        }

        for (int i=0; i<L.size(); ++i) {
            adj[i].clear();
            int u = L[i];
            for (int j=0; j<R.size(); ++j) {
                int v = R[j];
                if (abs(H[u]-H[v])<=40 && S[u]!=S[v] && M[u]==M[v])
                    adj[i].push_back(j);
            }
        }

        int cnt = 0;
        memset(match, -1, R.size()*sizeof(int));
        for (int i=0; i<L.size(); ++i) {
            memset(seen, 0, R.size());
            if (bpm(i)) ++cnt;
        }
        cout << (n - cnt) << '\n';
    }
}
