#include <bits/stdc++.h>
using namespace std;

long long	MH[] = {0, 100, 10000, 1000000, 1LL<<62},
			HP[] = {0, 2, 3, 5, 7};
long long price(long long cwh) {
	long long result = 0;
	for (int i=1; cwh>0; ++i) {
		long long h = min(MH[i]-MH[i-1], cwh);
		result += h * HP[i];
		cwh -= h;
	}
	return result;
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	long long a, b, t;
	while (cin >> a >> b && (a||b)) {
		long long lo = 0, hi = a+1;
		while (lo <= hi) {
			long long mid = (lo + hi) >> 1;
			if (price(mid) <= a)
				lo = mid + 1;
			else
				hi = mid - 1;
		}


		t = lo - 1; lo = 0; hi = t + 1;
		while (lo <= hi) {
			long long mid = (lo + hi) >> 1;
			if (price(t-mid)-price(mid) >= b)
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		cout << price(lo-1) << endl;
	}
}
