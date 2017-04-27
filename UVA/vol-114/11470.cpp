#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int M[20][20];
    for (int cse=1, n; cin >> n && n; ++cse) {
        cout << "Case " << cse << ":";

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin >> M[i][j];

        for (int i=0; i<=(n-1)>>1; ++i) {
            int sum = 0, e = n-i-1;

            if (i == e) sum = M[i][i];
            else
            for (int j=i; j<=e; ++j)
                sum += M[i][j] + M[e][j];

            for (int j=i+1; j<e; ++j)
                sum += M[j][i] + M[j][e];

            cout << " " << sum;
        }
        cout << endl;
    }
}
