#include <bits/stdc++.h>
using namespace std;

char tmp;
string line;
int DP[202], n, m, d, d1, d2;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> d1 >> tmp >> d2 >> m; ++cse) {
        cout << "Case " << cse << ":\n";

        int d = d1*100 + d2;
        for (int i=1; i<202; ++i)
            DP[i] = i * d;

        while (m--) {
            cin >> n >> d1 >> tmp >> d2;
            int d = d1*100 + d2;
            for (int i=n; i<202; ++i)
                DP[i] = min(DP[i], DP[i-n]+d);
        }

        for (int i=200; i>0; --i)
            DP[i] = min(DP[i], DP[i+1]);

        cin.ignore(100, '\n');
        getline(cin, line);
        for (int i=0, n=0; i<=line.length(); ++i)
            if (line[i] >= '0')
                n = n*10 + line[i]-'0';
            else {
                cout << "Buy " << n << " for $"
                     << fixed << setprecision(2) << (DP[n]/100.0)
                     << "\n";
                n = 0;
            }
    }
}
