#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct Cell {
    int r, c, d;
    Cell(int r, int c, int d): r(r), c(c), d(d) {}
};

int dr[]={0, 0, 1, -1},
    dc[]={1, -1, 0, 0};

bool mp[1001][1001];


int main(){
    int R, C, r, c, rn, cn, r0, c0, r1, c1;
    while (cin>>R>>C && (R||C)) {
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                mp[i][j]=0;

        cin >> rn;
        for (int i=0; i<rn; i++) {
            cin >> r >> cn;
            for (int j=0; j<cn; j++) {
                cin >> c;
                mp[r][c] = 1;
            }
        }
        cin>>r0>>c0>>r1>>c1;

        int result=-1;
        queue<Cell> q;
        q.push(Cell(r0, c0, 0));
        while (!q.empty()) {
            Cell p = q.front(); q.pop();
            if (p.r==r1 && p.c==c1) {
                result = p.d;
                break;
            }

            mp[p.r][p.c] = 1;
            for (int i=0; i<4; i++) {
                int nr = p.r + dr[i], nc = p.c + dc[i];

                if (nr>=0 && nr<R && nc>=0 && nc<C && !mp[nr][nc]) {
                    q.push(Cell(nr, nc, p.d + 1));
                    mp[nr][nc] = 1;
                }
            }
        }
        cout << result << endl;
    }
}
