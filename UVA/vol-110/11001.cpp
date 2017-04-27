#include <bits/stdc++.h>
using namespace std;

int v, v0;
long long tlen(int n) { return n*(v-n*v0); }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> v >> v0 && v0) {
        if (v <= v0) cout << "0\n";
        else {
            int n1 = ceil(v/(2.0*v0)),
                n2 = floor(v/(2.0*v0));
            long long
                t1 = tlen(n1),
                t2 = tlen(n2);

            if (n1!=n2 && t1==t2) cout << "0\n";
            else cout << (t1 > t2 ? n1 : n2) << endl;
        }
    }
}
