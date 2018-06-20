#include <bits/stdc++.h>
using namespace std;


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(8);

    long double l, f;
    while (cin >> l >> f && (l||f)) {
        long double
            v = sqrt(2.0*l*f),
            d = v*(v/(2*f)),
            x = 3600*v / (l + d);
        cout << v << ' ' << x << endl;
    }
}
