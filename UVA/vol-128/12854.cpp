#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    bool X[10];
    while (cin>>X[0]) {
        for (int i=1; i<10; ++i)
            cin >> X[i];

        for (int i=0; i<5; ++i)
            if (X[i] != !X[5+i]) {
                cout << "N\n";
                goto fin;
            }
        cout << "Y\n";
        fin:;
    }
}
