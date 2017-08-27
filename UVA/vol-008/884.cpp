#include <bits/stdc++.h>
using namespace std;


int factors(int n) {
    int sq = sqrt(n),
        cnt = 0;

    for (int i=2; i<=sq; ++i)
        if (n%i == 0) {
            while (n%i == 0) {
                n /= i;
                ++cnt;
            }
            sq = sqrt(n);
        }
    if (n > 1) ++cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int C[1000001] = {};
    for (int i=1; i<1000001; ++i)
        C[i] = C[i-1] + factors(i);

    int n;
    while (cin >> n)
        cout << C[n] << endl;
}
