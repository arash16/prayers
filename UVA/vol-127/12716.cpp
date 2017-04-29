#include <bits/stdc++.h>
using namespace std;

int D[30000005] = {};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, X[10001], mx=0;
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> X[i];
        mx = max(mx, X[i]);
    }

    for (int c=mx/3; c>0; --c) {
        int tc = c+c;
        for (int a = c+tc; a<=mx; a+=tc)
            if ( (a & c) == c )
                ++D[a];
    }

    for (int i=1; i<=mx; ++i)
        D[i] += D[i-1];

    for (int i=1; i<=T; ++i)
        cout << "Case " << i << ": " << D[X[i-1]] << "\n";
}
