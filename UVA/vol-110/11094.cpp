#include <bits/stdc++.h>
using namespace std;

int n, m;
char M[100][100], land;
int dfs(int y, int x) {
    if (x < 0) x += m;
    if (M[y][x] != land)
        return 0;
    M[y][x] = 0;

    int result = 1;
    result += dfs(y, (x-1)%m);
    result += dfs(y, (x+1)%m);
    if (y > 0) result += dfs(y-1, x);
    if (y<n-1) result += dfs(y+1, x);
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x, y;
    while (cin >> n >> m && (n||m)) {
        for (int i=0; i<n; ++i)
            cin >> M[i];

        cin >> y >> x;
        land = M[y][x];
        dfs(y, x);

        int mx = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
                if (M[i][j] == land)
                    mx = max(mx, dfs(i, j));
        cout << mx << endl;
    }
}
