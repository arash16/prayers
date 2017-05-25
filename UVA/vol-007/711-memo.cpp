#include <bits/stdc++.h>
using namespace std;


int X[7], C[7],
    S[7][121000], cse;
bool D[7][121000];
bool dfs(int k, int rem) {
    if (!rem)
        return true;
    if (!k || rem < 0 || C[k] < rem)
        return false;

    if (S[k][rem] == cse)
        return D[k][rem];

    S[k][rem] = cse;
    for (int i=min(X[k], rem/k); i>=0; --i)
        if (dfs(k-1, rem - i*k))
            return D[k][rem] = true;

    return D[k][rem] = false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (cse=1; cin >> X[1]>>X[2]>>X[3]>>X[4]>>X[5]>>X[6]; ++cse) {
        for (int i=1; i<=6; ++i)
            C[i] = C[i-1] + i * X[i];
        if (!C[6]) break;

        cout << "Collection #" << cse << ":\n"
             << ((C[6]&1) || !dfs(6, C[6]>>1)
                 ? "Can't be divided.\n\n"
                 : "Can be divided.\n\n");
    }
}
