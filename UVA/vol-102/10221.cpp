#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(6);

    long double r, a;
    string u;
    while (cin >> r >> a >> u) {
        if (u[0] == 'm') a /= 60;
        a = fmod(a, 360);
        if (a > 180) a = 360 - a;
        a *= PI/180;
        r += 6440;
        cout << r*a << ' ' << 2*sqrt(r*r-pow(r*cos(a/2), 2)) << '\n';
    }
}
