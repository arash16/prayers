#include <bits/stdc++.h>
using namespace std;

int C[] = {1,5,10,25,50}, n;
long long DP[30143][5];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int j=0; j<5; ++j) DP[0][j] = 1;
    for (int i=0; i<30000; ++i)
        for (int j=0; j<5; ++j)
            for (int k=j; k<5; ++k)
                DP[i+C[j]][k] += DP[i][j];

    while (cin >> n)
        if (DP[n][4] == 1)
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        else
            cout << "There are " << DP[n][4] << " ways to produce " << n << " cents change.\n";
}
