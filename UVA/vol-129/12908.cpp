#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int n; cin>>n && n; ) {
        int m = floor((sqrt(1 + 8*n)-1) / 2) + 1;
        cout << (m*(m+1)/2 - n) << ' ' << m << '\n';
    }
}
