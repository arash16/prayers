#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char ch, cm[40];
    int T, n, m, a, b, X[20][20];
    cin>>T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> ch;
                X[i][j] = ch-'0';
            }

        cin >> m;
        int diff = 0;
        for (int i=0; i<m; ++i) {
            cin >> cm;
            switch (cm[0]) {
                case 'i': ++diff; break;
                case 'd': --diff; break;
                case 't':
                    for (int i=0; i<n; ++i)
                        for (int j=0; j<i; ++j)
                            swap(X[i][j], X[j][i]);
                    break;

                case 'r':
                    cin >> a >> b;
                    for (int j=0; j<n; ++j)
                        swap(X[a-1][j], X[b-1][j]);
                    break;

                case 'c':
                    cin >> a >> b;
                    for (int i=0; i<n; ++i)
                        swap(X[i][a-1], X[i][b-1]);
                    break;

            }
        }

        cout << "Case #" << cse << endl;
        if (diff < 0) diff = (diff%10)+10;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j)
                cout << (X[i][j]+diff)%10;
            cout << endl;
        }
        cout << endl;
    }
}
