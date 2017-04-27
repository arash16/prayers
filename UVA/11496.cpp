#include <bits/stdc++.h>
using namespace std;

int sgn(int x) { return x<0 ? -1 : !x ? 0 : 1; }
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, x, frst, lst, s;
	while (cin>>n && n) {
		cin >> frst >> lst;
		int dir = sgn(lst - frst),
			cnt = 0,
			d1 = dir;
		for (int i=2; i<n; ++i) {
			cin >> x;
			s = sgn(x - lst);
			if (s*dir < 0) ++cnt;
			dir = s;
			lst = x;
		}
		s = sgn(frst - lst);
		if (s*dir < 0) ++cnt;
		if (s*d1 < 0) ++cnt;

		cout << cnt << endl;
	}
}
