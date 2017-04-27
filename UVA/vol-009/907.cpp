#include <bits/stdc++.h>
using namespace std;

int X[616], n, k;
bool check(int mx) {
	int sum=0, cnt=1;
	for (int i=0; i<n; ++i) {
		if ((sum += X[i]) > mx) {
			sum = X[i];
			if (++cnt > k)
				return false;
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin >> n >> k) {
		++n; ++k;
		int lo=0, hi=0;
		for (int i=0; i<n; ++i) {
			cin >> X[i];
			if (X[i] > lo)
				lo = X[i];
			hi += X[i];
		}

		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (check(mid))
				hi = mid-1;
			else
				lo = mid+1;
		}
		cout << hi+1 << endl;
	}
}
