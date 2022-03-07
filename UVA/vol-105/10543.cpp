/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10543
  Name: Traveling Politician
  Problem: https://onlinejudge.org/external/105/10543.pdf
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

    int n, m, k;
    vector<int> adj[55];
    while (cin>>n>>m>>k && (n||m||k)) {
        bool seen[55][21]={};
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int u, v; m--; ) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        queue<State> q;
        q.push(State(0, 1));
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.u==n-1 && s.d>=k) {
                cout << s.d << "\n";
                goto fin;
            }

            if (s.d < 20)
                for (int v: adj[s.u])
                    if (!seen[v][s.d+1]) {
                        seen[v][s.d+1] = 1;
                        q.push(State(v, s.d+1));
                    }
        }
        cout << "LOSER\n";
        fin:;
    }
}
