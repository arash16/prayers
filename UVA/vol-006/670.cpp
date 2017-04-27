#include <bits/stdc++.h>
using namespace std;

int dist2(int x1, int y1, int x2, int y2) {
	x1 -= x2; 
	y1 -= y2;
	return x1*x1 + y1*y1;
}

vector<int> adj[143];
int XB[143], YB[143], XI[143], YI[143], matchL[143], matchR[143];
bool seen[143];
bool bpm(int u) {
	for (int v: adj[u])
		if (!seen[v]) {
			seen[v] = true;
			if (matchR[v]<0 || bpm(matchR[v])) {
				matchL[u] = v;
				matchR[v] = u;
				return true;
			}
		}
	return false;
}


char BUF[1000000];
int main() {
	cout.rdbuf()->pubsetbuf(BUF, 1000000);
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			cin >> XB[i] >> YB[i];
			adj[i].clear();
		}

		for (int j=0; j<m; ++j) {
			cin >> XI[j] >> YI[j];
			for (int i=1; i<n; ++i) {
				int di1 = dist2(XI[j], YI[j], XB[i], YB[i]),
					di2 = dist2(XI[j], YI[j], XB[i-1], YB[i-1]),
					d12 = dist2(XB[i], YB[i], XB[i-1], YB[i-1]);

				if (di1 + di2 + 2*sqrt(1.0*di1*di2) <= 4*d12)
					adj[i].push_back(j);
			}
		}

		memset(matchL, -1, sizeof(matchL));
		memset(matchR, -1, sizeof(matchR));

		int cnt = 0;
		for (int i=1; i<n; ++i) {
			memset(seen, 0, m);
			if (bpm(i)) ++cnt;
		}

		cout << cnt+n << "\n";

		cout << XB[0] << ' ' << YB[0];
		for (int i=1; i<n; ++i) {
			if (matchL[i] != -1)
				cout << ' ' << XI[matchL[i]] << ' ' << YI[matchL[i]];
			cout << ' ' << XB[i] << ' ' << YB[i];
		}
		cout << "\n";
		if (T) cout << "\n";
	}
}
