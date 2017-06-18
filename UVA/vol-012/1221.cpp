#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


int Ix[255], Iy[255], Rx[255], Ry[255], D[255][255], n, m;
vector<int> adj[255];
int match[255];
bool seen[255];
bool dfs(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (match[v]==-1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    return 0;
}

bool bpm(int maxt) {
    if (n < m) return 0;

    for (int i=0; i<n; ++i) {
        adj[i].clear();
        for (int j=0; j<m; ++j)
            if (D[i][j] <= maxt)
                adj[i].push_back(j);
    }

    int cnt = m;
    memset(match, -1, m*sizeof(int));
    for (int i=0; n-i>=cnt; ++i) {
        memset(seen, 0, m);
        if (dfs(i) && !--cnt)
            return 1;
    }
    return 0;
}


int divu(int a, int b) { return (a+b-1) / b; }
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> m && (n||m)) {
        for (int i=0; i<n; ++i)
            cin >> Ix[i] >> Rx[i];

        for (int i=0; i<m; ++i)
            cin >> Iy[i] >> Ry[i];

        vector<int> V;
        for (int i=0; i<n; ++i)
            for (int j=0, tt; j<m; ++j) {
                cin >> tt;
                if (Rx[i] <= Ry[j])
                    D[i][j] = Ix[i] >= Iy[j]+tt*Ry[j] ? tt : INF;
                else
                    D[i][j] = tt + divu( Iy[j]-Ix[i]+Ry[j]*tt , Rx[i]-Ry[j] );

                if (D[i][j] != INF)
                    V.push_back(D[i][j]);
            }

        if (!bpm(INF-1))
            cout << "IMPOSSIBLE\n";
        else if (V.empty())
            cout << "0\n";
        else {
            int lo=0, hi=1;
            sort(V.begin(), V.end());
            for (int i=1; i<V.size(); ++i)
                if (V[i] != V[i-1])
                    V[hi++] = V[i];

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (bpm(V[mid]))
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }

            cout << V[hi+1] << endl;
        }
    }
}
