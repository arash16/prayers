#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        bool f = 1;
        for (int i=0, x; i<13; ++i) {
            cin >> x;
            f &= x > 0;
        }
        cout << "Set #" << cse << ": " << (f ? "Yes\n" : "No\n");
    }
}
