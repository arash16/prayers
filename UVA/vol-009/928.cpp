/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 928
  Name: Eternal Truths
  Problem: https://onlinejudge.org/external/9/928.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct State {
    int i, j, s, d;
    State(int i, int j, int s, int d):i(i),j(j),s(s),d(d){}
};

int di[] = {1, -1, 0, 0},
    dj[] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char M[313][313];
    bool S[313][313][3];
    int T, r, c, si, sj;
    cin >> T;
    while (T-- && cin >> r >> c) {
        for (int i=0; i<r; ++i) {
            cin >> M[i];
            for (int j=0; j<c; ++j) {
                if (M[i][j] == 'S')
                    si = i,
                    sj = j;
                memset(S[i][j], 0, 3);
            }
        }

        queue<State> q;
        q.push(State(si, sj, 0, 0));
        S[si][sj][0] = 1;
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (M[s.i][s.j] == 'E') {
                cout << s.d << '\n';
                goto fin;
            }

            int len = s.s + 1;
            for (int k=0; k<4; ++k) {
                State t(s.i + len*di[k], s.j + len*dj[k], len%3, s.d+1);
                if (t.i>=0 && t.i<r && t.j>=0 && t.j<c && !S[t.i][t.j][t.s]) {
                    for (int l=1; l<=len; ++l)
                        if (M[s.i + l*di[k]][s.j + l*dj[k]]=='#')
                            goto blocked;

                    S[t.i][t.j][t.s] = 1;
                    q.push(t);
                    blocked:;
                }
            }
        }
        cout << "NO\n";
        fin:;
    }
}
