#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
#define ff first
#define ss second

bool inq[143][143];
int di[] = {1,-1,0,0},
    dj[] = {0,0,1,-1};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int D[143][143], X[143][143], T, n, d;
    cin >> T;
    while (T-- && cin >> n >> d) {
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> X[i][j];
                D[i][j] = 0;
            }

        queue<Pair> q;
        q.push(Pair(0, 0));
        D[0][0] = 0;

        int mxr = 0;
        while (!q.empty()) {
            Pair s = q.front(); q.pop();
            int score = D[s.ff][s.ss] + X[s.ff][s.ss];
            mxr = max(mxr, score);
            inq[s.ff][s.ss] = 0;

            for (int k=1; k<=d; ++k)
                for (int dir=0; dir<4; ++dir) {
                    Pair t(s.ff + k*di[dir], s.ss + k*dj[dir]);
                    if (t.ff>=0 && t.ff<n && t.ss>=0 && t.ss<n)
                    if (X[t.ff][t.ss] > X[s.ff][s.ss]) {
                        if (D[t.ff][t.ss] < score) {
                            D[t.ff][t.ss] = score;
                            if (!inq[t.ff][t.ss]) {
                                inq[t.ff][t.ss] = 1;
                                q.push(t);
                            }
                        }
                    }
                }
        }
        cout << mxr << '\n';
        if (T) cout << '\n';
    }
}
