#include <bits/stdc++.h>
using namespace std;

struct Box {
    int w, l;
    bool operator < (const Box &o) const { return l != o.l ? l > o.l : w < o.l; }
} B[1043];


int DP[1043][3003], M[1043][3003], n, cse;
int rec(int id, int r) {
    if (id>=n || r<=0) return 0;
    if (M[id][r]==cse) return DP[id][r];

    DP[id][r] = rec(id+1, r);
    if (r >= B[id].w)
        DP[id][r] = max(DP[id][r], rec(id+1, min(r-B[id].w, B[id].l))+1);

    M[id][r] = cse;
    return DP[id][r];
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (cse=1; cin >> n && n; ++cse) {
        for (int i=0; i<n; ++i)
            cin >> B[i].w >> B[i].l;

        int mx = 0;
        for (int i=0; i<n; ++i)
            if ( (mx = max(mx, rec(i+1, B[i].l)+1)) == n )
                break;

        cout << mx << "\n";
    }
}
