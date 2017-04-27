#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
int D[MAXN], C[MAXN][15], L[15], U[15], n, m;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	while (cin>>n>>m) {
		string str;
		unordered_map<string, int> ids;
		for (int i=0; i<n; ++i) {
			int b, s, d;
			cin >> str >> b >> s >> d;
			ids[str] = i;
			D[i] = d;
			for (int j=1; j<=d; ++j)
				cin >> L[j] >> U[j];

			C[i][d] = s;
			for (int j=d-1; j>0; --j)
				C[i][j] = C[i][j+1] * (U[j+1] - L[j+1] + 1);
			C[i][0] = b;
			for (int j=1; j<=d; ++j)
				C[i][0] -= C[i][j]*L[j];
		}

		for (int i=0; i<m; ++i) {
			cin >> str;
			int id = ids[str],
				ad = C[id][0], ind;

			cout << str << '[';
			for (int i=1; i<= D[id]; ++i) {
				cin >> ind;
				ad += C[id][i] * ind;
				if (i > 1)	cout << ", ";
							cout << ind;
			}
			cout << "] = " << ad << endl;
		}
	}
}
