#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int X[143], n, x, bs;
	while (cin >> n >> x && (n||x)) {
		int sz = 0;
		for (int i=1, d, d1, d2; i<=n; ++i) {
			cin >> d1;
			cin.ignore(1,'.');
			cin >> d2;
			d = d1 * 100 + d2;
			if (i == x)
				 bs = d;
			else X[sz++] = d;
		}

		int r = 0;
		if (bs < 5000) {
			bool dp[10000] = {-1};
			int mx=10000-bs;
			for (int i=0; i<sz; ++i)
				for (int j=mx; j-X[i]>=0; --j)
					dp[j] |= dp[j-X[i]];

			for (int i=5001-bs; i<=mx; ++i)
				if (dp[i]) {
					r = i;
					break;
				}
		}

		cout << fixed << setprecision(2)
			<< round(10000.0 * bs / (bs + r))/100.0 << endl;
	}
}
