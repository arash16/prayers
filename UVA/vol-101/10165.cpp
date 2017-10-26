#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    while (cin >> n && n>0) {
        int s = 0;
        for (int i=0; i<n; ++i) {
        cin >> x;
        s ^= x;
    }
    cout << (s ? "Yes\n" : "No\n");
    }
}
