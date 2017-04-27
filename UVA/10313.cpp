#include <bits/stdc++.h>
using namespace std;

long long DP[313][313];
long long sum(int p, int l, int r=300) {
	if (l > p) return 0;
	if (r > 300) r = 300;
	long long res = DP[p][r];
	if (l > 0) res -= DP[p][l-1];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	DP[0][0] = 1;
	for (int c=1; c<=300; ++c)
		for (int i=1; i<=300; ++i)
			for (int r=c; r<=300; ++r)
				DP[r][i] += DP[r-c][i-1];

	for (int r=0; r<=300; ++r)
		for (int i=1; i<=300; ++i)
			DP[r][i] += DP[r][i-1];

	char line[100];
	while (cin.getline(line, 100)) if (line[0]) {
		int p, l, r;
		switch (sscanf(line, "%d%d%d", &p, &l, &r)) {
			case 1: cout << DP[p][p] << "\n"; break;
			case 2: cout << sum(p, 0, l) << "\n"; break;
			case 3: cout << sum(p, l, r) << "\n";
		}
	}
}
