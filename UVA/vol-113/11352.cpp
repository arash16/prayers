/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11352
  Name: Crazy King
  Problem: https://onlinejudge.org/external/113/11352.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d){}
    bool operator == (const State &s) const { return i==s.i && j==s.j; }
};


bool B[120][120];
int dy[] = {0, 1,-1,1,-1, 2,-2,2,-2},
    dx[] = {0, 2,2,-2,-2, 1,1,-1,-1};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    char ch;
    int T; cin>>T;
    for (int cse=1; cse<=T; ++cse) {
        int n, m; cin >> n >> m;

        memset(B, -1, sizeof(B));
        for (int i=2; i<n+2; ++i)
            for (int j=2; j<m+2; ++j)
                B[i][j] = 0;


        queue<State> q;
        State dst(0,0,0);
        for (int i=2; i<n+2; ++i) {
            cin.ignore(100, '\n');

            for (int j=2; j<m+2; ++j) {
                cin.get(ch);
                if (ch == 'A')
                    q.push(State(i, j, 0));
                else if (ch == 'B')
                    dst = State(i, j, -1);
                else if (ch == 'Z')
                    for (int k=0; k<9; ++k)
                        B[i+dy[k]][j+dx[k]] = 1;
            }
        }


        while (!q.empty()) {
            State s=q.front(); q.pop();
            for (int i=-1; i<2; ++i)
                for (int j=-1; j<2; ++j)
                    if (i || j) {
                        State t(s.i+i, s.j+j, s.d+1);
                        if (t == dst) {
                            cout << "Minimal possible length of a trip is " << t.d << endl;
                            goto fin;
                        }
                        if (!B[t.i][t.j]) {
                            B[t.i][t.j] = 1;
                            q.push(t);
                        }
                    }
        }

        cout << "King Peter, you can't go now!\n";
        fin:;
    }
}
