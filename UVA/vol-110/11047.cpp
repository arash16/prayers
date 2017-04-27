#include <bits/stdc++.h>
using namespace std;

string names[143];
int D[143][143], P[143][143];
void printPath(int u, int v) {
	if (P[u][v] == u) {
		cout << names[u] << ' ';
		return;
	}
	printPath(u, P[u][v]);
	printPath(P[u][v], v);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	string s1, s2, emp;
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n;
		unordered_map<string, int> ids;
		for (int i=0; i<n; ++i) {
			cin >> names[i];
			ids[names[i]] = i;
		}

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				cin >> D[i][j];
				P[i][j] = i;
			}

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
			if (D[i][k]!=-1)
				for (int j=0; j<n; ++j)
				if (D[k][j]!=-1) {
					int d = D[i][k] + D[k][j];
					if (D[i][j]<0 || d < D[i][j]) {
						D[i][j] = d;
						P[i][j] = k;
					}
				}


		cin >> m;
		while (m--) {
			cin >> emp >> s1 >> s2;
			int u = ids[s1],
				v = ids[s2];
			if (D[u][v] == -1)
				cout << "Sorry Mr " << emp << " you can not go from " << s1 << " to " << s2 << endl;

			else {
				cout << "Mr " << emp << " to go from " << s1 << " to " << s2 << ", you will receive " << D[u][v] << " euros\n";
				cout << "Path:";
				printPath(u, v);
				cout << s2 << endl;
			}
		}
	}
}
