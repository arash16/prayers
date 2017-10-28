#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int V[10000], T, n;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case #" << cse << ": ";
        cin >> n;

        unsigned int r = (n + 0xAAAAAAAA) ^ 0xAAAAAAAA;
        int sz = 0;
        while (r) {
            V[sz++] = r&1;
            r >>= 1;
        }

        if (sz>0) {
            int i = sz-1;
            while (!V[i]) --i;
            while (i>=0) cout << V[i--];
        }
        else cout << 0;
        cout << '\n';
    }
}
