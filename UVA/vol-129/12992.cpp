#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    for (int cse=1; T-- && cin >> n; ++cse)
        cout << "Case #" << cse << ": " << 2*n-1 << '\n';
}
