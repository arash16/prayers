/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 590
  Name: Always on the run
  Problem: https://onlinejudge.org/external/5/590.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


struct State {
    int u, d, c;
    State(int u, int d, int c):u(u),d(d),c(c) {}
    bool operator < (const State& o) const { return c > o.c; }
};



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int FC[17][17][43], FD[17][17], C[17][1043], n, m;
    for (int cse=1; cin >> n >> m && (n||m); ++cse) {
        cout << "Scenario #" << cse << "\n";

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) if (i!=j) {
                cin >> FD[i][j];
                for (int k=0; k<FD[i][j]; ++k)
                    cin >> FC[i][j][k];
            }

        for (int i=0; i<n; ++i)
            for (int d=0; d<=m; ++d)
                C[i][d] = INF;

        priority_queue<State> q;
        q.push(State(0, 0, C[0][0] = 0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (s.c != C[s.u][s.d]) continue;
            if (s.d==m && s.u==n-1) {
                cout << "The best flight costs " << s.c << ".\n";
                goto fin;
            }

            if (s.d < m)
            for (int j=0; j<n; ++j)
                if (s.u!=j && FD[s.u][j]) {
                    int fc = FC[s.u][j][ s.d % FD[s.u][j] ];
                    if (fc && s.c+fc < C[j][s.d+1])
                        q.push(State(j, s.d+1, C[j][s.d+1]=s.c+fc));
                }
        }

        cout << "No flight possible.\n";
        fin:
        cout << "\n";
    }
}
