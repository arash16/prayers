#include <bits/stdc++.h>
using namespace std;

const double DR = acos(-1)/180;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(0);

    string cm;
    int T, n, a;
    cin >> T;
    while (T-- && cin >> n) {
        int d=0;
        double x=0, y=0;
        while (n--) {
            int dir = 1;
            cin >> cm >> a;
            switch (cm[0]) {
                case 'l': d += a; break;
                case 'r': d -= a; break;
                case 'b': dir = -1;
                case 'f':
                    double r = d * DR;
                    x += dir * a * cos(r);
                    y += dir * a * sin(r);
            }
            d = d % 360;
            if (d < 360) d += 360;
        }
        cout << sqrt(x*x + y*y) << '\n';
    }
}
