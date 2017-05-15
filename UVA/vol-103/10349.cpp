#include <bits/stdc++.h>
using namespace std;


vector<int> adj[416];
bool seen[416];
int match[416];
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

    string M[43];
    int I[43][43], T, r, c;
    cin >> T;
    while (T-- && cin >> r >> c) {
        for (int i=0; i<r; ++i)
            cin >> M[i];

        int ln=0, rn=0;
        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j)
                if (M[i][j] == '*')
                    I[i][j] = (i+j)&1 ? ln++ : rn++;

        for (int i=0; i<ln; ++i)
            adj[i].clear();

        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j)
                if (M[i][j] == '*') {
                    int u = I[i][j];
                    if ((i+j)&1) {
                        if (i<r-1 && M[i+1][j] == '*')
                            adj[u].push_back(I[i+1][j]);

                        if (j<c-1 && M[i][j+1] == '*')
                            adj[u].push_back(I[i][j+1]);
                    }
                    else {
                        if (i<r-1 && M[i+1][j] == '*')
                            adj[I[i+1][j]].push_back(u);

                        if (j<c-1 && M[i][j+1] == '*')
                            adj[I[i][j+1]].push_back(u);
                    }
                }

        int cnt = ln + rn;
        memset(match, -1, rn*sizeof(int));
        for (int i=0; i<ln; ++i) {
            memset(seen, 0, rn);
            if (bpm(i)) --cnt;
        }
        cout << cnt << '\n';
    }
}
