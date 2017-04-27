#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, a, b, c;
    cin >> T;
    while (T-- && cin>>a>>b>>c) {
        int mx = sqrt(c);
        for (int x=-mx; x<=mx; ++x)
            if (x && b % x == 0) {
                int mxy = x<0 ? 0 : mx;
                for (int y=x+1; y <= mxy; ++y)
                    if (y && b % y == 0) {
                        int z = a - x - y;
                        if (z>y && x*y*z == b && x*x+y*y+z*z==c) {
                            cout << x << ' ' << y << ' ' << z << '\n';
                            goto fin;
                        }
                    }
            }
        cout << "No solution.\n";
        fin:;
    }
}
