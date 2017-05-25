#include <bits/stdc++.h>
using namespace std;


struct State {
    int r, l, d;
    State(int r, int l, int d):r(r),l(l),d(d){}
};


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);


    int S[17][2048]={}, Pr[17][2048], Pt[17][2048], pr[10240], pt[10240], n, m, s, u, v;
    vector<int> adj[17], ads[17];
    for (int cse=1; cin >> n >> m >> s && (n||m||s); ++cse) {
        for (int i=0; i<n; ++i)
            adj[i].clear(),
            ads[i].clear();

        for (int i=0; i<m; ++i) {
            cin >> u >> v; --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i=0; i<s; ++i) {
            cin >> u >> v; --u; --v;
            if (u != v)
                ads[u].push_back(v);
        }

        int ll = 1<<(n-1);
        cout << "Villa #" << cse << '\n';
        queue<State> q;
        q.push(State(0, 1, 0));
        S[0][1] = cse;
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.r==n-1 && s.l==ll) {
                cout << "The problem can be solved in " << s.d << " steps:\n";
                for (int i=s.d-1, r=s.r, l=s.l; i>=0; --i) {
                    if (Pt[r][l] == 1)
                        l^=1<<(pr[i]=Pr[r][l]),
                        pt[i] = l&(1<<pr[i]) ? 2 : 1;
                    else
                        pt[i] = 3,
                        pr[i] = r,
                        r = Pr[r][l];
                }
                for (int i=0; i<s.d; ++i)
                    if (pt[i] == 1)
                        cout << "- Switch on light in room " << pr[i]+1 << ".\n";
                    else if (pt[i] == 2)
                        cout << "- Switch off light in room " << pr[i]+1 << ".\n";
                    else
                        cout << "- Move to room " << pr[i]+1 << ".\n";
                goto fin;
            }

            for (int r: adj[s.r])
                if (S[r][s.l] != cse && (1<<r&s.l)) {
                    S[r][s.l]  = cse;
                    Pr[r][s.l] = s.r;
                    Pt[r][s.l] = 2;
                    q.push(State(r, s.l, s.d+1));
                }

            for (int r: ads[s.r]) {
                int l2 = 1<<r^s.l;
                if (S[s.r][l2] != cse) {
                    S[s.r][l2]  = cse;
                    Pr[s.r][l2] = r;
                    Pt[s.r][l2] = 1;
                    q.push(State(s.r, l2, s.d+1));
                }
            }
        }
        cout << "The problem cannot be solved.\n";
        fin: cout << '\n';
    }
}
