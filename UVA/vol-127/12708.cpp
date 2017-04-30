#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    long long n;
    while (T-- && cin >> n)
        cout << (n >> 1) << '\n';
}
