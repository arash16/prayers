#include <bits/stdc++.h>
using namespace std;


bool lined(bool H[], int sz) {
    for (int i=0; i<sz; ++i)
        if (!H[i])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1, n,m; cin >> n >> m; ++cse) {
        if (cse > 1)
            cout << "\n**********************************\n\n";
        cout << "Problem #" << cse << "\n\n";

        bool H[9][9] = {},
             V[9][9] = {};

        for (int i, j; m--; ) {
            char ch;
            cin >> ch >> i >> j;
            (ch == 'H' ? H : V)[i-1][j-1] = true;
        }

        int C[10] = {};
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                int msz = n - max(i, j);
                for (int sz=1; sz<msz && H[i][j+sz-1] && V[j][i+sz-1]; ++sz)
                    if (lined(&H[i+sz][j], sz) && lined(&V[j+sz][i], sz))
                        C[sz] += 1;
            }

        bool some = false;
        for (int i=1; i<n; ++i)
            if (C[i]) {
                cout << C[i] << " square (s) of size " << i << '\n';
                some = true;
            }
        if (!some)
            cout << "No completed squares can be found.\n";
    }
}
