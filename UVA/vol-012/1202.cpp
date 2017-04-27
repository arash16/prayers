#include <bits/stdc++.h>
#define INF 67108864
using namespace std;


struct State {
    int x, y, d;
    State(int x, int y, int d):y(y),x(x),d(d){}
    bool operator < (const State &o) const { return d > o.d; }
};

int D[201][201];
char L[201][201], B[201][201];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m, n, x, y, d, t;
    while (cin >> m >> n && m>-1) {
        int w = 0, h = 0;
        while (m--) {
            cin >> x >> y >> d >> t;

            for (int mxw=x+(d?0:t); w<=mxw; ++w)
                for (int i=0; i<h; ++i)
                    L[w][i] = B[w][i] = 0;

            for (int mxh=y+(d?t:0); h<=mxh; ++h)
                for (int i=0; i<w; ++i)
                    L[i][h] = B[i][h] = 0;

            if (d)    for (int i=0; i<t; ++i)
                        L[x][y+i] = 1;
            else    for (int i=0; i<t; ++i)
                        B[x+i][y] = 1;
        }

        while (n--) {
            cin >> x >> y >> d;
            if (d)    L[x][y] = 2;
            else    B[x][y] = 2;
        }


        double f1, f2;
        cin >> f1 >> f2;
        int dx = f1, dy = f2;
        if (dx>=w || dy>=h) {
            cout << "0\n";
            continue;
        }

        for (int i=0; i<w; ++i)
            for (int j=0; j<h; ++j)
                D[i][j] = INF;

        priority_queue<State> q;
        q.push(State(0, 0, D[0][0]=0));
        while (!q.empty()) {
            State s = q.top(); q.pop();
            if (s.d != D[s.x][s.y]) continue;
            if (s.x == dx  && s.y == dy) {
                cout << s.d << endl;
                goto fin;
            }

            if (s.x && L[s.x][s.y]!=1) {
                int d = s.d + (L[s.x][s.y]==2);
                if (d < D[s.x-1][s.y])
                    q.push(State(s.x-1, s.y, D[s.x-1][s.y]=d));
            }

            if (s.y && B[s.x][s.y]!=1) {
                int d = s.d + (B[s.x][s.y]==2);
                if (d < D[s.x][s.y-1])
                    q.push(State(s.x, s.y-1, D[s.x][s.y-1]=d));
            }

            if (s.x < w-1 && L[s.x+1][s.y]!=1) {
                int d = s.d + (L[s.x+1][s.y]==2);
                if (d < D[s.x+1][s.y])
                    q.push(State(s.x+1, s.y, D[s.x+1][s.y]=d));
            }

            if (s.y < h-1 && B[s.x][s.y+1]!=1) {
                int d = s.d + (B[s.x][s.y+1]==2);
                if (d < D[s.x][s.y+1])
                    q.push(State(s.x, s.y+1, D[s.x][s.y+1]=d));
            }
        }
        cout << "-1\n";
        fin:;
    }
}
