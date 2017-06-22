#include <bits/stdc++.h>
using namespace std;


int klen[10];
char keys[10][7] = {
    " ",
    ".,?\"", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<10; ++i)
        klen[i] = strlen(keys[i]);

    int X[143], T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> X[i];

        for (int i=0, c; i<n; ++i) {
            cin >> c; --c;
            cout << char(keys[X[i]][ c % klen[X[i]] ]);
        }
        cout << '\n';
    }
}
