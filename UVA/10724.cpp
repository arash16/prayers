#include <bits/stdc++.h>
using namespace std;

int X[143], Y[143], n;
bool S[143][143];
double W[143][143];
int dist2(int i, int j) {
	int xx = X[i] - X[j],
		yy = Y[i] - Y[j];
	return xx*xx + yy*yy;
}

double C(int u, int v, double d) {
	double s = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<i; ++j)
			if (!S[i][j])
				s += W[i][j] - min(W[i][j], d + min(W[i][u] + W[v][j], W[i][v] + W[u][j]));
	return s;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int m;
	while (cin>>n>>m && (n||m)) {
		for (int i=0; i<n; ++i) {
			cin >> X[i] >> Y[i];
			for (int j=0; j<i; ++j) {
				W[i][j] = W[j][i] = 1e55;
				S[i][j] = S[j][i] = 0;
			}
			W[i][i] = S[i][i] = 0;
		}

		for (int i=0, u,v; i<m; ++i) {
			cin >> u >> v; --u;--v;
			if (!S[u][v]) {
				 S[u][v] = S[v][u] = 1;
				 W[u][v] = W[v][u] = sqrt((double)dist2(u, v));
			}
		}

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
			if (W[i][k] < 1e43)
				for (int j=0; j<n; ++j)
					W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

		int bi=-1,bj;
		double bs = 0, bd;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j) 
				if (!S[i][j]) {
					double	d = sqrt(double(dist2(i, j))),
							s = C(i, j, d);

					if (s>bs || (s==bs && d<bd)) {
						bs = s; bd = d;
						bi = i; bj = j;
					}
				}

		if (bi < 0) cout << "No road required\n";
		else cout << bi+1 << ' ' << bj+1 << endl;
	}
}
