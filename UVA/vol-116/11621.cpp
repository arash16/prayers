#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<uint> v;
    uint maxi = 2147483648;
    for (uint i=0, x=1; i<32; ++i, x*=2)
        for (uint j=0, y=1; (long long)x*y<=maxi; ++j, y*=3)
            v.push_back(x*y);
    sort(v.begin(), v.end());

    int n;
    while (cin >> n && n)
        cout << (*lower_bound(v.begin(), v.end(), n)) << "\n";
}
