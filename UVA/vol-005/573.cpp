#include <stdio.h>
#include <iostream>
using namespace std;

int fun(int h, long double u, int d, long double f) {
	long double c = 0;

	for (int i = 1; 1; i++) {
		c += u;
		if (c > h) return i;

		c -= d;
		if (c < 0) return -i;

		u -= u < f ? u : f;
	}
}



int main() {
	int h, u, d, f, i;
	while ((cin >> h >> u >> d >> f) && h) {

		int res = fun(h, u, d, (u * f) / 100.0);

		if (res > 0)
			cout << "success on day " << res << endl;
		else
			cout << "failure on day " << -res << endl;
	}
}
