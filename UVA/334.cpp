#include <bits/stdc++.h>
using namespace std;

int T[1000][1000], idcnt;
unordered_map<string, int> ids;
string names[1000];
int readId() {
	cin >> names[idcnt];
	auto r = ids.emplace(names[idcnt], idcnt);
	if (r.second) {
		++idcnt;
		for (int i=0; i<=idcnt; ++i)
			T[i][idcnt] = T[idcnt][i] = 0;
	}
	return r.first->second;
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n, m;
	for (int cse=1; cin >> n && n; ++cse) {
		ids.clear();
		T[0][0] = idcnt = 0;
		for (int i=0; i<n; ++i) {
			cin >> m;
			if (!m) continue;
			int u = readId();
			for (int j=1; j<m; ++j) {
				int v = readId();
				T[u][v] = 1;
				u = v;
			}
		}

		cin >> m;
		for (int i=0; i<m; ++i) {
			int u = readId(),
				v = readId();
			T[u][v] = 1;
		}

		for (int k=0; k<idcnt; ++k)
			for (int i=0; i<idcnt; ++i)
			if (i!=k && T[i][k])
				for (int j=0; j<idcnt; ++j)
				if (T[k][j])
					T[i][j] = 1;


		int cnt = 0, i1,j1,i2,j2;
		for (int i=0; i<idcnt; ++i)
			for (int j=0; j<i; ++j)
				if (!T[i][j] && !T[j][i]) {
					if (!cnt) i1=i, j1=j;
					else if (cnt==1) i2=i, j2=j;
					++cnt;
				}

		cout << "Case " << cse << ", ";
		if (!cnt) cout << "no concurrent events.\n";
		else {
			cout << cnt << " concurrent events:\n";
			cout << '(' << names[j1] << ',' << names[i1] << ") ";
			if (cnt > 1)
				cout << '(' << names[j2] << ',' << names[i2] << ") ";
			cout << endl;
		}
	}
}
