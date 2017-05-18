#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

bool lte(int x, int y) {
    while (x) {
        if (x > y || (x%10)>(y%10))
            return 0;
        x /= 10;
        y /= 10;
    }
    return 1;
}

int Ci[143], Cp[143], csz,
    S[1000143], DP[1000143], cse;
int rec(int rem) {
    if (!rem) return 0;
    if (rem<0 || rem > 1000143) {
        cout << "!ERROR\n";
        return 0;
    }
    if (S[rem] == cse) return DP[rem];

    int mn = INF;
    for (int i=0; i<csz; ++i)
        if (lte(Ci[i], rem))
            mn = min(mn, rec(rem-Ci[i]) + Cp[i]);

    S[rem] = cse;
    return DP[rem] = mn;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    for (cse=1; cin >> n && n; ++cse) {
        int id = pow(10, n-1); csz=0;
        for (int i=0; i<n; ++i) {
            cin >> Cp[csz];
            Ci[csz++] = id;
            id /= 10;
        }

        cin >> m;
        while (m--) {
            id = 0; bool f=1;
            for (int i=0, c; i<n; ++i) {
                cin >> c;
                id = id*10 + c;
                f &= c <= 9;
            }
            cin >> Cp[csz];
            if (f && id) Ci[csz++] = id;
        }

        cin >> m;
        while (m--) {
            id = 0;
            for (int i=0, c; i<n; ++i) {
                cin >> c;
                id = id*10 + c;
            }
            cout << rec(id) << endl;
        }
    }
}
