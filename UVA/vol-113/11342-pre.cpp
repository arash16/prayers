#include <bits/stdc++.h>
using namespace std;

#define MAXN 50005
bool E[MAXN];
int X[MAXN], Y[MAXN], Z[MAXN];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0, x; (x=i*i)<MAXN; ++i)
        for (int j=i, y; x+(y=j*j)<MAXN; ++j)
            for (int k=j, z; x+y+(z=k*k)<MAXN; ++k) {
                int n = x+y+z;
                if (!E[n]) {
                    E[n] = 1;
                    X[n] = i;
                    Y[n] = j;
                    Z[n] = k;
                }
            }

    int T, n;
    cin >> T;
    while (T-- && cin>>n) {
        if (!E[n]) cout << "-1\n";
        else cout << X[n] << ' ' << Y[n] << ' ' << Z[n] << '\n';
    }
}
