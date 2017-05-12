#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, k, x;
    cin >> T;
    for (int cse=1; cse<=T && cin >> n >> k >> x; ++cse)
        cout << "Case " << cse << ": " << ( ((n*(n+1))>>1) - ((k*(2*x+k-1))>>1) ) << '\n';
}
