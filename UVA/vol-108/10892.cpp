#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while (cin >> n && n) {
        vector<int> v;
        int sq = sqrt(n);
        for (int i=1; i<=sq; ++i)
            if (n%i == 0)
                v.push_back(i),
                v.push_back(n/i);
        if (sq*sq == n)
            v.pop_back();

        int card = 0;
        for (int i=0, sz=v.size(); i<sz; ++i) {
            long long x = v[i];
            for (int j=0; j<=i; ++j)
                if (x*v[j]/__gcd(v[i],v[j]) == n)
                    ++card;
        }

        cout << n << ' ' << card << endl;
    }
}
