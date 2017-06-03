#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, p, l;
    string word;
    while (cin >> n >> p >> l) {
        cin >> word;
        int cl = 1, cc = word.length();
        for (int i=1; i<n; ++i) {
            cin >> word;
            cc += 1 + word.length();
            if (cc > l) {
                cc = word.length();
                ++cl;
            }
        }

        cout << (cl+p-1)/p << '\n';
    }
}
