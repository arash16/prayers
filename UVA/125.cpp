#include <bits/stdc++.h>
using namespace std;

int M[143][143];
int main() {
	int m, u, v;
	for (int cse=0; cin >> m; ++cse) {
		int n = 0;
		for (int i=0; i<m; ++i) {
			cin >> u >> v;
			int nn = max(u, v) + 1;
			for (; n < nn; ++n)
				for (int j=0; j<=n; ++j)
					M[n][j]=M[j][n]=0;
			M[u][v] = 1;
		}

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
			if (M[i][k])
				for (int j=0; j<n; ++j)
				if (M[k][j])
					M[i][j] += M[i][k] * M[k][j];

		for (int k=0; k<n; ++k)
		if (M[k][k])
			for (int i=0; i<n; ++i)
			if (M[i][k])
				for (int j=0; j<n; ++j)
				if (M[k][j])
					M[i][j] = -1;


		cout << "matrix for city " << cse << endl;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (j) cout << ' ';
				cout << M[i][j];
			}
			cout << endl;
		}
	}
}
