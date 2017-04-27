#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    State(int x, int y):x(x),y(y){}
};

int dy[] = {0,0,1,-1},
    dx[] = {1,-1,0,0};

int fnd(int x, int y) {
    for (int i=0; i<4; ++i)
        if (dy[i]==y && dx[i]==x)
            return i;
    return -1;
}

bool B[117][117][4],
    S[117][117];
int T[117][117][517],
    D[117][117],
    dn[117*117*500];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int nv, nh, c, x1, y1, x2, y2, tm;
    for (int cse=1; cin>>nv>>nh; ++cse) {
        memset(dn, 0, nv*nh*sizeof(int));
        for (int i=0; i<nv; ++i) {
            memset(S[i],  0, nh);
            memset(B[i],  0, nh*4);
            memset(T[i], -1, nh*sizeof(int));
        }

        cin >> c;
        for (int i=0; i<c; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            int id = fnd(x2-x1, y2-y1);
            if (id != -1)
                B[x1][y1][id] = cse;
        }

        cin >> c;
        for (int i=0; i<c; ++i) {
            cin >> tm >> x1 >> y1;
            T[x1][y1][tm] = cse;
        }

        queue<State> q;
        q.push(State(0,0));
        S[0][0] = dn[0] = 1;
        for (tm=0; !q.empty();) {
            if (!dn[tm]) ++tm;

            State s = q.front(); q.pop();
            if (D[s.x][s.y] > tm) q.push(s);
            else {
                if (s.x==nv-1 && s.y==nh-1) {
                    cout << D[s.x][s.y] << endl;
                    goto fin;
                }

                --dn[tm];
                for (int i=0; i<4; ++i)
                    if (!B[s.x][s.y][i]) {
                        State t(s.x+dx[i], s.y+dy[i]);
                        if (t.x>=0 && t.y>=0 && t.x<nv && t.y<nh) {
                            int tt = D[s.x][s.y]+1;
                            while (T[t.x][t.y][tt] == cse)
                                ++tt;

                            if (!S[t.x][t.y]) {
                                S[t.x][t.y] = 1;
                                D[t.x][t.y] = tt;
                                q.push(t);
                                ++dn[tt];
                            }
                            else if (tt < D[t.x][t.y]) {
                                --dn[D[t.x][t.y]];
                                ++dn[tt];

                                D[t.x][t.y] = tt;
                            }
                        }
                    }
            }
        }
        cout << "0\n";
        fin:;
    }
}
