#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


vector<int> adj[143];
int X1[143], Y1[143], X2[143], Y2[143], n, m,
    match[143], D[143][143],
    seen[143], sse;
bool dfs(int u) {
    for (int v: adj[u])
        if (seen[v] != sse) {
            seen[v] = sse;
            if (match[v]==-1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    return 0;
}

bool bpm(int mx, int k) {
    if (!k) return 1;
    for (int i=0; i<n; ++i) {
        adj[i].clear();
        for (int j=0; j<m; ++j)
            if (D[i][j] <= mx)
                adj[i].push_back(j);
    }

    memset(match, -1, m*sizeof(int));
    for (int i=0; i<n; ++i) {
        if (n-i < k) return 0;
        ++sse;
        if (dfs(i) && !--k)
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, p, k;
    cin >> T;
    string s;
    while (T--) {
        cin >> p >> k;
        n=m=0;
        for (int i=0, x,y; i<p; ++i) {
            cin >> x >> y >> s;
            if (s[0] == 'b')
                X1[n] = x, Y1[n] = y, ++n;
            else
                X2[m] = x, Y2[m] = y, ++m;
        }

        vector<int> V;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                int xx = X1[i]-X2[j],
                    yy = Y1[i]-Y2[j];
                D[i][j] = xx*xx + yy*yy;
                V.push_back(ceil(sqrt(D[i][j])));
            }

        if (!bpm(INF, k))
            cout << "Impossible\n";

        else if (V.empty())
            cout << "0\n";

        else {
            int lo=0, hi=!V.empty();
            sort(V.begin(), V.end());
            for (int i=1; i<V.size(); ++i)
                if (V[i] != V[i-1])
                    V[hi++] = V[i];

            while (lo <= hi) {
                int mid = (lo + hi)>>1;
                if (bpm(V[mid]*V[mid], k))
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }

            cout << V[hi+1] << '\n';
        }
    }
}
