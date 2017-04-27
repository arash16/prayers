#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, m, x;
	for (int cse=1; cin >> n >> m && (n||m); ++cse) {
		int dif = n - m, mn = 100;
		while (n--) {
			cin >> x;
			mn = min(mn, x);
		}

		while (m--) cin >> x;

		cout << "Case " << cse << ": ";
		if (dif <= 0) cout << "0\n";
		else cout << dif << ' ' << mn << "\n";
	}
}
