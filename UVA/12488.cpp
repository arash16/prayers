#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int X[43], Y[43], n;
	while (cin >> n) {
		for (int i=0; i<n; ++i)
			cin >> X[i];
		for (int j=0, y; j<n; ++j) {
			cin >> y;
			Y[y] = j;
		}
		
		int cnt = 0;
		for (int i=0; i<n; ++i)
			for (int j=1; j<n; ++j)
				if (Y[X[j-1]] > Y[X[j]])
					swap(X[j-1], X[j]),
					++cnt;
		cout << cnt << '\n';
	}
}
