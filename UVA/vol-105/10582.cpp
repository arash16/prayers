#include <bits/stdc++.h>
using namespace std;


#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

int di[] = { -1, 0, 1,  0 },
    dj[] = {  0, 1, 0, -1 };

int M[77][77], r, c;
int dfs(int i, int j, int dir) {
    if (i<0 || i>=r || j<0 || j>=c || !M[i][j]) return 0;
    if (i==r-1 && j==c-1) return 1;

    int o = M[i][j];
    M[i][j] = 0;

    int r = 0;
    if (o == 1)
        r += dfs(i-di[dir], j-dj[dir], dir);

    else if (dir==TOP || dir==BOTTOM) {
        r += dfs(i+di[LEFT], j+dj[LEFT], RIGHT);
        r += dfs(i+di[RIGHT], j+dj[RIGHT], LEFT);
    }

    else if (dir==LEFT || dir==RIGHT) {
        r += dfs(i+di[TOP], j+dj[TOP], BOTTOM);
        r += dfs(i+di[BOTTOM], j+dj[BOTTOM], TOP);
    }

    M[i][j] = o;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    char S[3][512];
    while (T-- && cin >> r >> c) {
        cin.ignore(512, '\n');
        for (int i=0; i<r; ++i) {
            cin.ignore(512, '\n');
            for (int j=0; j<3; ++j)
                cin.getline(S[j], 512);

            for (int j=0; j<c; ++j) {
                int o = j<<2;
                M[i][j] = (S[1][o+2]==' ') ? 0 : (S[0][o+2]==S[2][o+2] || S[1][o+1]==S[1][o+3]) ? 1 : 2;
            }
        }
        cin.ignore(512, '\n');

        cout << "Number of solutions: " << (dfs(0, 0, TOP)+dfs(0, 0, LEFT)) << '\n';
    }
}
