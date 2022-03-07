/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 825
  Name: Walking on the Safe Side
  Problem: https://onlinejudge.org/external/8/825.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d){}
};

long long DP[143][143];
int D[143][143], n, m;
bool B[143][143];

int di[] = {1,0,-1,0},
    dj[] = {0,1,0,-1};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            memset(B[i], 0, m),
            memset(D[i], 127, m*sizeof(int)),
            memset(DP[i],  0, m*sizeof(long long));

        for (int i=0, u,v; i<n; ++i) {
            cin >> u;
            string line;
            getline(cin, line);
            stringstream sin(line);
            while (sin >> v)
                B[u-1][v-1] = 1;
        }

        queue<State> q;
        if (!B[0][0]) {
            q.push(State(0,0,D[0][0]=0));
            DP[0][0] = 1;
        }
        while (!q.empty()) {
            State s = q.front(); q.pop();

            for (int k=0; k<2; ++k) {
                int ni = s.i + di[k],
                    nj = s.j + dj[k],
                    nd = s.d + 1;

                if (ni>=0 && ni<n && nj>=0 && nj<m && !B[ni][nj] && nd<=D[ni][nj]) {
                    if (D[ni][nj] > nd)
                        q.push(State(ni, nj, D[ni][nj] = nd));

                    DP[ni][nj] += DP[s.i][s.j];
                }
            }
        }

        cout << DP[n-1][m-1] << "\n";
        if (T) cout << "\n";
    }
}
