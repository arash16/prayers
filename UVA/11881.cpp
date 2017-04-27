#include <bits/stdc++.h>
using namespace std;

int CF[17], n;
double npv(double irr) {
	double result = CF[0];
	double den = 1;
	for (int i=1; i<n; ++i) {
		den *= 1 + irr;
		result += CF[i] / den;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin >> n && n++) {
		for (int i=0; i<n; ++i)
			cin >> CF[i];

		if (npv(0) == npv(1))
			cout << "Too many\n";

		else {
			double lo = -1, hi = 1e10;
			while (hi-lo > 1e-9) {
				double mid = (lo + hi) / 2;
				if (npv(mid) < 0)
					hi = mid;
				else
					lo = mid;
			}

			cout << fixed << setprecision(2) << lo << endl;
		}
	}
}
