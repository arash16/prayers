#include <bits/stdc++.h>
using namespace std;


int main() {
    unsigned int N, L, U, R, b, r;
    while (cin >> N >> L >> U) {
        R = 0;
        for (int i=31; i>=0; --i) {
            b = 1<<i;
            if (!(N&b) || (R<L && (L&b))) {
                r = R|b;
                if (r <= U)
                    R = r;
            }
        }
        cout << R << endl;
    }
}
