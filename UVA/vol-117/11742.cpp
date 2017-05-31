#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> Pair;
#define ss second
#define ff first


vector<Pair> adj[17];
int P[17], n;
bool used[17];
bool check(int u, int pu) {
    for (Pair uv: adj[u]) {
        if (uv.ss<0 && abs(pu-P[uv.ff])<-uv.ss)
            return 0;
        if (uv.ss>0 && abs(pu-P[uv.ff])>uv.ss)
            return 0;
    }
    return 1;
}


int bt(int pi) {
    if (pi == n) return 1;

    int sum = 0;
    for (int i=0; i<n; ++i)
        if (!used[i] && check(pi, i)) {
            used[i] = 1;
            P[pi] = i;
            sum += bt(pi + 1);
            used[i] = 0;
        }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m, u, v, w;
    while (cin >> n >> m && (n||m)) {
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int i=0; i<m; ++i) {
            cin >> u >> v >> w;
            if (u < v) swap(u, v);
            adj[u].push_back(Pair(v, w));
        }

        cout << bt(0) << '\n';
    }
}
