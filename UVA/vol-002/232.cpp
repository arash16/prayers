#include <bits/stdc++.h>
using namespace std;


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r, c;
    for (int cse=1; cin >> r >> c; ++cse) {
        if (cse>1) cout << '\n';

        char M[12][12] = {};
        for (int i=1; i<=r; ++i) {
            cin >> &M[i][1];
            for (int j=1; j<=c; ++j)
                if (M[i][j] == '*')
                    M[i][j] = 0;
        }

        int id = 0;
        cout << "puzzle #" << cse << ":\nAcross\n";
        for (int i=1; i<=r; ++i)
            for (int j=1; j<=c; ++j) if(M[i][j]) {
                id += !M[i-1][j] || !M[i][j-1];
                if (!M[i][j-1])
                    cout << setw(3) << id << '.' << &M[i][j] << '\n';
            }

        id = 0;
        cout << "Down\n";
        for (int i=1; i<=r; ++i)
            for (int j=1; j<=c; ++j) if(M[i][j]) {
                id += !M[i-1][j] || !M[i][j-1];
                if (!M[i-1][j]) {
                    cout << setw(3) << id << '.';
                    for (int k=i; M[k][j]; ++k)
                        cout << M[k][j];
                    cout << '\n';
                }
            }
    }
}
