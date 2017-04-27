#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T, X[10][10];
    cin >> T;
    while (T--) {
        for (int i=0; i<9; i+=2)
            for (int j=0; j<=i; j+=2)
                cin >> X[i][j];

        for (int j=1; j<8; j+=2)
            X[8][j] = (X[6][j-1] - X[8][j-1] - X[8][j+1])>>1;

        for (int i=7; i>=0; --i)
            for (int j=0; j<=i; ++j)
                X[i][j] = X[i+1][j] + X[i+1][j+1];

        for (int i=0; i<9; ++i) {
            cout << X[i][0];
            for (int j=1; j<=i; ++j)
                cout << ' ' << X[i][j];
            cout << endl;
        }
    }
}
