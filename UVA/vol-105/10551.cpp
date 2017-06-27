#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int b;
    char ps[1024], ms[17], rs[17];
    while (cin >> b >> ps >> ms) {
        int m = 0;
        for (int i=0; ms[i]; ++i)
            m = m*b + ms[i] - '0';

        long long r = 0;
        for (int i=0; ps[i]; ++i)
            r = (r*b + ps[i] - '0') % m;

        char *rr = rs+17;
        *(--rr) = 0;
        if (!r) *(--rr) = '0';
        else while (r)
            *(--rr) = (r%b) + '0',
            r /= b;

        cout << rr << '\n';
    }
}
