#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int a, u, v;
    while (cin >> a >> u >> v) {
        int b = 0, c = 0,
            t = 0;

        while (c < a || c < b) {
            ++t;
            c = t * (t + 1) >> 1;
            a += u;
            b += v;
        }
        cout << t << endl;
    }
}
