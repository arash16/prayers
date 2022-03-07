/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 314
  Name: Robot
  Problem: https://onlinejudge.org/external/3/314.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

struct State {
    int t;
    char i, j, d;
    State(char i, char j, char d, int t):i(i),j(j),d(d),t(t){}
};


bool B[99][99], C[99][99],
     seen[99][99][4];

int dirid[200],
    di[] = {-1, 0, 1,  0},
    dj[] = { 0, 1, 0, -1};

void pushS(queue<State> &q, int i, int j, int d, int t) {
    if (!seen[i][j][d]) {
        seen[i][j][d] = true;
        q.push(State(i, j, d, t));
    }
}

bool readBool() {
    char ch;
    while ((ch=getchar())!='0' && ch!='1');
    return ch-'0';
}

int main(){
    int n, m, si, sj, ei, ej;
    char dir[20];
    dirid['n'] = 0; dirid['e'] = 1;
    dirid['s'] = 2; dirid['w'] = 3;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                B[i][j] = readBool();
                memset(seen[i][j], 0, 4);
            }

        for (int i=0; i<=n; ++i)
            for (int j=0; j<=m; ++j) {
                if (!i || !j || i==n || j==m)
                     C[i][j] = 0;
                else C[i][j] = !B[i][j] && !B[i][j-1] && !B[i-1][j] && !B[i-1][j-1];
            }

        int result = -1;
        queue<State> q;

        scanf("%d%d%d%d%s", &si, &sj, &ei, &ej, dir);
        pushS(q, si, sj, dirid[dir[0]], 0);
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.i == ei && s.j == ej) {
                result = s.t;
                break;
            }

            pushS(q, s.i, s.j, (s.d+1)%4, s.t+1);
            pushS(q, s.i, s.j, (s.d+3)%4, s.t+1);
            for (int k=1; k<=3; ++k) {
                int ni = s.i + k*di[s.d],
                    nj = s.j + k*dj[s.d];
                if (!C[ni][nj]) break;
                pushS(q, ni, nj, s.d, s.t+1);
            }
        }

        printf("%d\n", result);
    }
}
