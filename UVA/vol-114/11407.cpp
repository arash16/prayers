#include <bits/stdc++.h>
using namespace std;

int DP[10143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0; i<10143; ++i)
        DP[i] = i;

    for (int i=2, u; (u=i*i)<10143; ++i)
        for (int j=0; j+u<10143; ++j)
            DP[j+u] = min(DP[j+u], DP[j]+1);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << DP[n] << "\n";
    }

}
