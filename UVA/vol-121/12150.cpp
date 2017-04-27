#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, id, y, X[2000];
    while (cin>>n && n) {
        memset(X, 0, sizeof(int)*n);
        bool def = 0;
        for (int i=0; i<n; ++i) {
            cin >> id >> y;
            if (i+y>=0 && i+y<n && !X[i+y])
                X[i+y] = id;
            else
                def = 1;
        }

        if (def) cout << "-1\n";
        else {
            cout << X[0];
            for (int i=1; i<n; ++i)
                cout << ' ' << X[i];
            cout << endl;
        }
    }
}
