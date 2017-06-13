#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char str[7];
    int dx[] = { 1, 0, -1, 0 },
        dw[] = { 0, 1, 0, -1 }, n;
    while (cin >> n && n) {
        int x=1, y=0, z=0;
        for (int i=1; i<n; ++i) {
            cin >> str;
            if (str[1] != 'o') {
                int &w = str[1]=='y' ? y : z,
                     d = str[0]=='+' ? 1 : 3;
                for (int k=0; k<4; ++k)
                    if (x == dx[k] && w == dw[k]) {
                        x = dx[(k+d)&3];
                        w = dw[(k+d)&3];
                        break;
                    }
            }
        }

        cout << (x>0 || y>0 || z>0 ? '+' : '-')
             << (x ? 'x' : z ? 'z' : 'y')
             << endl;
    }
}
