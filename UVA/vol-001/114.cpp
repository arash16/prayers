#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int G[55][55] = {}, C[55*55], P[55*55],
        w, h, wc, m, x, y, d, l;
    cin >> w >> h >> C[1] >> m;

    for (int x=1; x<=w; ++x)
        G[x][1] = G[x][h] = 1;
    for (int y=1; y<=h; ++y)
        G[1][y] = G[w][y] = 1;

    for (int i=2; i<m+2; ++i) {
        cin >> x >> y >> P[i] >> C[i];
        G[x][y] = i;
    }

    int dx[] = {1, 0, -1, 0},
        dy[] = {0, 1, 0, -1},
        sum = 0;

    while (cin >> x >> y >> d >> l) {
        int p = 0, t;
        while (--l > 0) {
            if ((t = G[x + dx[d]][y + dy[d]])) {
                l -= C[t];
                p += P[t];
                d = (d + 3) % 4;
            }
            else {
                x += dx[d];
                y += dy[d];
            }
        }
        cout << p << endl;
        sum += p;
    }
    cout << sum << endl;
}
