#include <iostream>
using namespace std;


char X[200][200];
int dx[] = {0,1,0,-1},
    dy[] = {1,0,-1,0}, n;
void dfs(int y, int x) {
    if (y<0 || y>=n || x<0 || x>=n || X[y][x]=='.')
        return;

    X[y][x] = '.';
    for (int i=0; i<4; ++i)
        dfs(y+dy[i], x+dx[i]);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int cse=1, T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> X[i];

        int cnt = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (X[i][j] == 'x') {
                    dfs(i, j);
                    ++cnt;
                }

        cout << "Case " << (cse++) << ": " << cnt << endl;
    }
}
