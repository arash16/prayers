#include <bits/stdc++.h>
using namespace std;

char state[10][6],
finalS[5][6] = {
    "11111",
    "01111",
    "00 11",
    "00001",
    "00000"
};

bool isg[] = { 0, 0, 1, 1, 1, 1, 1, 0, 0 };
int dx[] = {  1, -1,  1, -1,  2, -2,  2, -2},
    dy[] = {  2,  2, -2, -2,  1,  1, -1, -1},
    maxd;


int H() {
    int cc = 0;
    for (int i=0; i<5; ++i)
        for (int j=0; j<5; ++j)
            cc += finalS[i][j] != state[i][j];
    return cc >> 1;
}

bool ida(int y, int x, int d) {
    if (memcmp(state, finalS, sizeof(finalS))==0)
        return true;

    if (d + H() > maxd) return false;

    for (int k=0; k<8; ++k)
        if (isg[x+dx[k]+2] && isg[y+dy[k]+2]) {
            swap(state[y][x], state[y+dy[k]][x+dx[k]]);
            if (ida(y+dy[k], x+dx[k], d+1))
                return true;
            swap(state[y][x], state[y+dy[k]][x+dx[k]]);
        }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    cin.ignore(100, '\n');
    while (T--) {
        int sx, sy;
        for (int i=0; i<5; ++i) {
            cin.getline(state[i], 50);

            int l = strlen(state[i]);
            while (l < 5) state[i][l++] = ' ';
            state[i][5] = 0;

            for (int j=0; j<5; ++j)
                if (state[i][j] == ' ')
                    sy = i,
                    sx = j;
        }

        for (maxd=0; maxd<=10; ++maxd)
            if (ida(sy, sx, 0)) {
                cout << "Solvable in " << maxd << " move(s).\n";
                goto fin;
            }
        cout << "Unsolvable in less than 11 move(s).\n";
        fin:;
    }
}
