/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10967
  Name: The Great Escape
  Problem: https://onlinejudge.org/external/109/10967.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int X[143][143], D[143][143];
char M[143][143], tch;
struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d){}
    bool operator < (const State &o) const { return d > o.d; }
};


char dd[] = "NWSE";
int dk[128],
    di[] = {1, 0, -1, 0},
    dj[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    dk['N']=2; dk['S']=0;
    dk['E']=1; dk['W']=3;

    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i)
            cin >> M[i];

        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                D[i][j] = INF;
                X[i][j] = 0;
                if (M[i][j]!='.' && M[i][j]!='#')
                    cin >> X[i][j];
            }

        priority_queue<State> q;
        q.push(State(n-1, 0, D[n-1][0]=0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (D[s.i][s.j] != s.d) continue;

            if (!s.i && s.j==m-1) {
                cout << s.d << '\n';
                goto fin;
            }

            int ski = dk[M[s.i][s.j]];
            for (int k=0; k<4; ++k) {
                State t(s.i+di[k], s.j+dj[k], s.d+1);
                if (t.i>=0 && t.i<n && t.j>=0 && t.j<m && (tch = M[t.i][t.j])!='#')
                    if (tch=='.' || tch==dd[k]) {
                        int kdd = abs(ski - k);
                        if (kdd>2) kdd = 4-kdd;
                        t.d += kdd * X[s.i][s.j];
                        if (D[t.i][t.j] > t.d) {
                            D[t.i][t.j] = t.d;
                            q.push(t);
                        }
                    }
            }
        }
        cout << "Poor Kianoosh\n";
        fin:;
    }
}
