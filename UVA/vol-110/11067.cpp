#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool B[143][143];
    unsigned int C[143][143], w, h, n;
    while (cin >> w >> h >> n) {
        for (int i=0; i<=h; ++i)
            memset(B[i], 0, (w+1)),
            memset(C[i], 0, (w+1)*sizeof(int));

        for (int i=0, x,y; i<n; ++i) {
            cin >> x >> y;
            B[y][x] = 1;
        }

        C[0][0] = 1;
        for (int i=0; i<=h; ++i)
            for (int j=0; j<=w; ++j)
                if (!B[i][j])
                    C[i+1][j] += C[i][j],
                    C[i][j+1] += C[i][j];

        int res = C[h][w];
        if (res > 1)
            cout << "There are " << res << " paths from Little Red Riding Hood's house to her grandmother's house.\n";

        else if (res == 1)
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";

        else cout << "There is no path.\n";
    }
}
