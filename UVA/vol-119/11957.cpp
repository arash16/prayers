#include <bits/stdc++.h>
using namespace std;

#define MODUL 1000007
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char s[143];
    bool B[143][143];
    int T, C[143][143], n;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        for (int i=n-1; i>=0; --i) {
            memset(C[i], 0, n*sizeof(int));
            cin >> s;
            for (int j=0; j<n; ++j) {
                if (s[j]=='W') C[i][j]=1;
                B[i][j] = s[j] == 'B';
            }
        }

        for (int i=0; i<n-1; ++i)
            for (int j=0, t; j<n; ++j)
                if ((t=C[i][j])) {
                    if (!B[i+1][j+1])
                        C[i+1][j+1] = (t + C[i+1][j+1]) % MODUL;
                    else if (!B[i+2][j+2])
                        C[i+2][j+2] = (t + C[i+2][j+2]) % MODUL;

                    if (!B[i+1][j-1])
                        C[i+1][j-1] = (t + C[i+1][j-1]) % MODUL;
                    else if (!B[i+2][j-2])
                        C[i+2][j-2] = (t + C[i+2][j-2]) % MODUL;
                }

        int sum = 0;
        for (int j=0; j<n; ++j)
            sum = (sum + C[n-1][j]) % MODUL;

        cout << "Case " << cse << ": " << sum << endl;
    }
}
