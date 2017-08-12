#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n) {
        int r = n>1 ? n : 0;
        for (int i=2; i*i<=n; ++i)
            if (n%i == 0) {
                while (n%i == 0) n/=i;
                r = (r / i) * (i-1);
            }
        if (n > 1)
            r = (r / n) * (n-1);
        cout << r << endl;
    }
}
