#include <bits/stdc++.h>
using namespace std;

#define MAXN 143

int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN], M[MAXN], n;
bool isInside(int i, int x, int y) {
    return x>=X1[i] && x<=X2[i] && y>=Y1[i] && y<=Y2[i];
}

vector<int> adj[MAXN];
int matchL[MAXN], matchR[MAXN];
bool del[MAXN][MAXN], seen[MAXN], good[MAXN];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v] && !del[u][v]) {
            seen[v] = true;
            if (matchR[v]<0 || bpm(matchR[v])) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
    return false;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n && n; ++cse) {
        cout << "Heap " << cse << "\n";

        for (int i=0; i<n; ++i) {
            cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];
            adj[i].clear();
        }


        for (int i=0, x,y; i<n; ++i) {
            cin >> x >> y;
            for (int j=0; j<n; ++j)
                if (isInside(j, x, y))
                    adj[j].push_back(i);
        }

        memset(good, 0, n);
        memset(matchL, -1, n*sizeof(int));
        memset(matchR, -1, n*sizeof(int));
        for (int i=0; i<n; ++i) {
            memset(seen, 0, n);
            if (bpm(i)) good[i] = 1;
        }

        bool frst = 1;
        for (int i=0; i<n; ++i)
            if (good[i]) {
                int j = matchL[i];
                matchL[i] = matchR[j] = -1;
                del[i][j] = 1;
                memset(seen, 0, n);
                if (bpm(i)) good[i] = 0;
                else {
                    matchL[i] = j;
                    matchR[j] = i;


                    if (frst) frst=0;
                    else cout << ' ';
                    cout << '(' << char('A'+i) << ',' << (j+1) << ')';
                }
                del[i][j] = 0;
            }

        if (frst) cout << "none\n";
        else cout << "\n";
        cout << "\n";
    }
}
