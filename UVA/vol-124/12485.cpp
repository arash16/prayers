#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[10143], n;
    while (cin >> n) {
        int sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
        }

        if (sum % n) cout << "-1\n";
        else {
            int avg = sum / n;
            sum = 0;
            for (int i=0; i<n; ++i)
                sum += abs(X[i]-avg);
            cout << (sum>>1)+1 << "\n";
        }
    }
}
