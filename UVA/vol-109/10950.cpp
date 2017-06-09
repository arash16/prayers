#include <bits/stdc++.h>
using namespace std;


int cnt, n;
char Ch[43], X[128][7], S[143], P[143];

void bt(int si, int di) {
    if (cnt == 100) return;
    if (!S[si]) {
        ++cnt;
        P[di] = 0;
        cout << P << '\n';
        return;
    }

    while (S[si] == '0') ++si;
    if (!S[si]) return;

    for (int i=0, j; i<n; ++i) {
        char *Y = X[Ch[i]];
        for (j=0; Y[j]; ++j)
            if (S[si+j] != Y[j])
                goto unmatch;

        P[di] = Ch[i];
        bt(si + j, di + 1);

        unmatch:;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n && n; ++cse) {
        cout << "Case #" << cse << '\n';

        for (int i=0, x; i<n; ++i) {
            cin >> Ch[i] >> x;
            sprintf(X[Ch[i]], "%d", x);
        }
        sort(Ch, Ch+n);

        cin >> S;
        cnt = 0;
        bt(0, 0);
        cout << '\n';
    }
}
