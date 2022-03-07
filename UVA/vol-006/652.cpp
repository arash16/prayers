/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 652
  Name: Eight
  Problem: https://onlinejudge.org/external/6/652.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> R;
const char finstr[] = "012345678";
struct State {
    string p;
    char s[10];
    int zid, sx;
    State() {}

    void recalc() {
        sx = 0;
        for (int i=0; i<9; ++i)
            sx = sx*10 + s[i] - '0';
    }
}
Q[400414];

char dn[] = "rldu";
int dd[] = {-1, 1, -3, 3},
    dy[] = {0, 0, -1, 1},
    dx[] = {-1, 1, 0, 0},
    isg[] = { 0, 1, 1, 1, 0 };

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int sz = 1;
    Q[0].zid = 8;
    Q[0].recalc();
    memcpy(Q[0].s, finstr, sizeof(finstr));

    for (int i=0; i<sz; ++i) {
        State &s = Q[i];

        int y = s.zid / 3, x = s.zid % 3;
        for (int k=0; k<4; ++k)
            if (isg[y+dy[k]+1] && isg[x+dx[k]+1]) {
                State &t = Q[sz];

                memcpy(t.s, s.s, sizeof(t.s));
                swap(t.s[s.zid], t.s[s.zid + dd[k]]);
                t.zid = s.zid + dd[k];
                t.p = dn[k] + s.p;
                t.recalc();
                if (R.emplace(t.sx, t.p).second)
                    ++sz;
            }
    }


    int T;
    char ch;
    cin >> T;
    while (T--) {
        int sx = 0;
        for (int i=0; i<9; ++i) {
            cin >> ch;
            sx = sx*10 + (ch == 'x' ? 8 : ch-'1');
        }

        auto it = R.find(sx);
        if (it == R.end())
             cout << "unsolvable\n";
        else cout << (it->second) << '\n';

        if (T) cout << '\n';
    }
}
