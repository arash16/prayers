#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, p, q;
    cin >> T;
    while (T-- && cin >> p >> q) {
        unsigned long long r = 0, b = 1;
        while (p > 2*q)
            r |= b,
            b<<= 1,
            --p;

        for (int i=1; ; b<<=1, ++i)
            if (i%3 != 2)
                if (!p) break;
                else r |= b, --p;
            else
                if (!q) break;
                else --q;

        cout << r << '\n';
    }
}
