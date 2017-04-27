#include <bits/stdc++.h>
using namespace std;


bool S[5][100];
int adj[5][100][2],
    D[5][100], T[5], n, k;

struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d){}
    bool operator < (const State &s) const { return d > s.d; }
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    while (cin >> n >> k) {
        for (int i=0; i<n; ++i)
            cin >> T[i];

        priority_queue<State> q;

        memset(S, 0, 100*n);
        memset(D, 127, 100*n*sizeof(int));
        cin.ignore(100, '\n');
        for (int i=0, x, l; i<n; ++i) {
            getline(cin, line);
            stringstream sin(line);
            if (sin >> l) {
                if (!l) q.push(State(i, 0, D[i][0]=0));
                adj[i][l][0] = -1; S[i][l]=1;
                for (int j=0; sin>>x; ++j) {
                    adj[i][x][0] = l;
                    adj[i][l][1] = x;
                    S[i][l = x] = 1;
                }
                adj[i][l][1] = -1;
            }
        }

        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (D[s.i][s.j] != s.d) continue;
            if (s.j == k) {
                cout << s.d << endl;
                goto fin;
            }

            for (int k=0; k<2; ++k) {
                int v = adj[s.i][s.j][k];
                if (v!=-1) {
                    int d = s.d + T[s.i]*(s.j>v ? s.j-v : v-s.j);
                    if (d < D[s.i][v])
                        q.push(State(s.i, v, D[s.i][v]=d));
                }
            }

            for (int k=0; k<n; ++k) if (k!=s.i && S[k][s.j]) {
                int d = s.d + 60;
                if (d < D[k][s.j])
                    q.push(State(k, s.j, D[k][s.j]=d));
            }
        }
        cout << "IMPOSSIBLE\n";
        fin:;
    }
}
