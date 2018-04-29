#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    double pi = 3.1415926535897932384, d, v;
    while (cin >> d >> v && (d||v))
        cout << fixed << setprecision(3)
             << pow((pi*d*d*d - 6*v)/pi, 1.0/3) << endl;
}
