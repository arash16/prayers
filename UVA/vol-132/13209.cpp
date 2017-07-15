#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T-- && cin >> n) {
        cout << "0.";
        int num = 10;
        bool seen[1000143] = {};
        while (!seen[num]) {
            seen[num] = 1;
            if (num < n) cout << '0';
            else {
                int t = num / n;
                num -= t * n;
                cout << t;
            }
            num *= 10;
        }
        cout << endl;
    }
}
