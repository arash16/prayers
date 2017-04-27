#include <bits/stdc++.h>
#define INF 268435456
using namespace std;

struct State {
    int i, j;
    State(int i, int j):i(i),j(j) {};
};

char M[143][143];
int seen[143][143], n,
    di[] = {0,0,1,-1},
    dj[] = {1,-1,0,0};

int bfs(int si, int sj, int cse) {
    seen[si][sj] = cse;
    queue<State> q;
    q.push(State(si, sj));
    while (!q.empty()) {
        State s = q.front(); q.pop();
        if (M[s.i][s.j] == '3')
            return abs(s.i-si) + abs(s.j-sj);

        for (int k=0; k<4; ++k) {
            State t(s.i+di[k], s.j+dj[k]);
            if (t.i>=0 && t.i<n && t.j>=0 && t.j<n)
                if (seen[t.i][t.j] != cse) {
                    seen[t.i][t.j] = cse;
                    q.push(t);
                }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int cse = 0;
    while (cin >> n) {
        for (int i=0; i<n; ++i)
            cin >> M[i];

        int mx = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (M[i][j] == '1')
                    mx = max(mx, bfs(i, j, ++cse));
        cout << mx << '\n';
    }
}
