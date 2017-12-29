#include <bits/stdc++.h>
#define INF 1073741824
using namespace std;


int n = 0;
struct Turtle {
    int w, s;
    bool operator < (const Turtle& o) const {
        return s != o.s ? s < o.s : w < o.w;
    }
}
X[6000];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> X[n].w >> X[n].s)
        if (X[n].w <= X[n].s)
            ++n;

    sort(X, X+n);

    int dp[6000] = {}, c, lc=1;
    for (c=1; c<=n; ++c)
        dp[c] = INF;

    for (int i=0; i<n; ++i)
        for (int c=lc; c>0; --c)
            if (dp[c-1]+X[i].w <= X[i].s) {
                dp[c] = min(dp[c], dp[c-1]+X[i].w);
                lc = max(lc, 1+c);
            }

    for (c=n; c>=0; --c)
        if (dp[c] != INF)
            break;

    cout << c << endl;
}
