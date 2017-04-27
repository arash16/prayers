#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int DP[30][30], P[30][30], n, m;
void print(int i, int j) {
    if (i==n && j==m) return;
    switch (P[i][j]) {
        case 'S':
            print(i+1, j+1);
            break;

        case 'C':
            print(i+1, j+1);
            cout << 'C' << s2[j] << setfill('0') << setw(2) << i+1;
            break;

        case 'I':
            print(i, j+1);
            cout << 'I' << s2[j] << setfill('0') << setw(2) << i+1;
            break;

        case 'D':
            print(i+1, j);
            cout << 'D' << s1[i] << setfill('0') << setw(2) << i+1;
            break;
    }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> s1 >> s2 && s1!="#") {
        n = s1.length();
        m = s2.length();

        for (int i=0; i<=n; ++i) {
            DP[i][m] = n-i;
            P[i][m] = 'D';
        }
        for (int j=0; j<=m; ++j) {
            DP[n][j] = m-j;
            P[n][j] = 'I';
        }

        for (int i=n-1; i>=0; --i)
            for (int j=m-1; j>=0; --j)
                if (s1[i] == s2[j]) {
                    DP[i][j] = DP[i+1][j+1];
                    P[i][j] = 'S';
                }
                else if (DP[i+1][j] < DP[i][j+1] && DP[i+1][j] < DP[i+1][j+1]) {
                    DP[i][j] = DP[i+1][j] + 1;
                    P[i][j] = 'D';
                }
                else if (DP[i+1][j+1] < DP[i][j+1]) {
                    DP[i][j] = DP[i+1][j+1] + 1;
                    P[i][j] = 'C';
                }
                else {
                    DP[i][j] = DP[i][j+1] + 1;
                    P[i][j] = 'I';
                }

        print(0, 0); cout << "E\n";
    }
}
