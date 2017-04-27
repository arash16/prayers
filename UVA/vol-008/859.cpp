#include <bits/stdc++.h>
using namespace std;

struct State {
    int y, x, c;
    State (int y, int x, int c):y(y),x(x),c(c){}
    bool operator < (const State &s) const { return y!=s.y ? y > s.y : x < s.x; }
};


bool seen[1000][1000], M[1000][1000];
int dx[] = {-1,0,1,-1,1},
    dy[] = { 0,1,0, 1,1},
    n, m;

bool check(State &s) { return s.x>0 && s.x<=m && s.y<=n; }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool frst = 1;
    int x, y, sx, sy;
    while (cin >> n >> m) {
        if (frst) frst = 0;
        else cout << endl;

        for (int i=1; i<=n; ++i) {
            memset(seen[i]+1, 0, m);
            memset(M[i]+1, 0, m);
        }

        for (int i=0; i<4*m; ++i) {
            cin >> y >> x;
            M[y][x] = 1;
        }
        cin >> sy >> sx;

        vector<State> v;
        for (int k=0; k<3; ++k) {
            State t(sy+dy[k], sx+dx[k], 1);
            if (check(t) && !M[t.y][t.x])
                v.push_back(t);
        }

        queue<State> q;
        q.push(State(sy, sx, 0));
        while (!q.empty()) {
            State s = q.front(); q.pop();
            for (int k=0; k<5; ++k) {
                State t(s.y+2*dy[k], s.x+2*dx[k], s.c+1);
                if (check(t) && !M[t.y][t.x] && !seen[t.y][t.x] && M[t.y-dy[k]][t.x-dx[k]]) {
                    seen[t.y][t.x] = 1;
                    v.push_back(t);
                    q.push(t);
                }
            }
        }


        sort(v.begin(), v.end());
        for (State &s: v)
            cout << s.y << ' ' << s.x << ' ' << s.c << endl;
    }
}
