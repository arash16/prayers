#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char S[143], op;
    int T, n, m, X[143];
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(S, 0, n+1);
        for (int i=0, l; i<m; ++i) {
            cin >> l; l<<=1;
            for (int j=0; j<l; ++j)
                cin >> X[j];

            cin >> op;
            if (op == '=')
                for (int j=0; j<l; ++j)
                    S[X[j]] = 3;

            else {
                l >>= 1;
                for (int j=0; j<l; ++j)
                    S[X[j]] |= op=='<' ? 1 : 2;

                for (int j=2*l-1; j>=l; --j)
                    S[X[j]] |= op=='>' ? 1 : 2;
            }
        }

        int res0=0, res1=0;
        for (int i=1; i<=n; ++i)
            if (S[i] != 3) {
                if (!S[i]) {
                    if (!res0)
                         res0 = i;
                    else res0 = -1;
                }
                else {
                    if (!res1)
                         res1 = i;
                    else res1 = -1;
                }
            }

        if (res0<=0 && res1<0) cout << "0\n";
        else if (res0<=0 && res1>=0) cout << res1 << "\n";
        else cout << res0 << "\n";
        if (T) cout << endl;
    }
}
