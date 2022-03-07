/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 910
  Name: TV game
  Problem: https://onlinejudge.org/external/9/910.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct State {
    int u, d;
    State(int u, int d):u(u),d(d){}
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int adj[43][2], S[43], C[43][43], n, m;
    while (cin >> n) {
        for (int i=0; i<n; ++i) {
            char c1, c2, c3, c4;
            cin >> c1 >> c2 >> c3 >> c4;
            int u = c1-'A';
            adj[u][0] = c2 - 'A';
            adj[u][1] = c3 - 'A';
            S[u] = c4 == 'x';
        }

        cin >> m;
        for (int i=0; i<n; ++i)
            memset(C[i], 0, (m+1)*sizeof(int));
        C[0][0] = 1;

        queue<State> q;
        q.push(State(0, 0));
        while (!q.empty()) {
            State s = q.front(); q.pop();
            int c = C[s.u][s.d];
            if (s.d < m)
                for (int i=0; i<2; ++i) {
                    int v = adj[s.u][i];
                    if (!C[v][s.d+1])
                        q.push(State(v, s.d+1));
                    C[v][s.d+1] += c;
                }
        }

        int sum = 0;
        for (int i=0; i<n; ++i) if (S[i])
            sum += C[i][m];
        cout << sum << endl;
    }
}
