#include <bits/stdc++.h>
using namespace std;

int snoob(int x) {
    if (!x) throw 1;
    int rightOne = x & -x,
        nextHigherOneBit = x + rightOne;
    return ((x ^ nextHigherOneBit)/rightOne) >> 2 | nextHigherOneBit;
}


int X[143], n, m,
    seen[1<<16], cse;
bool check(int bm) {
    ++cse;
    for (int i=0; i<m; ++i) {
        int xi = X[i] & bm;
        if (seen[xi] == cse)
            return 0;
        seen[xi] = cse;
    }
    return 1;
}

int solve() {
    int sz = 1 << n;
    for (int a=1; a<n; ++a)
        for (int b=(1<<a)-1; b<sz; b=snoob(b))
            if (check(b))
                return a;
    return n;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, b;
    cin >> T;
    while (T-- && cin >> n >> m) {
        for (int i=0; i<m; ++i) {
            X[i] = 0;
            for (int j=0; j<n; ++j) {
                cin >> b;
                X[i] = X[i]<<1|b;
            }
        }
        cout << (m<=1 ? 0 : solve()) << '\n';
    }
}
