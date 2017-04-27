#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	long long x;
	int DP[1001][1001], n, m;
	for (int i=0; i<1001; ++i)
		DP[i][0] = 1;

	while (cin >> n >> m && (n||m)) {
		for (int i=1; i<=n; ++i) {
			cin >> x; x %= m;
			for (int j=1; j<=i; ++j)
				DP[i][j] = (x * DP[i-1][j-1] + DP[i-1][j]) % m;
		}

		int mx = 0;
		for (int j=1; j<=n; ++j)
			mx = max(mx, DP[n][j]);

		cout << mx << '\n';
	}
}
