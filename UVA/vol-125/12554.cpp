#include <bits/stdc++.h>
using namespace std;


char msg[16][30] = {
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "you",
    "Happy", "birthday", "to", "Rujia",
    "Happy", "birthday", "to", "you",
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    string names[200];
    for (int i=0; i<n; ++i)
        cin >> names[i];

    int sz = ceil(n/16.0) * 16;
    for (int i=0; i<sz; ++i)
        cout << names[i%n] << ": " << msg[i%16] << '\n';
}
