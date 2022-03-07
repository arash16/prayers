/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10804
  Name: Gopher Strategy
  Problem: https://onlinejudge.org/external/108/10804.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


vector<int> adj[55];
int match[55], n, m;
double Xg[55], Yg[55], Xh[55], Yh[55], D[55][55];

int seen[55], sse;
bool dfs(int u) {
    for (int v: adj[u])
        if (seen[v]!= sse) {
            seen[v] = sse;
            if (match[v]==-1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    return 0;
}

bool bpm(double h, int mk) {
    if (mk >= n) return 1;

    memset(match, -1, m*sizeof(int));
    for (int i=0; i<n; ++i) {
        adj[i].clear();
        for (int j=0; j<m; ++j)
            if (D[i][j] <= h)
                adj[i].push_back(j);
    }

    for (int i=0; i<n; ++i) {
        if (mk >= n-i) return 1;
        ++sse;
        if (!dfs(i) && (--mk) < 0)
            return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    int T, k;
    cin>>T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> m >> k;
        for (int i=0; i<n; ++i)
            cin >> Xg[i] >> Yg[i];

        for (int i=0; i<m; ++i)
            cin >> Xh[i] >> Yh[i];

        vector<double> V;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                double xx = Xg[i]-Xh[j], yy = Yg[i]-Yh[j];
                D[i][j] = xx*xx + yy*yy;
                V.push_back(D[i][j]);
            }


        cout << "Case #" << cse << ":\n";
        if (!bpm(1e100, k))
            cout << "Too bad.\n";

        else if (V.empty())
            cout << "0.000\n";

        else {
            int lo=0, hi=!V.empty();
            sort(V.begin(), V.end());
            for (int i=1; i<V.size(); ++i)
                if (V[i]-V[i-1] > 1e-4)
                    V[hi++] = V[i];

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (bpm(V[mid], k))
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            cout << sqrt(V[hi+1]) << '\n';
        }
        cout << '\n';
    }
}
