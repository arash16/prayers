#include <bits/stdc++.h>
using namespace std;

int DP[313][313];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n, p, c, d;
	cin >> T;
	while (T--) {
		cin >> n >> p;
		memset(DP, 127, sizeof(DP));
		DP[0][0] = 0;
		while (n--) {
			cin >> c >> d;
			for (int i=p; i>=0; --i)
				for (int j=p; j>=0; --j) 
					if (DP[i][j] < 1000) {
						int cc=c, dd=d;
						for (int k=1; i+cc<=p && j+dd<=p; ++k, cc+=c, dd+=d)
							DP[i+cc][j+dd] = min(DP[i+cc][j+dd], DP[i][j]+k);
					}
		}

		int mn = 1000;
		for (int i=0; i<=p; ++i)
			for (int j=0; j<=p; ++j)
				if (i*i+j*j==p*p)
					mn = min(mn, DP[i][j]);
		if (mn == 1000)
			cout << "not possible\n";
		else
			cout << mn << endl;
	}
}
