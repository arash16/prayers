#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(2);

    int a1,a2,b1,b2,c1,c2;
    while (cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 && (a1||b1||c1||a2||b2||c2))
        if (a1*b2 == a2*b1)
            cout << "No fixed point exists.\n";
        else {
            if (!b2) {
                swap(a1, a2);
                swap(b1, b2);
                swap(c1, c2);
            }

            double x;
            if (!b1) x = double(c1) / a1;
            else x = (double(c2)/b2-double(c1)/b1) /
                    (double(a2)/b2 - double(a1)/b1);
            double y = (c2 - a2*x)/b2;
            cout << "The fixed point is at " << x << ' ' << y << ".\n";
        }
}
