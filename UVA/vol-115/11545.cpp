/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11545
  Name: Avoiding Jungle in the Dark
  Problem: https://onlinejudge.org/external/115/11545.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

struct State {
    int i, d;
    State(int i, int d):i(i),d(d){}
    bool operator < (const State &o) const { return d-i > o.d-o.i; }
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, D[1043][24];
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        string M;
        cin >> M;
        for (int i=0; i<=M.length(); ++i)
            for (int j=0; j<24; ++j)
                D[i][j] = INF;

        int result = -1;
        priority_queue<State> q;
        q.push(State(0, D[0][0]=0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (s.d != D[s.i][s.d%24]) continue;
            if (M[s.i] == 'D') {
                result = s.d;
                break;
            }


            // rest here one more 8hours
            if (s.d+8 < D[s.i][(s.d+8)%24])
                q.push(State(s.i, D[s.i][(s.d+8)%24] = s.d+8));


            int bj = -1;
            for (int i=1; i<=16 && s.i+i<M.length(); ++i) {
                if (M[s.i+i]=='*') {
                    int t = (s.d+i)%24;
                    if (!t || t>=12)
                        break;
                }
                else bj = i;
            }

            if (bj != -1) {
                int ii = s.i + bj,
                    dd = s.d + bj + (M[ii]!='D' ? 8 : 0);

                if (dd < D[ii][dd%24])
                    q.push(State(ii, D[ii][dd%24] = dd));
            }
        }
        cout << "Case #" << cse << ": " << result << endl;
    }
}
