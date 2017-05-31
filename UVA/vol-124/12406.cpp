#include <bits/stdc++.h>
#define INF 1152921504606846976LL
using namespace std;


long long int mn[23][23], mx[23][23];
void dfs(long long int num, int d) {
    if (d > 17) return;
    for (int i=0; i<18 && num % (1<<i) == 0; ++i) {
        mx[d][i] = max(mx[d][i], num);
        mn[d][i] = min(mn[d][i], num);
    }

    long long int n10 = num*10;
    dfs(n10+1, d+1);
    dfs(n10+2, d+1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0; i<19; ++i)
        for (int j=0; j<19; ++j)
            mn[i][j] = INF,
            mx[i][j] =-INF;

    dfs(0, 0);

    int T, p, q;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> p >> q;

        cout << "Case " << cse << ": ";
        if (mn[p][q] == INF) cout << "impossible\n";
        else {
            cout << mn[p][q];
            if (mn[p][q] != mx[p][q])
                cout << ' ' << mx[p][q];
            cout << '\n';
        }
    }
}
