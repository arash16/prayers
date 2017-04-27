#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    State(int x, int y):x(x),y(y){}
};

char S[7][7];
void printPath(int sx, int sy, int tx, int ty) {
    if (sx==tx && sy==ty) return;
    switch (S[tx][ty]) {
        case 'E':
            printPath(sx, sy, tx-1, ty);
            break;
        case 'S':
            printPath(sx, sy, tx, ty-1);
            break;
        case 'W':
            printPath(sx, sy, tx+1, ty);
            break;
        case 'N':
            printPath(sx, sy, tx, ty+1);
            break;
    }
    cout << S[tx][ty];
}


bool RB[7][7], DB[7][7];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int sx, sy, tx, ty;
    while (cin >> sx >> sy && (sx||sy)) {
        cin >> tx >> ty;

        memset(S, 0, sizeof(S));
        memset(DB, 0, sizeof(DB));
        memset(RB, 0, sizeof(RB));
        for (int i=0; i<3; ++i) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (y1 == y2) {
                if (x1 > x2)
                    swap(x1, x2);
                for (int x=x1+1; x<=x2; ++x)
                    DB[x][y1] = 1;
            }

            if (x1 == x2) {
                if (y1 > y2)
                    swap(y1, y2);
                for (int y=y1+1; y<=y2; ++y)
                    RB[x1][y] = 1;
            }
        }

        queue<State> q;
        q.push(State(sx, sy));
        S[sx][sy] = 1;
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.x == tx && s.y == ty)
                break;

            if (s.x>1 && !S[s.x-1][s.y] && !RB[s.x-1][s.y]) {
                q.push(State(s.x-1, s.y));
                S[s.x-1][s.y] = 'W';
            }

            if (s.y>1 && !S[s.x][s.y-1] && !DB[s.x][s.y-1]) {
                q.push(State(s.x, s.y-1));
                S[s.x][s.y-1] = 'N';
            }

            if (s.x<6 && !S[s.x+1][s.y] && !RB[s.x][s.y]) {
                q.push(State(s.x+1, s.y));
                S[s.x+1][s.y] = 'E';
            }

            if (s.y<6 && !S[s.x][s.y+1] && !DB[s.x][s.y]) {
                q.push(State(s.x, s.y+1));
                S[s.x][s.y+1] = 'S';
            }
        }

        printPath(sx, sy, tx, ty);
        cout << endl;
    }
}
