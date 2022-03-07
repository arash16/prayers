/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11487
  Name: Gathering Food
  Problem: https://onlinejudge.org/external/114/11487.pdf
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

#define MODUL 20437
char M[17][17];
int Pi[26], Pj[26], C[11][11], n,
    di[] = {1,-1,0,0},
    dj[] = {0,0,1,-1};

int bfs(int sid, int &c) {
    memset(C, 0, sizeof(C));
    char sch = 'A' + sid,
         dch = 'A' + sid + 1;

    queue<State> q;
    C[Pi[sid]][Pj[sid]] = 1;
    q.push(State(Pi[sid], Pj[sid], 0));
    while (!q.empty()) {
        State s = q.front(); q.pop();
        if (M[s.i][s.j] == dch) {
            c = C[s.i][s.j];
            return s.d;
        }

        for (int k=0; k<4; ++k) {
            State t(s.i+di[k], s.j+dj[k], s.d+1);
            if (M[t.i][t.j]=='.' || (M[t.i][t.j]>='A' && M[t.i][t.j]<=dch)) {
                if (!C[t.i][t.j])
                    q.push(t);

                C[t.i][t.j] += C[s.i][s.j];
                C[t.i][t.j] %= MODUL;
            }
        }
    }
    return c = 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    memset(M, '#', sizeof(M));
    for (int cse=1; cin >> n && n; ++cse) {
        int m = 0;
        for (int i=1; i<=n; ++i) {
            cin >> (M[i]+1);
            M[i][n+1] = '#';
            M[i][n+2] = 0;

            for (int j=1; j<=n; ++j)
                if (M[i][j]>='A') {
                    int id = M[i][j] - 'A';
                    m = max(m, id);
                    Pi[id] = i;
                    Pj[id] = j;
                }
        }
        memset(M[n+1], '#', 17);

        int sum=0, cnt=1;
        for (int i=0, c; cnt && i<m; ++i) {
            sum += bfs(i, c);
            cnt = ((long long) cnt * c) % MODUL;
        }

        cout << "Case " << cse << ": ";

        if (!cnt) cout << "Impossible\n";
        else cout << sum << ' ' << cnt << "\n";
    }
}
