#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, x;
    cin >> T;
    while (T-- && cin >> n) {
        int d = log10(n) + 1,
            s = 0;

        for (x=n; x; x/=10)
            s += pow(x%10, d);

        cout << (s == n ? "Armstrong\n" : "Not Armstrong\n");
    }
}
