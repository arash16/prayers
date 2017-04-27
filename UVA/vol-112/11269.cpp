#include <bits/stdc++.h>
using namespace std;

struct Prob { int x, y; } P[43];
bool cmp1(Prob a, Prob b) { return a.x < b.x; }
bool cmp2(Prob a, Prob b) { return a.y > b.y; }

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int D[43], n;
	while (cin >> n) {
		for (int i=0; i<n; ++i)
			cin >> P[i].x;

		for (int i=0; i<n; ++i)
			cin >> P[i].y;

		int sz1=0, sz2=20;
		for (int i=0; i<n; ++i)
			if (P[i].x <= P[i].y)
				P[sz1++] = P[i];
			else
				P[sz2++] = P[i];

		sort(P, P+sz1, cmp1);
		sort(P+20, P+sz2, cmp2);
		for (int i=20; i<sz2; ++i)
			P[sz1++] = P[i];

		for (int i=1; i<n; ++i)
			P[i].x += P[i-1].x;

		D[0] = P[0].x + P[0].y;
		for (int i=1; i<n; ++i)
			D[i] = max(D[i-1], P[i].x) + P[i].y;

		cout << D[n-1] << "\n";
	}
}
