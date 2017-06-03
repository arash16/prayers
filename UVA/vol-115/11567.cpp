#include <bits/stdc++.h>
using namespace std;


int main() {
    unsigned int n;
    while (cin >> n) {
        int cnt = 0;
        for (; n; ++cnt)
            if (n&1)
                if (n>3 && n&2) ++n;
                else --n;
            else n >>= 1;
        cout << cnt << endl;
    }
}
