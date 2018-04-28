#include <bits/stdc++.h>
using namespace std;


bool intersect(int x1, int x2, int x3, int x4, int &x5, int &x6) {
    if (x1 >= x3) {
        swap(x1, x3);
        swap(x2, x4);
    }

    x5 = max(x1, x3);
    x6 = min(x2, x4);
    return x5 < x6;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, x1, x2, x3, x4, x5, x6,
           y1, y2, y3, y4, y5, y6;

    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2
            >> x3 >> y3 >> x4 >> y4;

        if (intersect(x1, x2, x3, x4, x5, x6) && intersect(y1, y2, y3, y4, y5, y6))
            printf("%d %d %d %d\n", x5, y5, x6, y6);
        else
            puts("No Overlap");
        if (n) puts("");
    }
}
