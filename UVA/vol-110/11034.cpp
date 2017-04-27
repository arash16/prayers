#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
int ql[MAXN], qr[MAXN];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T, n, l, cl;
    cin>>T;
    while (T--) {
        cin >> l >> n; l*=100;
        int lc=0, rc=0, lcc=0, rcc=0;
        for (int i=0; i<n; ++i) {
            char dir[20];
            cin >> cl >> dir;
            if (dir[0]=='l') {
                if (lc + cl > l) {
                    lc = 0;
                    ++lcc;
                }
                lc += cl;
            }
            else {
                if (rc + cl > l) {
                    rc = 0;
                    ++rcc;
                }
                rc += cl;
            }
        }
        if (lc) ++lcc;
        if (rc) ++rcc;

        if (lcc > rcc) cout << 2*lcc-1 << endl;
        else cout << 2*rcc << endl;
    }
}
