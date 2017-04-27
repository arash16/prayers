#include <bits/stdc++.h>
using namespace std;


bool F[1000][1000];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int w, h, n, x1, x2, y1, y2;
    while (cin>>w>>h>>n && (w || h || n)) {
        for (int i=0; i<h; ++i)
            memset(F[i], 0, w);

        int result = w*h;
        for (int i=0; i<n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);

            for (int x=x1-1; x<x2; ++x)
                for (int y=y1-1; y<y2; ++y)
                    if (!F[y][x]) {
                        F[y][x] = 1;
                        --result;
                    }
        }

        if (!result) puts("There is no empty spots.");
        else if (result==1) puts("There is one empty spot.");
        else printf("There are %d empty spots.\n", result);
    }
}
